# Cross-compiler
CC = arm-buildroot-linux-gnueabihf-gcc

BUILDROOT_PATH := $(shell find ~/ -type f -path '*/buildroot/.config' -exec dirname {} \; 2>/dev/null | head -n 1)

# Destination path on the target
TARGET_PATH = $(BUILDROOT_PATH)/output/target/bin/

#Library FLAG
LDFLAGS := -lgpiod

# Executable name
EXECUTABLE = nand_gate

all: $(EXECUTABLE)

$(EXECUTABLE): nand_gate.c
	$(CC) -o $@ $^ $(LDFLAGS)

install: $(EXECUTABLE)
	cp $^ $(TARGET_PATH)

clean:
	rm -f $(EXECUTABLE)

.PHONY: all install clean

