# shwild
**SH**ell-compatible **WILD**cards is a small, standalone library, implemented in C++ with a C and a C++ API, that provides shell-compatible wildcard matching.

## Table of Contents

1. [Introduction](#introduction)
2. [Installation](#installation)
3. [Components](#components)
4. [Examples](#examples)
5. [Project Information](#project-information)

## Introduction

**SH**ell-compatible **WILD**cards is a small, standalone library, implemented in C++ with a C and a C++ API, that provides shell-compatible wildcard matching.

## Installation

The original (~2005) implementation used **STLSoft**, for discrimination of compilers are library support. However, if the preprocessor symbol `SHWILD_NO_STLSOFT` is specified, then all dependencies on **STLSoft** are removed and basic **C++-11** features are used instead.

If **STLSoft** is to be used, then the makefiles require definition of the environment variable `STLSOFT` that should be set to the root directory of a clone of **STLSoft** (see [Dependencies](#dependencies) in this document).

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

#### STLSoft (C++ API-only)

The C++ API depends on the STLSoft libraries, version 1.9.134 (or later). Version 1.10.1 beta19 (or later) is recommended.

* [STLSoft 1.9](http://github.com/synesissoftware/STLSoft-1.9/)
* [STLSoft 1.10](http://github.com/synesissoftware/STLSoft-1.10/) (Recommended)

### Related projects

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

