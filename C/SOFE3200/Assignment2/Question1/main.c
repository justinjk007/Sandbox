 #include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  // Check for argument count, first argument is the name of the executable
  if (argc != 3) {
    printf("duplicate: incorrect number of arguments!\n");
    printf("Usage: duplicate <sourcefile> <sourcefile>\n");
    exit(EXIT_FAILURE);
  }

  // Declare and initialize variables
  char ch, from_file[20], to_file[20];
  int size;
  FILE *from, *to;

  // Assignment to variables
  strncpy(from_file, argv[1], sizeof(from_file));
  strncpy(to_file, argv[2], sizeof(to_file));

  // Open from file in read mode
  from = fopen(from_file, "r");

  // Check for file does not exist error
  if (from == NULL) {
    printf("duplicate: Couldn't open file %s \n", from_file);
    exit(EXIT_FAILURE);
  }

  // Check for any other errors
  if (errno != 0) {
    printf("Error: %s \n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  // Determine file size by seeking to eof
  // then asking for position, returns # of bytes
  fseek(from, 0, SEEK_END);
  size = ftell(from);
  // Go back to start of file
  rewind(from);

  // Open to file in write mode
  to = fopen(to_file, "w");

  // Check for file does not exist error
  if (to == NULL) {
    fclose(from);
    printf("duplicate: Couldn't open file %s \n", to_file);
    exit(EXIT_FAILURE);
  }

  // Check for any other errors
  if (errno != 0) {
    fclose(from);
    fclose(to);
    printf("Error: %s \n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  // Copy each char from from to to file one at a time
  clock_t start = clock();
  while ((ch = fgetc(from)) != EOF) {
    clock_t current = clock();
    fputc(ch, to);
    // Check if its been 1 second, if yes, start outputting message
    if (current >= (start + 1 * CLOCKS_PER_SEC)) {
      printf("duplicate: still duplicating...");
    }
  }

  // Success message
  printf("File copied successfully %d bytes from file %s to %s \n", size,
         from_file, to_file);

  // Close files
  fclose(from);
  fclose(to);

  return 0;
}
