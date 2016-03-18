#include <stdbool.h>
#include <stdint.h>
volatile uint32_t *const spm12 = (uint32_t *) 2159026196;
volatile uint32_t *const spm13 = (uint32_t *) 2159026200;
volatile int32_t *const spm14 = (int32_t *) 2159026204;
volatile uint32_t *const spm6 = (uint32_t *) 8192;
volatile uint32_t *const spm7 = (uint32_t *) 8196;
volatile int32_t *const spm8 = (int32_t *) 8200;
int main()
{
    while (1) {
        uint32_t v2;
        int32_t v3;
        
        while (1) {
            uint32_t v0;
            uint32_t v1;
            
            v0 = spm6[0];
            v1 = spm7[0];
            if (!(v0 == v1)) {
                break;
            }
        }
        v2 = spm6[0];
        v3 = spm8[v2];
        spm6[0] = (v2 + 1) % 3;
        while (1) {
            uint32_t v4;
            uint32_t v5;
            bool r6;
            bool v8;
            
            v4 = spm12[0];
            v5 = spm13[0];
            r6 = false;
            if ((v5 + 1) % 3 == v4) {
                r6 = false;
            } else {
                uint32_t v7;
                
                v7 = spm13[0];
                spm14[v7] = v3 * 2;
                spm13[0] = (v7 + 1) % 3;
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
