#include <stdbool.h>
#include <stdint.h>
volatile bool *const spm2 = (bool *) 8192;
volatile int32_t *const spm3 = (int32_t *) 8196;
volatile bool *const spm4 = (bool *) 2157977600;
volatile int32_t *const spm5 = (int32_t *) 2157977604;
int main()
{
    while (1) {
        uint32_t v1;
        
        while (1) {
            bool v0;
            
            v0 = spm2[0];
            if (v0) {
                break;
            }
        }
        spm2[0] = false;
        for (v1 = 0; v1 < 4; v1++) {
            int32_t v2;
            
            v2 = spm3[v1];
            spm5[v1] = v2 * 2;
        }
        spm4[0] = true;
    }
    return 0;
}
