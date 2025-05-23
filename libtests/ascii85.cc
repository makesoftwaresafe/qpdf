#include <qpdf/Pl_ASCII85Decoder.hh>

#include <qpdf/Pl_StdioFile.hh>
#include <cstdlib>
#include <iostream>

int
main()
{
    Pl_StdioFile out("stdout", stdout);
    Pl_ASCII85Decoder decode("decode", &out);

    try {
        unsigned char buf[10000];
        bool done = false;
        while (!done) {
            size_t len = fread(buf, 1, sizeof(buf), stdin);
            if (len <= 0) {
                done = true;
            } else {
                decode.write(buf, len);
            }
        }
        decode.finish();
    } catch (std::exception& e) {
        std::cerr << e.what() << '\n';
        exit(2);
    }

    return 0;
}
