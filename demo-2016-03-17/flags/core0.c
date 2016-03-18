#include <stdbool.h>
#include <stdint.h>
volatile bool *const spm0 = (bool *) 8192;
volatile int32_t *const spm1 = (int32_t *) 8196;
volatile bool *const spm2 = (bool *) 2156929024;
volatile int32_t *const spm3 = (int32_t *) 2156929028;
int main()
{
    while (1) {
        uint32_t v1;
        
        while (1) {
            bool v0;
            
            v0 = spm0[0];
            if (v0) {
                break;
            }
        }
        spm0[0] = false;
        for (v1 = 0; v1 < 4; v1++) {
            int32_t v2;
            
            v2 = spm1[v1];
            spm3[v1] = v2 + 1;
        }
        spm2[0] = true;
    }
    return 0;
}
