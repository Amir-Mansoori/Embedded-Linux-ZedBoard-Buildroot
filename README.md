# Embedded-Linux-ZedBoard-Buildroot
Step-by-step instructions to bring up embedded Linux and develop applications on ZedBoard

For Embedded Linux development, we need 4 components:

- **Toolchain**
  
  A toolchain is a set of programming tools, including **_cross-compilers_**, linkers, and other utilities, that enable the development of software for a specific platform. Cross-compilation is a process where software is compiled on one architecture (host) to run on a different architecture (target).
  
- **Bootloader**

  The bootloader is a piece of software that initializes the system and loads the operating system into memory during the boot process. For ZedBoard, U-Boot is a commonly used bootloader. It is responsible for loading the Linux kernel and the initial filesystem into memory before handing over control to the operating system.
  
- **Linux kernel**

  The Linux kernel is the core of the operating system. It manages hardware resources, provides essential services, and acts as an intermediary between software applications in the userspace and hardware components.
  
- **Root File system**

  The root file system is the initial file system mounted during boot. It contains essential files and directories needed for the system to operate.

Although it is possible to install each component separately (manual embedded linux devlopment), there are several tools that are devloped to automate and simplify the process of building embedded linux systems. Among these systems, **Buildroot** and **Yocto Project** are the most commonly-used tools so far. 

**Buildroot** is the oldest tool that is introduced in 2001 for embedded linux development and is still being used in many embedded applications. It provides a framework for generating custom Linux distributions tailored for specific embedded platforms. Buildroot is less complex than Yocto, so it is a great starting point to learn about embedded linux development.

**Yocto Project** also provides tools and resources for building custom Linux-based systems for embedded devices. It aims to streamline the development process and ensure consistency across a wide range of embedded platforms. Yocto provides a layering structure that makes it easier to scale and enables better organization and management of project configurations, dependencies, and customizations. Layers can be added or removed to tailor the build to specific project needs. However, it makes the devlepment process more complex.

In this repository, you will find step-by-step instructions on how to configure and bring up linux on embedded devices using buildroot and develop applications on your device. We use ZedBoard as an example, but you can test and evaluate the instructions and examples on your own board.
