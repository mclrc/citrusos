# default: build
		
build: target/kernel.bin
run: target/os.iso
	qemu-system-x86_64 -cdrom target/os.iso
clean: 
	rm -r target

cpp:
	(cd src/cpp && make)
# target/main.o: src/cpp/main.cpp
# 	~/opt/cross/bin/x86_64-elf-gcc src/cpp/main.cpp -c -o target/main.o -nostdlib -nostartfiles
# target/terminal.o: src/cpp/terminal.cpp src/cpp/terminal.hpp
# 	~/opt/cross/bin/x86_64-elf-gcc src/cpp/terminal.cpp -c -o target/terminal.o -nostdlib -nostartfiles

# .PHONY: default build run clean

target/multiboot_header.o: src/asm/multiboot_header.asm
	mkdir -p target
	nasm -f elf64 src/asm/multiboot_header.asm -o target/multiboot_header.o

target/boot.o: src/asm/boot.asm cpp
	mkdir -p target
	nasm -f elf64 src/asm/boot.asm -o target/boot.o

target/kernel.bin: cpp target/multiboot_header.o target/boot.o src/asm/linker.ld cpp #target/main.o target/terminal.o
	ld -n -o target/kernel.bin -T src/asm/linker.ld target/multiboot_header.o target/boot.o target/cppkernel.a

target/os.iso: target/kernel.bin src/asm/grub.cfg
	mkdir -p target/isofiles/boot/grub
	cp src/asm/grub.cfg target/isofiles/boot/grub
	cp target/kernel.bin target/isofiles/boot/
	grub-mkrescue -o target/os.iso target/isofiles