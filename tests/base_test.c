#include <string.h>
#define ARENA_SOURCE
#include "../include/arena.h"

#include <assert.h>

#define TEST_ARENA_SIZE 4096
#define TEST_BUFSIZ        5

static void Corruption(void) {
  Arena* test = InitArena(TEST_ARENA_SIZE);
  int* data = (int*)ArenaAlloc(test, sizeof(int));
  char* buffer = (char*)ArenaAlloc(test, TEST_BUFSIZ);
  
  assert(test != NULL);
  assert(data != NULL);
  assert(buffer != NULL);

  *data = 5;
  assert(*data == 5);

  /* Corruption */
  strcpy(buffer, "too large");

  ArenaReset(test);

  /* Writed to 'buffer' more than 8 bytes. */
  assert(test->corruptions == 1);

  /* sizeof(int) -> 8
     5 -> 8
     8 + 8 = 16 - allocated */
  assert(test->peak_usage == 16);

  FreeArena(test);
}

int main(void) {
  Corruption();
  return 0;
}
