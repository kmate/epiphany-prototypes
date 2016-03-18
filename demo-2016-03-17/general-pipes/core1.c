#include <stdbool.h>
#include <stdint.h>
volatile uint32_t *const spm10 = (uint32_t *) 2159026180;
volatile int32_t *const spm11 = (int32_t *) 2159026184;
volatile uint32_t *const spm3 = (uint32_t *) 8192;
volatile uint32_t *const spm4 = (uint32_t *) 8196;
volatile int32_t *const spm5 = (int32_t *) 8200;
volatile uint32_t *const spm9 = (uint32_t *) 2159026176;
int main()
{
    while (1) {
        uint32_t v2;
        int32_t v3;
        
        while (1) {
            uint32_t v0;
            uint32_t v1;
            
            v0 = spm3[0];
            v1 = spm4[0];
            if (!(v0 == v1)) {
                break;
            }
        }
        v2 = spm3[0];
        v3 = spm5[v2];
        spm3[0] = (v2 + 1) % 3;
        while (1) {
            uint32_t v4;
            uint32_t v5;
            bool r6;
            bool v8;
            
            v4 = spm9[0];
            v5 = spm10[0];
            r6 = false;
            if ((v5 + 1) % 3 == v4) {
                r6 = false;
            } else {
                uint32_t v7;
                
                v7 = spm10[0];
                spm11[v7] = v3 + 1;
                spm10[0] = (v7 + 1) % 3;
                r6 = true;
            }
            v8 = r6;
            if (v8) {
                break;
            }
        }
    }
    return 0;
}
