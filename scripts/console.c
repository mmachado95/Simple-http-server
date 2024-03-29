#include "../includes/console.h"

int main() {
  int option;
  char change[50];
  config_struct_aux new_config;

  while(1) {
    printf("Change:\n1 - Scheduling\n2 - Number of threads\n3 - List of compressed files\n");
    option = menu_protection();
    printf("Change: ");
    scanf("%s", change);
    new_config.option = option;
    strcpy(new_config.change, change);
    write_in_pipe(new_config);
  }

  return 0;
}

int menu_protection() {
  char str[MAX_CHAR];

  while (scanf(" %[^\n]", str) ) {
    int i = 0;
    int len = strlen(str);

    while (i < len) {
      if (str[i] < '0' || str[i] > '4' || i > 0) {
        printf("Invalid Input. Choose number from 1 to 3");
        return menu_protection();
      }
      i++;
    }
    break;
  }

  return atoi(str);
}

void write_in_pipe(config_struct_aux config) {
  // Opens the pipe for writing
  int fd;
  if ((fd = open(PIPE_NAME, O_WRONLY)) < 0) {
    perror("Cannot open pipe for writing: ");
    exit(1);
  }

  printf("[CLIENT] Sending (%d %s) for adding\n", config.option, config.change);
  write(fd, &config, sizeof(config_struct_aux));
}
