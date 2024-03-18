# Blinking LED

In this section, we want to toggle an LED on our ZedBoard for 10 times every 1 second.

The LED that we use is connected to the PS MIO7. In ZedBoard, there are 54 MIO pins and 64 EMIO pins (extended to PL), so in total there are 118 pins.

To interact with our LED in the embedded linux platform from the userspace, we can either use the [Sysfs GPIO interface](https://www.kernel.org/doc/Documentation/gpio/sysfs.txt), or we can use a higher level userspace library (libgpiod).
We use libgpiod library which can be enabled in the kernel configurations using the `make menuconfig`:

`Target Packages ----> Libraries ----> Hardware handling ----> libgpiod` (press Y to enable).

Also make sure that Zynq GPIO driver is enabled:

`make uboot-menuconfig -> Device Drivers ----> GPIO support ----> Zynq GPIO`

`make linux-menuconfig -> Device Drivers ----> GPIO support ----> Memory mapped GPIO drivers ----> Xilinx Zynq GPIO support`

After saving this configuration, run the `make` command again to rebuild the root file system and all the required images in the output/images directory.

The next step is to make sure that our Device Tree Source (DTS) file includes the zynq GPIO node For more information about Device Trees follow this section.
The DTS files are available in this directory: `buildroot/output/build/linux-custom/arch/arm/boot/dts/`.
There are two files that are related to our ZedBoard: `zynq-7000.dtsi` and `zynq-zed.dts`.
The dtsi (dts include) file is the source file that is _included_ in the dts file. The nodes are usually defined in dtsi file and additional features can be added in the dts file.
For the default configurations of the ZedBoard, the GPIO node is already enabled in the device tree source files. This can be verified by checking the `/dev/` directory after booting.
A device file must be created in this directory (/dev/) that is related to the GPIO controller and the name of this file is usually gpiochip0 (if there is no other gpio controllers). Note that for the LED that is connected to PS in the ZedBoard, the GPIO line offset is 7 because it is connected to MIO7.

The final step is to cross-compile our C code (led_blink.c) by using the Makefile that is provided. Follow the same steps that are explained in the [hello-world section](https://github.com/Amir-Mansoori/Embedded-Linux-ZedBoard-Buildroot/tree/main/1-hello-world#hello-world).

After booting, make sure that led executable is availabe in /bin/ directory. Then run `led` to run the LED blinking application. The LED on our board must be toggled every one second for 10 times.
