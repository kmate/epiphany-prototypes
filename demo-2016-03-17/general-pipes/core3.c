#include <stdbool.h>
#include <stdint.h>
volatile uint32_t *const spm10 = (uint32_t *) 8196;
volatile int32_t *const spm11 = (int32_t *) 8200;
volatile uint32_t *const spm12 = (uint32_t *) 8212;
volatile uint32_t *const spm13 = (uint32_t *) 8216;
volatile int32_t *const spm14 = (int32_t *) 8220;
volatile uint32_t *const spm15 = (uint32_t *) 2222989312;
volatile uint32_t *const spm16 = (uint32_t *) 2222989316;
volatile int32_t *const spm17 = (int32_t *) 2222989320;
volatile uint32_t *const spm9 = (uint32_t *) 8192;
int main()
{
    while (1) {
        uint32_t v2;
        int32_t v3;
        uint32_t v6;
        int32_t v7;
        
        while (1) {
            uint32_t v0;
            uint32_t v1;
            
            v0 = spm9[0];
            v1 = spm10[0];
            if (!(v0 == v1)) {
                break;
            }
        }
        v2 = spm9[0];
        v3 = spm11[v2];
        spm9[0] = (v2 + 1) % 3;
        while (1) {
            uint32_t v4;
            uint32_t v5;
            
            v4 = spm12[0];
            v5 = spm13[0];
            if (!(v4 == v5)) {
                break;
            }
        }
        v6 = spm12[0];
        v7 = spm14[v6];
        spm12[0] = (v6 + 1) % 3;
        while (1) {
            uint32_t v8;
            uint32_t v9;
            bool r10;
            bool v12;
            
            v8 = spm15[0];
            v9 = spm16[0];
            r10 = false;
            if ((v9 + 1) % 3 == v8) {
                r10 = false;
            } else {
                uint32_t v11;
                
                v11 = spm16[0];
                spm17[v11] = v3 + v7;
                spm16[0] = (v11 + 1) % 3;
                r10 = true;
            }
            v12 = r10;
            if (v12) {
                break;
            }
        }
    }
    return 0;
}
