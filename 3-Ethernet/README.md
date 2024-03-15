# Ethernet configuration on embedded linux

In this section, we will configure Ethernet on our embedded linux platform and will use SSH to connect from our host computer to the Zynq SoC.

Make sure that the device driver for the Ethernet is enabled for Xilinx devices:

`make linux-menuconfig -> Device Drivers ----> Network device support ----> Ethenet driver support ----> Xilinx devices`

To use SSH connection, we need to enable the **dropbear** package:

  `make menuconfig -> Target packages ----> Networking applications ----> dropbear`

  Make sure that the ethernet node is available in the device tree source (buildroot/output/build/arch/arm/boot/dts/zynq-7000.dtsi, zynq-zed.dts).

  Run 'make' in the buildroot directory and boot the zedboard from SD card.

  After login, you can use `ifconfig -a` command to see the ethernet network configs. Run this command to initialize your ethernet and set up the IP address:

  `ifconfig eth0 <IP_address> netmask <Subnet_Mask> up`

  replace the IP_address and Subnet_Mask with the proper values based on your system and ethernet connection.

  After this configuration, you can use SSH from your host to connect to the Zynq SoC Linux terminal or vice versa. In your embedded linux platform:

  `ssh <host_name>@<host_IP_address>`

One of the advantages of using Ethernet in embedded linux is that we can develop our application in the host machine and after the cross-compilation, we can send the executable file to the /bin/ directory of the embedded device by using the scp command and the Ethernet connection. Without ethernet, we need to manually copy the exeutable to the target directory in the host and then update the SD card before booting the system.
