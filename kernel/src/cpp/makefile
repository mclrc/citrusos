../../target/cppkernel.a: build/terminal.o build/main.o
	mkdir -p ../../target
	ar cr ../../target/cppkernel.a build/terminal.o build/main.o

build/terminal.o: terminal.cpp terminal.hpp stringutils.hpp
	~/opt/cross/bin/x86_64-elf-gcc terminal.cpp -c -o build/terminal.o -nostdlib -nostartfiles
build/main.o: main.cpp stringutils.hpp
	~/opt/cross/bin/x86_64-elf-gcc main.cpp -c -o build/main.o -nostdlib -nostartfiles