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

#ifndef ARENA_ARENA_H_
#define ARENA_ARENA_H_

#include <stddef.h>

/* struct Arena */
typedef struct Arena {
  char* data;
  size_t capacity;
  size_t offset;
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
