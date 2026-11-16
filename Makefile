CCPARAMS = -m32 -march=i386 -nostdlib -fno-builtin -fno-exceptions -fno-leading-underscore
ASPARAMS = --32
LDPARAMS = -melf_i386

objects = loader.o kernel.o

%.o: %.c
	gcc $(CCPARAMS) -o $@ -c $<

%.o: %.s
	as $(ASPARAMS) -o $@ -c $<

mykernel.bin: linker.ld $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)

install: mykernel.bin
	sudo cp $< /boot/mykernel.bin
