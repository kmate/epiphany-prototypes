#include <stdlib.h>
#include <stdint.h>

#include "feldspar-parallella.h"

#define N 10

volatile bool *const c2c_is_open = (bool *)0x2000;
volatile bool *const c2c_is_full = (bool *)0x2004;
volatile void *const c2c_buf = (void *)0x2008;

volatile bool *const c2h_is_open = (bool *)0x200c;
volatile bool *const c2h_is_full = (bool *)0x2012;
volatile void *const c2h_buf = (void *) 0x1000004;

// implements g: map (*2)
int main(void) {
  bool open = true;
  uint32_t value[1];
  while (open) {
    open = core_read_c2c(c2c_buf, c2c_is_open, c2c_is_full, value, 0, 1);
    if (open) {
      value[0] *= 2;
      open = core_write_c2h(c2h_buf, c2h_is_open, c2h_is_full, value, 0, 1);
    }
  }
  return EXIT_SUCCESS;
}

