[![Build Status](https://travis-ci.org/jfcameron/jfc-application_paths.svg?branch=master)](https://travis-ci.org/jfcameron/jfc-application_paths)[![Documentation](https://img.shields.io/badge/documentation-doxygen-blue.svg)](https://jfcameron.github.io/jfc-application_paths/)

## jfc-application_paths

Creates and provides paths to directories to read write data for a single specific application in a crossplatform way.
Follows freedesktop layout for POSIX, creates a subdirectory in appdata for windows.

### usage
1: add the `include` directory on the root of this repository to your include paths. 2: define #JFC_APPLICATION_PATHS_IMPLEMENTATIONbefore you include the header.

