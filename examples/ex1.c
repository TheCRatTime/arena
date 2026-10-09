#define ARENA_SOURCE
/* Without debug information */
#define FAST_ARENA

/* Using BIND */
#define NEEDED_BIND
#include "../include/arena.h"

#include <stdio.h>

/* Generate BIND with ID 'ex' */
GEN_BIND(ex);

int main(void) {
  Arena* example = InitArena(4096);
  int* data1 = NULL;
  int* data2 = NULL;
  
  if (example == NULL) {
    printf("Out of memory\n");
    return 1;
  }

  /* Using BIND */
  BindIDex(example);

  /* This is C++ style. */
  /* Can allocate so: */
  data1 = example->Alloc(sizeof(int));
  data2 = example->Alloc(sizeof(int));

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
