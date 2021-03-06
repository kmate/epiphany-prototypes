#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <unistd.h>
#include <time.h>

#include <e-hal.h>
#include <e-loader.h>

#include "feldspar-parallella.h"

#define N 4

uint32_t input[N];
uint32_t output[N];

off_t h2c_is_open = 0x2000;
off_t h2c_is_full = 0x2004;
off_t h2c_buf_o = 0x1000000;

off_t c2c_is_open = 0x2000;
off_t c2c_is_full = 0x2004;

off_t c2h_is_open = 0x200c;
off_t c2h_is_full = 0x2012;
off_t c2h_buf_o = 0x1000004;

int main(int argc, char *argv[])
{
  printf("[Started]\n");

  srand(time(NULL));
  for (int i = 0; i < N; ++i) {
    input[i] = rand() % 10;
  }

  printf("Input:");
  for (int i = 0; i < N; ++i) {
    printf(" %"PRIu32, input[i]);
  }
  puts("");

////////////////////////////////////////////////////////////////////////////////

  e_platform_t platform;
  e_epiphany_t group;

  e_init(NULL);
  e_reset_system();
  e_get_platform_info(&platform);

  e_open(&group, 0, 0, 1, 3);
  e_reset_group(&group);

  e_load("core0.elf", &group, 0, 0, E_FALSE);
  e_load("core1.elf", &group, 0, 1, E_FALSE);

  e_mem_t h2c_buf, c2h_buf;
  e_alloc(&h2c_buf, h2c_buf_o, sizeof(uint32_t));
  e_alloc(&c2h_buf, c2h_buf_o, sizeof(uint32_t));

  host_chan_t h2c;
  init_host_chan(&h2c, &group, 0, 0, &h2c_buf, h2c_is_open, h2c_is_full);
  host_chan_t c2h;
  init_host_chan(&c2h, &group, 0, 1, &c2h_buf, c2h_is_open, c2h_is_full);
  init_core_chan(&group, 0, 1, c2c_is_open, c2c_is_full);

  printf("Running f on core 0\n");
  e_start(&group, 0, 0);

  printf("Running g on core 1\n");
  e_start(&group, 0, 1);

  for (int i = 0; i < N; ++i) {
    host_write_h2c(h2c, input, i, 1);
    host_read_c2h(c2h, output, i, 1);
  }

  host_close_chan(h2c);
  host_close_chan(c2h);

  e_free(&h2c_buf);
  e_free(&c2h_buf);

  e_close(&group);
  e_finalize();

////////////////////////////////////////////////////////////////////////////////

  printf("Output:");
  for (int i = 0; i < N; ++i) {
    printf(" %"PRIu32, output[i]);
  }
  puts("");

  printf("[Finished]\n");
  return EXIT_SUCCESS;
}

