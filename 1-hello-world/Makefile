# Cross-compiler
CC = arm-buildroot-linux-gnueabihf-gcc


BUILDROOT_PATH := $(shell find ~/ -type f -path '*/buildroot/.config' -exec dirname {} \; 2>/dev/null | head -n 1)


# Destination path on the target
TARGET_PATH = $(BUILDROOT_PATH)/output/target/bin/

# Executable name
EXECUTABLE = hello

all: $(EXECUTABLE)

$(EXECUTABLE): hello.c
	$(CC) -o $@ $^

install: $(EXECUTABLE)
	cp $^ $(TARGET_PATH)

clean:
	rm -f $(EXECUTABLE)





.PHONY: all install clean

