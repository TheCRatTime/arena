/*
 * Copyright (C) 2026 TheCRatTime
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <arena.h>
#include <stdlib.h>

static int BadArena(Arena* arena) {
  if (arena == NULL) {
    return 1;
  }

  if (arena->capacity == 0            ||
      arena->data == NULL             ||
      arena->offset > arena->capacity) {
    return 1;
  }
  return 0;
}

Arena* InitArena(size_t init_cap) {
  char* slice = NULL;
  Arena* arena = NULL;

  if (init_cap == 0) {
    return NULL;
  }

  slice = (char*)malloc(sizeof(Arena) + init_cap);
  if (slice == NULL) {
    return NULL;
  }

  arena = (Arena*)(void*)slice;
  
  arena->data     = slice + sizeof(Arena);
  arena->capacity =              init_cap;
  arena->offset   =                     0;

  return arena;
}

void* ArenaAlloc(Arena* arena, size_t bytes) {
  char* ret = NULL;
  size_t total_size = 0;
  if (BadArena(arena) || bytes == 0) {
    return NULL;
  }

  total_size = ((bytes + 7) & (size_t)~7);
  if (arena->offset+total_size > arena->capacity) {
    return NULL;
  }

  ret = &arena->data[arena->offset];
  arena->offset += total_size;
  
  return ret;
}

void ArenaReset(Arena* to_reset) {
  if (BadArena(to_reset)) {
    return;
  }
  
  to_reset->offset = 0;
}

void FreeArena(Arena* ptr) {
  if (ptr) {
    free(ptr);
  }
}
