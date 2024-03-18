# Bitstream Addition

In this section, we will create a simple Vivado project by adding a VHDL IP in PL that implements only a wire. It has one input that is connected to a switch on the board and 
and one output that is connected to an LED. The switch can toggle the LED ON or OFF through the PL. There is no need to use the PS, we just want to write the FPGA bitstream and bring up Linux during the booting phase.

The block diagram in Vivado is shown bellow:

![Vivado wire block diagram](https://github.com/Amir-Mansoori/Embedded-Linux-ZedBoard-Buildroot/blob/main/Images/Vivado_wire.png)

We use the default configs for the Zynq PS. 
