# NAND function with PL and PS

In this section we want to use both PL and PS in our design. 

The standalone version of this design is provided in this [Youtube video](https://www.youtube.com/watch?v=_odNhKOZjEo&list=PLvZ6Lqw37k_EqcWXARuVN2ijjnxvW2P3Z&index=3). We will implement the same design in embedded linux.

In the PL, we create an AND gate using a VHDL IP. The two inputs of the AND gate are connected directly to two switches in our ZedBoard (SW0 and SW1). The output of the AND gate is connected to PS through an AXI-GPIO IP (axi_gpio_0). Inside the PS, we implement a NOT logic, so at the end our design will implement a NAND gate (AND in PL + NOT in PS). The output of the PS is connected to an LED (LD0) through a second AXI-GPIO IP (axi_gpio_1). The purpose of using the AXI-GPIO IPs is to be able to communicate between the PL and PS. The PS controls the PL through the AXI-GPIO IPs. The block diagram of our design is shown bellow:

![Vivado NAND block diagram](https://github.com/Amir-Mansoori/Embedded-Linux-ZedBoard-Buildroot/blob/main/Images/Vivado_NAND.png)

After generating the bitstream in Vivado, The next steps in Buildroot are:

1. Enable Xilinx GPIO drivers in the kernel:
   - `make linux-menuconfig ---> Device Drivers ---> GPIO Support ---> Memory mapped GPIO drivers ----> Xilinx GPIO support and Xilinx Zynq GPIO support`
2. Modify the Device Tree Source (DTS) files to add axi_gpio_0 and axi_gpio_1 (Refer to [Device Tree]() section):
   - DTS files are located in `buildroot/output/build/linux-custom/arch/arm/boot/dts/`
   - The names of the DTS files in this directory are: `zynq-7000.dtsi` and `zynq-zed.dts`
   - Modify these two files according to the provided files in this repository with the same names
3. Write the C code application (`nand_gate.c`) to:
   - configure the inputs and outputs of AXI GPIO IPs
   - implement the NOT logic
4. Rebuild the SSBL (u-boot) and Linux Kernel:
   - `make uboot-rebuild`
   - `make linux-rebuild`
   - Note: if you receive warnings regarding some missing files (\*file_list\*), you can just create some empty files with those names before running the previous two commands (refer to `mkrebuild` script).
5. Cross-compile your C code application (skip this step if you are using Ethernet to transfer the executable file with scp to /bin directory).
6. Update the Linux image files (root file system, dts, ...):
   - `make`

Finally, in Vivado:

7. Create the BOOT image and replace the boot.bin from Buildroot based on section ([4-Bitstream-addition](https://github.com/Amir-Mansoori/Embedded-Linux-ZedBoard-Buildroot/tree/main/4-Bitstream-addition#creating-the-boot-image))
8. Insert the SD card, login to your linux terminal, and run your application. You will see the NAND gate is implemented using the two switches and the LED.
