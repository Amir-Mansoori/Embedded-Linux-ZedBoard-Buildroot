# Bitstream Addition

In this section, we will create a simple Vivado project by adding a VHDL IP in PL that implements only a wire. It has one input that is connected to a switch on the board and one output that is connected to an LED. The switch can toggle the LED ON or OFF through the PL. There is no need to use the PS, but we must instantiate the Zynq PS in the block diagram with the default configurations in order to create the FSBL file in the next step. Our purpose is to write the FPGA bitstream and bring up Linux during the booting phase.

The block diagram in Vivado is shown bellow:

<img align="center" src="https://github.com/Amir-Mansoori/Embedded-Linux-ZedBoard-Buildroot/blob/main/Images/Vivado_wire.png" width="700" height="500">


Make sure that in the constraint file (physical.xdc), you have uncommented the lines related to the switch (SW0) and the LED (LD0). After the synthesis, implementation, and generating the bitstream, export the hardware and make sure the the "include the bitstream" option is checked before the export. Then lauch the Vitis IDE (or Launch SDK).

## Creating the BOOT image

In this step, we need to create a BOOT.bin file that includes the following:

- First Stage Boot Loader (**FSBL**) from Vivado as the **bootloader**
- **Bitstream** from Vivado as a **datafile**
- Second Stage Boot Loader (**SSBL**) from the Buildroot (**u-boot.elf**) as a **datafile**

Go to `Vitis (SDK) ---> Create BOOT Image ---> Zynq and Zynq Ultrascale`

Select the output path and add the 3 above-mentioned files to the Boot image partitions. Then click on Create Image.

### Important Note 
If after the booting, the hardware is not properly configured, most probably it is related to the FSBL file. **Try to create an empty project with only a Zynq PS and then use the generated FSBL file from this Zynq-PS-only project**

## Replacing Boot image from Buildroot
The files that were written to the SD card in previous sections (for example in [0-linux-bring-up](https://github.com/Amir-Mansoori/Embedded-Linux-ZedBoard-Buildroot/tree/main/0-linux-bring-up#embedded-linux-on-zedboard)), contains a **boot.bin** file. You must replace this file with the newly created **BOOT.BIN** file from the previous sub-section ([Creating the BOOT image](https://github.com/Amir-Mansoori/Embedded-Linux-ZedBoard-Buildroot/edit/main/4-Bitstream-addition/README.md#creating-the-boot-image)).

After the replacement, insert the SD card in the board. The booting process for Zynq devices will start as indicated in the following image:

<img src="https://github.com/Amir-Mansoori/Embedded-Linux-ZedBoard-Buildroot/blob/main/Images/Bootflow.png" width="700" height="500">

After powering on, you will see that the zynq FSBL will load the bitstream on the FPGA and then the u-boot (SSBL) will load the Linux kernel. You can test the design by turning ON the switch and see the LED status.
