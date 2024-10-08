# Using the qpdf AppImage bundle (for Linux x86_64 systems only)

Tips:

* After downloading, you have to set the executable bit for any AppImage (for security reasons this is disabled by
  default): `chmod +x <name-of-application>.AppImage`

* Run the qpdf AppImage with the `--ai-usage` parameter to start learning some useful details about built-in features of
  this specific AppImage.

* You can rename the AppImage to any name allowed for file names on Linux. The `.AppImage` suffix is not required for it
  to function. It will also work as expected if you invoke it from a symlink. Using `qpdf` as its filename or symlink
  name is OK. However, you may want to continue using the qpdf package provided by your system's package manager side by
  side with the AppImage bundle: in this case it is recommended to use `qpdf.ai` as a short name for (or as the symlink
  name to) the qpdf-<version>.AppImage.
