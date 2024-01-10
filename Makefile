ASMFLAGS += -f elf
CFLAGS += -ffreestanding -nostdlib
LINKFLAGS += -nostdlib -m elf_i386
TARGET_LINKFLAGS2 += -T stage1/linker.ld -nostdlib -m elf_i386

CC := i686-elf-gcc
LD := i686-elf-ld
ASM?=nasm

FILES = ./build/kernel.S.o

all: ./bin/boot.bin ./bin/kernel.bin
	rm -rf ./bin/os.bin
	dd if=./bin/boot.bin >> ./bin/os.bin
	dd if=./bin/kernel.bin >> ./bin/os.bin
	dd if=/dev/zero bs=512 count=100 >> ./bin/os.bin

./bin/boot.bin: ./src/boot/boot.S
	$(ASM) -f bin ./src/boot/boot.S -o ./bin/boot.bin

./bin/kernel.bin: $(FILES)
	$(LD) -g -relocatable $(FILES) -o ./build/kernelfull.o
	$(CC) -T ./src/linker.ld -o ./bin/kernel.bin -ffreestanding -O0 -nostdlib ./build/kernelfull.o 


./build/kernel.S.o: ./src/kernel.S
	$(ASM) -f elf -g ./src/kernel.S -o ./build/kernel.S.o

debug:
	qemu-system-x86_64 -hda ./bin/os.bin

clean:
	rm -rf ./bin/boot.bin
