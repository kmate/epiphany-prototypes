#include <stdlib.h>
#include <stdint.h>

#define N 10

// --                                                        d0 <- allocSpm 0 10
// input in core0 local memory
// bank1 of core (0,0)
uint32_t * const d0 = (uint32_t *)((((0 + 32) * 64 + (8 + 0)) << 20) | 0x2000);
// uint32_t d0[N] SECTION(".data_bank1");
// problem: overwrites on load

// output to input area of core1
// bank1 of core (0,1)
uint32_t * const d1 = (uint32_t *)((((0 + 32) * 64 + (8 + 1)) << 20) | 0x2000);
// extern uint32_t d1[N];
// problem: could not be resolved by the linker

// implements f: map (+1)
int main(void) {
  for (int i = 0; i < N; ++i) {
    d1[i] = d0[i] + 1;
  }
  return EXIT_SUCCESS;
}

