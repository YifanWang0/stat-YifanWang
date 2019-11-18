#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(){
  printf("PRINTING MAKEFILE STATS \n\n");

  struct stat file_stats;
  if (stat("makefile", &file_stats) == -1){
    printf("%s\n", strerror(errno));
    return 0;
  }

  printf("File Size: %lld\n", file_stats.st_size);
  printf("Mode: %hu\n", file_stats.st_mode);
  printf("Time of Last Excess: %s\n", ctime(&file_stats.st_atime));

  char buffer[100];
  int size = file_stats.st_size;
  char *sizes[] = {"B", "KB", "MB", "GB"};
  int i = 0;
  while (size > 1000){
    size = size / 1000.0;
    i++;
  }
  sprintf(buffer, "%d%s", size, sizes[i]);
  printf("File size in human readable form: %s\n", buffer);

  char permissions[100];
  sprintf(permissions, "%o", file_stats.st_mode & 511);
  printf("File permissions: -");
  for (int i = 0; i < 3; i++) {
      if (permissions[i] == '0') {
          printf("---");
      } else if (permissions[i] == '1') {
          printf("--x");
      } else if (permissions[i] == '2') {
          printf("-w-");
      } else if (permissions[i] == '3') {
          printf("-wx");
      } else if (permissions[i] == '4') {
          printf("r--");
      } else if (permissions[i] == '5') {
          printf("r-x");
      } else if (permissions[i] == '6') {
          printf("rw-");
      } else {
          printf("rwx");
      }
  }
  printf("\n");
  return 0;
}
