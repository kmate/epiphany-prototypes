#include <stdint.h>
volatile int32_t *const spm1 = (int32_t *) 8192;
volatile int32_t *const spm2 = (int32_t *) 2157977600;
int main()
{
    uint32_t v0;
    
    for (v0 = 0; v0 <= 9; v0++) {
        int32_t v1;
        
        v1 = spm1[v0];
        spm2[v0] = v1 * 2;
    }
    return 0;
}
