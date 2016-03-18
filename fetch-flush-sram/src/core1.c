#include <stdlib.h>
#include <stdint.h>

#define N 10

//                                                        -- d1 <- allocSpm 1 10
// input in core1 local memory
// bank1 of core (0,1)
uint32_t * const d1 = (uint32_t *)((((0 + 32) * 64 + (8 + 1)) << 20) | 0x2000);
// uint32_t d1[N] SECTION(".data_bank1");
// problem: overwrites on load

// output to input area of core2
// bank1 of core (0,2)
uint32_t * const d2 = (uint32_t *)((((0 + 32) * 64 + (8 + 2)) << 20) | 0x2000);
// extern uint32_t d2[N];
// problem: could not be resolved by the linker

// implements g: map (*2)
int main(void) {
  for (int i = 0; i < N; ++i) {
    d2[i] = d1[i] * 2;
  }
  return EXIT_SUCCESS;
}

