#include <stdlib.h>
#include <stdint.h>

#include "feldspar-parallella.h"

#define N 10

volatile bool *const c2c_is_open = (bool *)8192;
volatile bool *const c2c_is_full = (bool *)8196;
volatile void *const c2c_buf = (void *)8300;

volatile bool *const c2h_is_open = (bool *)8200;
volatile bool *const c2h_is_full = (bool *)8204;
volatile void *const c2h_buf = (void *) 0x1000004;

// implements g: map (*2)
int main(void) {
  core_chan_t c2c = core_init_chan(c2c_buf, c2c_is_open, c2c_is_full);
  core_chan_t c2h = core_init_chan(c2h_buf, c2h_is_open, c2h_is_full);
  bool open = true;
  uint32_t value[1];
  while (open) {
    open = core_read_c2c(c2c, value, 0, 1);
    if (open) {
      value[0] << 1;
      open = core_write_c2h(c2h, value, 0, 1);
    }
  }
  return EXIT_SUCCESS;
}

