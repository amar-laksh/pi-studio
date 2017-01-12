INCLUDEDIR  = ../include
SYSDIR  = ../sys
STDLIBDIR = ../stdlib
DRIVERSDIR = ../drivers
KERNELDIR = ./
MEMDIR = ../mm
TESTDIR = ../test

INCLUDE    := $(shell find $(INCLUDEDIR) -name '*.c')
SYS	   := $(shell find $(SYSDIR) -name '*.c')
STDLIB     := $(shell find $(STDLIBDIR) -name '*.c')
DRIVERS    := $(shell find $(DRIVERSDIR) -name '*.c')
KERNEL     := $(shell find $(KERNELDIR) -name '*.c')
MEM 	   := $(shell find $(MEMDIR) -name '*.c')
TEST	   := $(shell find $(TESTDIR) -name '*.c')

OBJECTS = $(patsubst %.c,$(INCLUDEDIR)/%.o,$(INCLUDE)) $(patsubst %.c,$(SYSDIR)/%.o,$(SYS)) $(patsubst %.c,$(STDLIBDIR)/%.o,$(STDLIB)) $(patsubst %.c,$(DRIVERSDIR)/%.o,$(DRIVERS)) $(patsubst %.c,$(KERNELDIR)/%.o,$(KERNEL)) $(patsubst %.c,$(MEMDIR)/%.o,$(MEM)) boot.o 

#CC =  /root/ARM-CROSS/bin/arm-eabi-gcc
CC = arm-none-eabi-gcc
CFLAGS = -I../include -mcpu=arm1176jzf-s -fpic  -std=gnu99 -ffreestanding -O2 -Wall -Wextra -c
#AS =  /root/ARM-CROSS/bin/arm-eabi-as
AS = arm-none-eabi-as
LDFLAGS = -T linker.ld -o fos.elf -ffreestanding -O2 -nostdlib 
OBJCOPY = /root/ARM-CROSS/bin/arm-eabi-objcopy

clean:
	rm -rf *. ../drivers/*.o ../mm/*.o ../sys/*.o ../stdlib/*.o ../include/*.o *.o ./*.iso ./*.elf

all : kernel.bin clean


kernel.bin : $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -lgcc
	$(OBJCOPY) fos.elf -O binary kernel.img
	$(OBJCOPY) fos.elf -O binary kernel.bin

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

%.o: %.s
	$(AS) $< -o $@

kernel.elf : $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -lgcc

run: all
	../../raspbootin/raspbootcom/raspbootcom  /dev/ttyUSB0 ./kernel.img
#qemu-system-arm -kernel fos.elf -m 256 -M raspi2 -serial stdio
