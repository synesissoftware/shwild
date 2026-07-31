# shwild - Installation and Use <!-- omit in toc -->

**shwild** is a classic-form C/C++ library, insofar as it has
implementation files in its **src** directory and header files in its
**include/shwild** directory. Thus, once "installed", one must simply
include **shwild/shwild.h** (or one of the utility headers), and compile-in
or link-in the implementation. There are several ways to do this:


## Table of Contents <!-- omit in toc -->

- [CMake](#cmake)



## CMake

The primary choice for installation is by use of **CMake**.

1. Obtain the latest distribution of **shwild**, from
   https://github.com/synesissoftware/shwild/, e.g.

   ```bash
   $ mkdir -p ~/open-source
   $ cd ~/open-source
   $ git clone https://github.com/synesissoftware/shwild/
   ```

2. Prepare the CMake configuration, via the **prepare_cmake.sh** script, as
   in:

   ```bash
   $ cd ~/open-source/shwild
   $ ./prepare_cmake.sh -v
   ```

3. Run a build of the generated **CMake**-derived build files via the
   **build_cmake.sh** script, as in:

   ```bash
   $ ./build_cmake.sh
   ```

   (**NOTE**: if you provide the flag `--run-make` (=== `-m`) in step 3 then you do
   not need this step.)

4. As a check, execute the built test program files via the
   **build_run_all_unit_tests.sh** script, as in:

   ```bash
   $ ./run_all_unit_tests.sh
   ```

5. Install the library on the host, via `cmake`, as in:


   ```bash
   $ sudo cmake --install ${SIS_CMAKE_BUILD_DIR:-./_build} --config Release
   ```

7. Then to use the library, it is a simple matter as follows:

   1. Assuming a simplest possible program to verify the installation:

      ```cpp
      // main.cpp
      #include <shwild/shwild.h>
      #include <stdio.h>
      #include <stdlib.h>

      int main(int argc, char* argv[])
      {
        shwild_init();

        printf("using shwild (minimally)\n");

        return EXIT_SUCCESS;
      }
      ```

   2. Compile your project against **shwild**:

      Due to the installation step (Step 6 above) there is no requirement
      for an explicit include directory for **shwild**:

      ```bash
      $ g++ -c -std=c++11 main.cpp
      ```

   3. Link your project against **shwild**:

      Due to the installation step (Step 6 above) there is no requirement
      for an explicit library directory for **shwild**:

      ```bash
      $ g++ main.o -lshwild
      ```

   4. Test your project:

      Then you can run, as in:

      ```bash
      $ ./a.out
      using shwild (minimally)
      $
      ```



<!-- ########################### end of file ########################### -->

