# arena
**arena** - allocate memory and free memory once.

# Description
This is **Single-header** library with fast memory arena.
You need allocate memory and free it once.

## Features
- ANSI C/C89 code standard.
- Single-header library.
- Out-Of-Bounds detection.
- Quick start.
- Compiles with `-Weverything -pedantic -Werror -Wno-unsafe-buffer-usage` flags.

## Quick start
```c
#define ARENA_SOURCE
/* Using debug arena */
#define ARENA_DEBUG
#include "arena.h"

int main(void) {
  Arena* example = InitArena(4096);
  int* data = (int*)ArenaAlloc(example, sizeof(int));
  char* buffer = (char*)ArenaAlloc(example, 1024);

  if (example == NULL) {
    return 1;
  }

  if (data == NULL || buffer == NULL) {
    /* Only free arena. */
    FreeArena(example);
    return 1;
  }

  /* Peak usage: */
  printf("Peak usage: %lu\n", example->peak_usage);

  /* ... */

  /* Just free arena, no need free buffer or data */
  FreeArena(example);
  return 0;
}
```

### Building

```bash
cmake -B build
cd build/
make
```

### Authors
TheCRatTime.

### Examples
You can see examples in **examples/** directory.

### License
Project is under Apache 2.0 license.

### Also
See this README.md in manual -> **README.1** with
this command:

```bash
man -l README.1
```
