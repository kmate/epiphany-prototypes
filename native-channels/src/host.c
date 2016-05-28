#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <unistd.h>
#include <time.h>

#include <e-hal.h>
#include <e-loader.h>

#include "feldspar-parallella.h"

#define N 10

uint32_t input[N];
uint32_t output[N];

off_t h2c_is_open = 8192;
off_t h2c_is_full = 8196;
off_t h2c_buf_o = 0x1000000;

off_t c2h_is_open = 8200;
off_t c2h_is_full = 8204;
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

  e_mem_t h2c_buf, c2h_buf;
  e_alloc(&h2c_buf, h2c_buf_o, sizeof(uint32_t));
  e_alloc(&c2h_buf, c2h_buf_o, sizeof(uint32_t));

  host_chan_t h2c = host_init_chan(&group, 0, 0, &h2c_buf, h2c_is_open, h2c_is_full);
  host_chan_t c2h = host_init_chan(&group, 0, 1, &c2h_buf, c2h_is_open, c2h_is_full);

  printf("Running f on core 0\n");
  e_load("core0.srec", &group, 0, 0, E_TRUE);

  printf("Running g on core 1\n");
  e_load("core1.srec", &group, 0, 1, E_TRUE);

  for (int i = 0; i < N; ++i) {
    host_write_h2c(h2c, input, i * sizeof(uint32_t), sizeof(uint32_t));
    host_read_c2h(c2h, output, i * sizeof(uint32_t), sizeof(uint32_t));
  }

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

