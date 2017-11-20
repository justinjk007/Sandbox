#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Checks ----
 * Check for number of arguments
 * Check for read file not existing
 * Check for write file not existing
 * Check for not enough memory for writing
 */

int main(int argc, char *argv[]) {
  /* Check for correctly formated input */
  if (argc < 3) {
    printf("dupilcate: Too few arguments!!\n");
    printf("    usage: duplicate <sourcefile> <targetfile>\n");
    return 1;
  } else if (argc > 3) {
    printf("dupilcate: Too many arguments!!\n");
    printf("    usage: duplicate <sourcefile> <targetfile>\n");
    return 1;
  }

  FILE *from_file, *to_file;
  long length, copy_size_in_bytes;
  char *file_array = 0;
  int array_len; /* Length of file array */

  /* Open file for reading */
  from_file = fopen(argv[1], "r");
  if (!from_file) {
    perror("File opening for reading failed\n");
    return 1;
  }

  /* Find length of the file opened */
  fseek(from_file, 0, SEEK_END);
  length = ftell(from_file);
  fseek(from_file, 0, SEEK_SET);
  printf("Length of file: %ld\n", length);
  copy_size_in_bytes = 4 * length;
  file_array =
      (char *)malloc(sizeof(char) * length); /* change the buffer size */

  /* Copy contents of file into array */
  if (file_array) {
    int reading = fread(file_array, 1, length, from_file);
    fclose(from_file); /* Close input file */
    if (reading != length) {
      printf("Reading file failed!!\n");
      return 1;
    }
  } else {
    printf("duplicate: DISK FULL!!, Couldn;t allocate enough memory\n",
           argv[2]);
    return 1;
  }


  /* Open file for writing */
  to_file = fopen(argv[2], "w");
  if (!to_file) {
    perror("File opening for writing failed!!\n");
    return 1;
  }

  /* Write array to file char by char */
  array_len = sizeof(file_array) / sizeof(file_array[0]);
  for (int i = 0; i <= array_len; ++i) {
    fputc(file_array[i], to_file);
    if (ferror(to_file)) {
      printf("duplicate: Error duplicating file !! DISK FULL\n");
      fclose(to_file); /* Close output file */
      return 1;
    }
  }
  printf("duplicate: Copied %ld bytes from file %s to %s\n", copy_size_in_bytes,argv[1],argv[2]);
  fclose(to_file); /* Close output file */

  return 0; /* Finite incantatem */
}
