#include "../includes/config.h"

void configuration_start() {
  // Allocate memory
  config = (config_struct *) malloc(sizeof(config_struct));
  char *serverport = (char *) malloc(READ_SIZE * sizeof(char));
  char *scheduling = (char *) malloc(READ_SIZE * sizeof(char));
  char *threadpool = (char *) malloc(READ_SIZE * sizeof(char));
  char *allowed = (char *) malloc(READ_SIZE * sizeof(char));

  // Read values from file
  FILE *configuration_file = fopen("./data/config.txt", "r");
  fscanf(configuration_file, "%[^\n]", serverport);
  fseek(configuration_file, 1, SEEK_CUR);
  fscanf(configuration_file, "%[^\n]", scheduling);
  fseek(configuration_file, 1, SEEK_CUR);
  fscanf(configuration_file, "%[^\n]", threadpool);
  fseek(configuration_file, 1, SEEK_CUR);
  fscanf(configuration_file, "%[^\n]", allowed);
  fclose(configuration_file);

  // Place those values on the config_struct
  config -> serverport = atoi(serverport);
  config -> scheduling = scheduling;
  config -> thread_pool = atoi(threadpool);
  config -> allowed = allowed;
  free(serverport);
  free(threadpool);
  return;
}

void change_configuration_file() {
  // Read values from file
  FILE *configuration_file = fopen("./data/config.txt", "w");
  fprintf(configuration_file, "%d\n", config->serverport);
  fprintf(configuration_file, "%s\n", config->scheduling);
  fprintf(configuration_file, "%d\n", config->thread_pool);
  fprintf(configuration_file, "%s\n", config->allowed);
  fclose(configuration_file);
  return;
}
