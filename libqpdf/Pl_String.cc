#include <qpdf/Pl_String.hh>

#include <stdexcept>

Pl_String::Members::Members(std::string& s) :
    s(s)
{
}

Pl_String::Pl_String(char const* identifier, Pipeline* next, std::string& s) :
    Pipeline(identifier, next),
    m(new Members(s))
{
}

Pl_String::~Pl_String() // NOLINT (modernize-use-equals-default)
{
    // Must be explicit and not inline -- see QPDF_DLL_CLASS in README-maintainer
}

void
Pl_String::write(unsigned char const* buf, size_t len)
{
    if (!len) {
        return;
    }
    m->s.append(reinterpret_cast<char const*>(buf), len);
    if (next()) {
        next()->write(buf, len);
    }
}

void
Pl_String::finish()
{
    if (next()) {
        next()->finish();
    }
}
