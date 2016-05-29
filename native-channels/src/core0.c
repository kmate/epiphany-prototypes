#include <stdlib.h>
#include <stdint.h>

#include "feldspar-parallella.h"

#define N 10

volatile bool *const h2c_is_open = (bool *)0x2000;
volatile bool *const h2c_is_full = (bool *)0x2004;
volatile void *const h2c_buf = (void *)0x1000000;

volatile bool *const c2c_is_open = (bool *)((((0 + 32) * 64 + (8 + 1)) << 20) | 0x2000);
volatile bool *const c2c_is_full = (bool *)((((0 + 32) * 64 + (8 + 1)) << 20) | 0x2004);
volatile void *const c2c_buf = (void *)((((0 + 32) * 64 + (8 + 1)) << 20) | 0x2008);

// implements f: map (+1)
int main(void) {
  core_chan_t h2c = core_make_chan(h2c_buf, h2c_is_open, h2c_is_full);
  core_chan_t c2c = core_make_chan(c2c_buf, c2c_is_open, c2c_is_full);
  bool open = true;
  uint32_t value[1];
  while (open) {
    open = core_read_h2c(h2c, value, 0, sizeof(uint32_t));
    if (open) {
      value[0] += 1;
      core_write_c2c(c2c, value, 0, sizeof(uint32_t));
    }
  }
  core_close_chan(c2c);
  return EXIT_SUCCESS;
}

