#ifndef __FELDSPAR_PARALLELLA_H__
#define __FELDSPAR_PARALLELLA_H__

#include <stdbool.h>

#ifndef __epiphany__

#include <e-hal.h>

// host operations on core local memories

#define host_write_local(g, r, c, dst, src, offset, lower, upper) \
    e_write(g, r, c, (dst) + (offset) * sizeof(*src), (src) + (lower), ((upper) - (lower) + 1) * sizeof(*src))

#define host_read_local(g, r, c, src, dst, offset, lower, upper) \
    e_read(g, r, c, (src) + (offset) * sizeof(*dst), (dst) + (lower), ((upper) - (lower) + 1) * sizeof(*dst))

// host operations on shared external memory

#define host_write_shared(dst, src, offset, lower, upper) \
    e_write(dst, 0, 0, (offset) * sizeof(*src), (src) + (lower), ((upper) - (lower) + 1) * sizeof(*src))

#define host_read_shared(src, dst, offset, lower, upper) \
    e_read(src, 0, 0, (offset) * sizeof(*dst), (dst) + (lower), ((upper) - (lower) + 1) * sizeof(*dst))

// host channel polling interval in microseconds

#ifndef HOST_CHANNEL_POLL_USEC
#define HOST_CHANNEL_POLL_USEC 100
#endif

// host-to-core and core-to-host channel

typedef struct host_chan {
  e_epiphany_t *g;
  e_coreid_t r;
  e_coreid_t c;
  e_mem_t *buf;
  off_t is_open;
  off_t is_full;
} host_chan_t;

// host-to-core channel initialization

host_chan_t host_init_chan(e_epiphany_t *g, e_coreid_t r, e_coreid_t c,
                           e_mem_t *buf, off_t is_open_o, off_t is_full_o);

// host-to-core channel write

bool host_write_h2c(host_chan_t chan, void *src, size_t off, size_t len);

// core-to-host channel read

bool host_read_c2h(host_chan_t chan, void *dst, size_t off, size_t len);

#else /* __epiphany__ */

#include <e-lib.h>
#include <stdlib.h>

// halting current core

#define core_halt() return 0

// core operations on core local memories

#define core_write_local(dst, src, offset, lower, upper) \
    e_dma_copy((void*)((dst) + (offset)), (void*)((src) + (lower)), ((upper) - (lower) + 1) * sizeof(*src))

#define core_read_local(src, dst, offset, lower, upper) \
    fast_memcpy((void*)((dst) + (lower)), (void*)((src) + (offset)), ((upper) - (lower) + 1) * sizeof(*dst))

void fast_memcpy(void *dst, const void *src, size_t bytes);

// core operations on shared external memory

#define core_write_shared(dst, src, offset, lower, upper) \
    e_dma_copy((void*)(e_emem_config.base + (dst) + (offset) * sizeof(*src)), (void*)((src) + (lower)), ((upper) - (lower) + 1) * sizeof(*src))

#define core_read_shared(src, dst, offset, lower, upper) \
    e_dma_copy((void*)((dst) + (lower)), (void*)(e_emem_config.base + (src) + (offset) * sizeof(*dst)), ((upper) - (lower) + 1) * sizeof(*dst))

// host-to-core and core-to-host channel

typedef struct host_chan {
  volatile void *const buf;
  volatile bool *const is_open;
  volatile bool *const is_full;
} host_chan_t;

// host-to-core channel initialization

host_chan_t host_init_chan(volatile void *const buf,
                           volatile bool *const is_open,
                           volatile bool *const is_full);

// core-to-host channel write

bool core_write_c2h(host_chan_t chan, void *src, size_t off, size_t len);

// host-to-core channel read

bool core_read_h2c(host_chan_t chan, void *dst, size_t off, size_t len);

#endif /* __epiphany__ */

#endif /* __FELDSPAR_PARALLELLA_H__ */

