#include <stdio.h>
#include <gpiod.h>
#include <unistd.h>

int main() {
    const char *chipname = "/dev/gpiochip0"; // Path to your GPIO character device
    const unsigned int line_offset = 7;// GPIO line offset

    struct gpiod_chip *chip;
    struct gpiod_line *line;
    struct gpiod_line_request_config config = {
        .consumer = "led",
        .request_type = GPIOD_LINE_REQUEST_DIRECTION_OUTPUT,
    };
    int req, val=0;

    // Open the GPIO character device
    chip = gpiod_chip_open(chipname);
    if (!chip) {
        perror("Error opening GPIO chip");
        return 1;
    }

    // Get the GPIO line
    line = gpiod_chip_get_line(chip, line_offset);
    if (!line) {
        perror("Error getting GPIO line");
        gpiod_chip_close(chip);
        return 1;
    }

    // Request the GPIO line with specific configuration
    req = gpiod_line_request(line, &config, 0);
    if (req < 0) {
        perror("Error requesting GPIO line");
        gpiod_chip_close(chip);
        return 1;
    }


    // Toggle the GPIO value
    for (int i = 0; i < 11; i++) {
        printf("GPIO value: %d\n", val);
	val = !val;
        gpiod_line_set_value(line, !val);
        sleep(1);
    }

    // Release the GPIO line
    gpiod_line_release(line);

    // Close the GPIO chip
    gpiod_chip_close(chip);

    return 0;
}

