#include "../includes/scheduler.h"
#include "../includes/config.h"

void terminate_thread() {
  printf("Terminating thread...\n");
  pthread_exit(0);
}

// Threads routine
void *scheduler_thread_routine() {
  while(1) {
    printf("This is a thread.\n");
    sleep(2);
  }
  return NULL;
}

// Create pool of threads
void create_scheduler_threads() {
  signal(SIGUSR1, terminate_thread);
  int i;
  long ids[config -> thread_pool];
  // Create pool of threads
  thread_pool = malloc(sizeof(pthread_t) * config->thread_pool);

  if (thread_pool == NULL) {
    perror("Error allocating memory for threads\n");
  }

  // Create threads
  for (i = 0; i < config->thread_pool; i++) {
    ids[i] = i;
    if (pthread_create(&thread_pool[i], NULL, scheduler_thread_routine, (void *)ids[i]) != 0) {
      perror("Error creating thread");
    }
  }
}

// Delete threads
void delete_scheduler_threads() {
  printf("Cleaning up scheduler...\n");
  int i;
  for (i = 0; i < config->thread_pool; i++) {
    pthread_join(thread_pool[i], NULL);
  }
}
