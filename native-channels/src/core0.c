#include <stdlib.h>
#include <stdint.h>

#include "feldspar-parallella.h"

#define N 10

volatile bool *const h2c_is_open = (bool *)8192;
volatile bool *const h2c_is_full = (bool *)8196;
volatile void *const h2c_buf = (void *)0x1000000;

volatile bool *const c2c_is_open = (bool *)((((0 + 32) * 64 + (8 + 1)) << 20) | 8192);
volatile bool *const c2c_is_full = (bool *)((((0 + 32) * 64 + (8 + 1)) << 20) | 8196);
volatile void *const c2c_buf = (void *)((((0 + 32) * 64 + (8 + 1)) << 20) | 8300);

// implements f: map (+1)
int main(void) {
  core_chan_t h2c = core_init_chan(h2c_buf, h2c_is_open, h2c_is_full);
  core_chan_t c2c = core_init_chan(c2c_buf, c2c_is_open, c2c_is_full);
  bool open = true;
  uint32_t value[1];
  while (open) {
    open = core_read_h2c(h2c, value, 0, 1);
    if (open) {
      value[0]++;
      open = core_write_c2c(c2c, value, 0, 1);
    }
  }
  return EXIT_SUCCESS;
}

