#include <stdint.h>
volatile int32_t *const spm0 = (int32_t *) 8192;
volatile int32_t *const spm1 = (int32_t *) 2156929024;
int main()
{
    uint32_t v0;
    
    for (v0 = 0; v0 <= 9; v0++) {
        int32_t v1;
        
        v1 = spm0[v0];
        spm1[v0] = v1 + 1;
    }
    return 0;
}
