#include <stdlib.h>
#include <stdint.h>

#include <e-lib.h>

#define N 10

uint32_t * const _d0 = (uint32_t *)0x1400000;
uint32_t * const _d1 = (uint32_t *)0x1400028; // _d0 + N * sizeof(uint32_t)
uint32_t * const _d2 = (uint32_t *)0x1400050; // _d1 + N * sizeof(uint32_t)

#define USE_DMA

#ifdef USE_DMA
#define ex_read(src, dst, size) e_dma_copy(dst, e_emem_config.base + src, size)
#define ex_write(src, dst, size) e_dma_copy(e_emem_config.base + dst, src, size)
#else
#define ex_read(src, dst, size) e_read(&e_emem_config, dst, 0, 0, src, size)
#define ex_write(src, dst, size) e_write(&e_emem_config, src, 0, 0, dst, size)
#endif


// implements g: map (*2)
int main(void) {
  uint32_t d1[N];
  uint32_t d2[N];

  ex_read(_d1, d1, N * sizeof(uint32_t));

  for (int i = 0; i < N; ++i) {
    d2[i] = d1[i] * 2;
  }

  ex_write(d2, _d2, N * sizeof(uint32_t));

  return EXIT_SUCCESS;
}

