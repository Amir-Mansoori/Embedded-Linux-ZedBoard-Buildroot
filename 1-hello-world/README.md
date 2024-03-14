# Hello World

We can run a simple hello world example on our Zedboard using the embedded linux platform.

In addition to our application C code (hello.c), we need a Makefile to use for our cross-compilation toolchain.

The provided Makefile assumes that the directory in which the Buildroot is cloned is located in the user's home directory (~/).

These are the steps to run the first Hello World example on your Zedboard:

1. `source setup_cc.sh` This will setup the environment for your cross compilation tool
2. In the current directory of the hello world example run the following commands:
    - `make`
    - `make install`
3. In the Buildroot directory, run `make` to rebuild the kernel image files
4. Copy the generated sdcard.img to the SD card and boot the Zedboard from SD (see [linux-bring-up](https://github.com/Amir-Mansoori/Embedded-Linux-ZedBoard-Buildroot/tree/main/0-linux-bring-up#embedded-linux-on-zedboard)).
  
