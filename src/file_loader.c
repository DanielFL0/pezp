#include <stdio.h>
#include <stdlib.h>
#include "file_loader.h"

void read_image_file(FILE* file) {
  fseek(file, 0L, SEEK_END);
  int fsize = ftell(file);
  fseek(file, 0L, SEEK_SET);
  unsigned char *buffer = malloc(fsize);
  size_t read = fread(buffer, fsize, 1, file);
  while (read-- > 0) {

  }
}

int read_image(char* image_path) {
  FILE* file = fopen(image_path, "rb");
  if (file == NULL)
    return 1;
  read_image_file(file);
  fclose(file);
  return 0;
}