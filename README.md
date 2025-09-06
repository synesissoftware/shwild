# shwild <!-- omit in toc -->

![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=flat&logo=c%2B%2B&logoColor=white)
[![License](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
[![GitHub release](https://img.shields.io/github/v/release/synesissoftware/shwild.svg)](https://github.com/synesissoftware/shwild/releases/latest)
[![Last Commit](https://img.shields.io/github/last-commit/synesissoftware/shwild)](https://github.com/synesissoftware/shwild/commits/master)
[![CMake on multiple platforms](https://github.com/synesissoftware/shwild/actions/workflows/cmake-multi-platform.yml/badge.svg)](https://github.com/synesissoftware/shwild/actions/workflows/cmake-multi-platform.yml)

**SH**ell-compatible **WILD**cards


## Table of Contents <!-- omit in toc -->

- [Introduction](#introduction)
- [Installation](#installation)
- [Components](#components)
  - [C API / core library](#c-api--core-library)
  - [C++ API](#c-api)
- [Examples](#examples)
- [Project Information](#project-information)
  - [Where to get help](#where-to-get-help)
  - [Contribution guidelines](#contribution-guidelines)
  - [Dependencies](#dependencies)
  - [Related projects](#related-projects)
  - [License](#license)


## Introduction

**shwild** is a small, standalone library, implemented in C++ with a C and a C++ API, that provides shell-compatible wildcard matching.


## Installation

Detailed instructions - via **CMake**, via bundling, via custom makefile
parameters - are provided in the accompanying [INSTALL.md](./INSTALL.md)
file.


## Components

### C API / core library

The **shwild C API** comprises the following functions:
* `shwild_init()`;
* `shwild_uninit()`;
* `shwild_match()`;
* `shwild_match_s()`;
* `shwild_compile_pattern()`;
* `shwild_compile_pattern_s()`;
* `shwild_destroy_pattern()`;
* `shwild_match_pattern()`;
* `shwild_match_pattern_s()`;

and used as in the following simple example:

```C
#include <shwild/shwild.h>

. . .

int r = shwild_init();
if (r < 0) {
    . . . // report failure and exit
} else {
  shwild_handle_t hCompiledPattern;
  int r2 = shwild_compile_pattern("X[0-9]*", 0, &hCompiledPattern);
  if (r2 < 0) {
    . . . // report failure and exit
  } else {
    assert(0 == shwild_match_pattern(hCompiledPattern, "X0"));
    assert(0 == shwild_match_pattern(hCompiledPattern, "X8abc"));
    assert(0 != shwild_match_pattern(hCompiledPattern, "X"));
    assert(0 != shwild_match_pattern(hCompiledPattern, "Y0"));

    shwild_destroy_pattern(hCompiledPattern);
  }

  shwild_uninit();
}
```


### C++ API

The **shwild C++ API** is a simple wrapper over the **shwild C API**, with the following components:
* `shwild::Pattern`;
* `shwild::PatternException`;

and used as in the following simple example:

```cpp
#include <shwild/shwild.hpp>

. . .

shwild::Pattern pattern("X[0-9]*", 0);

assert( pattern.match("X0"));
assert( pattern.match("X8abc"));
assert(!pattern.match("X"));
assert(!pattern.match("Y0"));

```


## Examples

Examples are provided in the ```examples``` directory, along with a markdown description for each.


## Project Information

### Where to get help

[GitHub Page](https://github.com/synesissoftware/shwild "GitHub Page")


### Contribution guidelines

Defect reports, feature requests, and pull requests are welcome on https://github.com/synesissoftware/shwild.


### Dependencies

#### STLSoft (optional) <!-- omit in toc -->

The original (~2005) implementation used **STLSoft** for discrimination of compilers and for library support. For modern compilers with broad support for the latest language standards this is not necessary. Hence, if the preprocessor symbol `SHWILD_NO_STLSOFT` is specified then all dependencies on **STLSoft** are removed and basic **C++-14** features are used instead. (This is done in the **CMake** configuration provided - see [INSTALL.md](./INSTALL.md).)

If you _do_ need **STLSoft**, then version 1.10.6 or later is recommended. If you're using a _very_ old compiler you may wish to use STLSoft-1.9, for which version 1.9.136 is recommended. Further, the makefiles require definition of the environment variable `STLSOFT` that should be set to the root directory of a clone of **STLSoft**.

* [STLSoft 1.9](http://github.com/synesissoftware/STLSoft-1.9/)
* [STLSoft 1.10](http://github.com/synesissoftware/STLSoft-1.10/) (Recommended)


### Related projects

Projects in which **shwild** is used include:

* [**shwild.fnmatch**](https://github.com/synesissoftware/shwild.fnmatch)

Projects in which **shwild** is used for testing include:

* [**b64**](https://github.com/synesissoftware/b64)
* [**cstring**](https://github.com/synesissoftware/cstring)
* [**FastFormat**](https://github.com/synesissoftware/FastFormat)
* [**libpath**](https://github.com/synesissoftware/libpath)
* [**Pantheios**](https://github.com/synesissoftware/Pantheios)
* [**recls**](https://github.com/synesissoftware/recls)
* [**UNIXem**](https://github.com/synesissoftware/UNIXem)


### License

**shwild** is released under the 3-clause BSD license. See [LICENSE](./LICENSE) for details.


<!-- ########################### end of file ########################### -->

