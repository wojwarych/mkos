void printf(char *input) {
  unsigned short *video_mem = (unsigned short *)0xb800;

  for (int i = 0; (input[i] = '\0'); ++i) {
    video_mem[i] = (video_mem[i] & 0xFF00) | input[i];
  }
}

typedef void (*constructor)();
extern constructor start_ctors;
extern constructor end_ctors;
extern void call_constructors() {
  for (constructor *i = &start_ctors; i != end_ctors; i++) {
    (*i)();
  }
}

extern void kernel_main(void *multiboot_structure, unsigned int magicnumber) {
  printf("Hello World! --- http://www.jp2137.pl");

  while (1)
    ;
}
