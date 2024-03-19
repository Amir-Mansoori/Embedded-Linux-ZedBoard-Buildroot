#include <stdio.h>
#include <gpiod.h>
#include <unistd.h>
int main() {
    const char *chipname1 = "/dev/gpiochip0"; // Path to your GPIO character device
    const unsigned int line_offset1 = 0;// GPIO line offset1
    const char *chipname2 = "/dev/gpiochip1"; // Path to your GPIO character device
    const unsigned int line_offset2 = 0;// GPIO line offset2

    struct gpiod_chip *chip1;
    struct gpiod_chip *chip2;
    struct gpiod_line *line1;
    struct gpiod_line *line2;
    struct gpiod_line_request_config config1 = {
        .consumer = "not_gate_in",
        .request_type = GPIOD_LINE_REQUEST_DIRECTION_INPUT,
    };

    struct gpiod_line_request_config config2 = {
        .consumer = "not_gate_out",
        .request_type = GPIOD_LINE_REQUEST_DIRECTION_OUTPUT,
    };
 
    int req, val, not_val;

    // Open the GPIO character device
    chip1 = gpiod_chip_open(chipname1);
    if (!chip1) {
        perror("Error opening GPIO chip1");
        return 1;
    }

    chip2 = gpiod_chip_open(chipname2);
    if (!chip2) {
        perror("Error opening GPIO chip2");
        return 1;
    }


    // Get the GPIO line
    line1 = gpiod_chip_get_line(chip1, line_offset1);
    if (!line1) {
        perror("Error getting GPIO line1");
        gpiod_chip_close(chip1);
        return 1;
    }

    // Get the GPIO line
    line2 = gpiod_chip_get_line(chip2, line_offset2);
    if (!line2) {
        perror("Error getting GPIO line2");
        gpiod_chip_close(chip2);
        return 1;
    }


    // Request the GPIO line with specific configuration
    req = gpiod_line_request(line1, &config1, 0);
    if (req < 0) {
        perror("Error requesting GPIO line");
        gpiod_chip_close(chip1);
        return 1;
    }

    // Request the GPIO line with specific configuration
    req = gpiod_line_request(line2, &config2, 0);
    if (req < 0) {
        perror("Error requesting GPIO line");
        gpiod_chip_close(chip2);
        return 1;
    }


        
    while(1){
    	val = gpiod_line_get_value(line1);
    	if(val==0)
	    not_val = 1;
    	else
	    not_val = 0;
	    
    	gpiod_line_set_value(line2,not_val);
    }
    // Release the GPIO line
    gpiod_line_release(line1);

    // Close the GPIO chip
    gpiod_chip_close(chip1);


    // Release the GPIO line
    gpiod_line_release(line2);

    // Close the GPIO chip
    gpiod_chip_close(chip2);
 

    return 0;
}

