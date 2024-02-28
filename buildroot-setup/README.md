The first step is to setup Buildroot. you can follow the instructions in [Buildroot website](https://buildroot.org/) and clone the repository:

`git clone https://gitlab.com/buildroot.org/buildroot.git`

Once you cloned the repository, you will have all the contents in the _buildroot_ directory. Go to the configs directory to see a list of default configurations for a set of hardware architectures:

`ls buildroot/configs/`

You will find the default configurations for the ZedBoard in here: _zynq_zed_defconfig_. Do the following steps to create a .config file from the ZedBoard default configs:

`cd buildroot/`

`make zynq_zed_defconfig`

This will create a .config file in your buildroot directory that contains the default configurations for the ZedBoard. From the buildroot directory, run the following command:

`make menuconfig`

This command reads the generated .config file for the ZedBoard and opens a graphical interface where you can customize the build configurations for your embedded linux application. The graphical interface is something like this:

