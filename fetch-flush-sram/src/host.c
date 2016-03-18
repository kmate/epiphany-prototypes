/** Assume the original Feldspar program is something like the following:

example :: Software ()
example = do
  input <- {- initialize an array with at least 10 elements -}
  d0 <- allocSpm 0 10
  fetch d0 (0, 9) input
  d1 <- allocSpm 1 10
  onCore 0 (f d0 d1) {- f maps (+1) -}
  d2 <- allocSpm 2 10
  onCore 1 (g d1 d2) {- g maps (*2) -}
  flush d2 (0, 9) output
  {- print the output -}
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <unistd.h>
#include <time.h>

#include <e-hal.h>
#include <e-loader.h>

#define N 10

// from where the input is fetched into d0
uint32_t input[N];

// where the result is flushed from d3
uint32_t output[N];

// d0 <- allocSpm 0 10
// local address of bank1 on core (0,0)
off_t d0 = 0x2000;

// d2 <- allocSpm 2 10
// local address of bank1 on core (0,2)
off_t d2 = 0x2000;

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

  //                                                    -- fetch d0 (0, 9) input
  // to bank1 of core 0
  e_write(&group, 0, 0, d0, input, N * sizeof(uint32_t));

  //                                                       -- onCore 0 (f d0 d1)
  printf("Running f on core 0\n");
  e_load("core0.srec", &group, 0, 0, E_TRUE);
  // should poll until finish (maybe a software interrupt later?)
  usleep(1000);

  //                                                       -- onCore 1 (g d1 d2)
  printf("Running g on core 1\n");
  e_load("core1.srec", &group, 0, 1, E_TRUE);
  // should poll until finish (maybe a software interrupt later?)
  usleep(1000);

  //                                                   -- flush d2 (0, 9) output
  // from bank1 of core 2
  e_read(&group, 0, 2, d2, output, N * sizeof(uint32_t));

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

