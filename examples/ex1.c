#define ARENA_SOURCE
#include "../include/arena.h"

#include <stdio.h>

int main(void) {
  Arena* example = InitArena(4096);
  /* Don't falls ArenaAlloc because function's checking arena. */
  int* data1 = (int*)ArenaAlloc(example, sizeof(int));
  int* data2 = (int*)ArenaAlloc(example, sizeof(int));
  
  if (example == NULL) {
    printf("Out of memory\n");
    return 1;
  }

  if (data1 == NULL || data2 == NULL) {
    /* Need only free arena. */
    FreeArena(example);
    printf("Arena allocate failed\n");
    return 1;
  }

  *data1 = 5;
  *data2 = 50;
  
  printf("%d + %d = %d\n", *data1, *data2, (*data1 + *data2));

  /* You only free arena */
  FreeArena(example);
  return 0;
}
