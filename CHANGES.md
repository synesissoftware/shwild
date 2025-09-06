#  **shwild** Changes


## 6th September 2025 - 0.12.8

* badges;
* added **run_all_unit_tests.cmd**;
* CMake helper scripts now define default make command as "mingw32-make.xe" if recognise MinGW;
* \*.sh : ~ moved info-lines into ./.sis/script_info_lines.txt;
* README;
* settings;
* .gitattributes;


## 30th August 2025 - 0.12.7

* GitHub Actions;
* CTest compatibility;
* updated **BDUT** to 0.4.0;
* removed Visual Studio project/solution/workspace files;
* refactoring CMake support files;
* ignores;


## 15th May 2025 - 0.12.6

* Fixing (_very_ old) offset defect that manifests when building without STLSoft;
* Now defines `SHWILD_VER_PATCH` and adjusted **CMakeLists.txt**;
* Added **libver** scratch test;
* Updated **BDUT** to 0.3.2;


## 6th May 2025 - 0.12.5

* Miscellaneous minor CMake driver script improvements;
* updated **BDUT** to 0.3.2-rc1;


## 3rd May 2025 - 0.12.4

* Compatibility with older compilers (incl. Visual C++ 14);
* Compatibility with older operating systems (incl. Windows Vista);


## 0.12.4 (alpha 1) - 3rd May 2025

* CMake MSVC warning fix;


## 0.12.3 - 18th November 2024

* added CMake MSVC MT support;
* CMake MSVC fix;


## 0.12.3 (alpha 1) - 18th November 2024

* fixed dependency on STLSoft;
* updated **BDUT** to 0.3.1;


## 0.12.2 - 18th October 2024

* MinGW compatility;
* Significant enhancement of use of CMake;


## 0.12.1 - 13th July 2024

* Fully optional compatibility with STLSoft
* CMake project renamed to `shwild::core`
* Various CMake standardisations and simplifications
* Compatibility with Visual C++ 17


## 0.11.8 - 10th July 2024

* Boilerplate files improvements
* Moved bundled **BDUT** header(s) into separate directory


## 0.11.8 - 10th July 2024

* Boilerplate files improvements


## 0.11.7 - 12th May 2024

* Visual C++ 17 compatibility
* **CMake** Windows compatibility


## 0.11.6 - 28th January 2024

* **CMake** support minor improvements
* improved project boilerplate, in particular **INSTALL.md**
* all UNIX custom makefiles updated for `SHWILD_NO_STLSOFT`


## 0.11.5 - 11th January 2024

* **CMake** support
* added project boilerplate files **AUTHORS.md**, **FAQ.md**, **HISTORY.md**, **TODO.md**
* internal **Brain-Dead Testing** replaced with (in fact moved to) [**BDUT**](https://github.com/synesissoftware/BDUT)


## 0.11.4 - 21st December 2023

* added `SHWILD_NO_STLSOFT` support, which means **b64** can now be built without reliance on **STLSoft**
* **Doxygen** support
* added **Clang** 13.0 makefile
* added **GCC** std-c++ makefile
* added new example **example.c.1**
* added new example **example.cpp.2**
* improved **Brain-Dead Testing**
* miscellaneous tidying and consistency with other Synesis open-source projects
* miscellaneous improvements to project boilerplate


## 0.11.3 - 18th July 2020

* GCC compatibility


## 0.11.2 - 18th July 2020

* fixed makefiles whitespace


## 0.11.1 - 18th July 2020

* added **Brain-Dead Testing** internal unit-testing
* removed dependency on **Open-RJ** project
* removed dependency on **xCover** project
* removed dependency on **xTests** project
* added support for Visual C++ 15 & 16
* added VC++ 10 solution file and projects files
* added GCC 4.8 makefile
* added GCC 8.1 (Windows) makefile
* fixed up copyright information
* moved examples and tests around


## 0.10.3 - 12th July 2016

* Initial version on GitHub


## 0.10.1 - 11th February 2009

* added implicit link files for test programs
* centralised discrimination of **STLSoft** dependency handling in common internal header file
* added code coverage
* moved core project files to projects/core/xxx, where xxx is the compiler-specific directory, e.g. vc6 for Visual C++ 6


All history before this day is moot!


<!-- ########################### end of file ########################### -->

