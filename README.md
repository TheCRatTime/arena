# arena
**arena** - allocate memory and free memory once.

# Description
This is **Single-header** library with fast memory arena.
You need allocate memory and free it once.

## Features
- ANSI C/C89 code standard.
- Single-header library.
- Out-Of-Bounds detection.
- Compiles with `-Weverything -pedantic -Werror -Wno-unsafe-buffer-usage -Wno-old-style-cast` flags.

## Quick start
```c
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
