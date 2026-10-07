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

/* === BEGIN HEADER === */

#ifndef ARENA_ARENA_H_
#define ARENA_ARENA_H_

#include <stddef.h>

/* struct Arena */
typedef struct Arena {
  char* data;      /* Arena data          */
  size_t capacity; /* Total size of arena */
  size_t offset;   /* Offset of arena     */
} Arena;

/* Initial function for arena */
Arena* InitArena(size_t);

/* Alloc memory from arena */
void* ArenaAlloc(Arena*, size_t);

/* Reset arena (free all objects) */
void ArenaReset(Arena*);

/* Free arena */
void FreeArena(Arena*);

#endif /* ARENA_ARENA_H_ */
/************************/

/* === BEGIN SOURCE === */

#ifdef ARENA_SOURCE

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

  /* 8-byte alignment */
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

  /* Just reset offset */
  to_reset->offset = 0;
}

void FreeArena(Arena* ptr) {
  if (ptr) {
    free(ptr);
  }
}

#endif /* ARENA_SOURCE */
/************************/
