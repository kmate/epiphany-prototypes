#include <stdbool.h>
#include <stdint.h>
volatile uint32_t *const spm0 = (uint32_t *) 8192;
volatile uint32_t *const spm1 = (uint32_t *) 8196;
volatile int32_t *const spm2 = (int32_t *) 8200;
volatile uint32_t *const spm3 = (uint32_t *) 2156929024;
volatile uint32_t *const spm4 = (uint32_t *) 2156929028;
volatile int32_t *const spm5 = (int32_t *) 2156929032;
volatile uint32_t *const spm6 = (uint32_t *) 2157977600;
volatile uint32_t *const spm7 = (uint32_t *) 2157977604;
volatile int32_t *const spm8 = (int32_t *) 2157977608;
int main()
{
    while (1) {
        uint32_t v2;
        int32_t v3;
        
        while (1) {
            uint32_t v0;
            uint32_t v1;
            
            v0 = spm0[0];
            v1 = spm1[0];
            if (!(v0 == v1)) {
                break;
            }
        }
        v2 = spm0[0];
        v3 = spm2[v2];
        spm0[0] = (v2 + 1) % 3;
        while (1) {
            uint32_t v4;
            uint32_t v5;
            bool r6;
            bool v8;
            
            v4 = spm3[0];
            v5 = spm4[0];
            r6 = false;
            if ((v5 + 1) % 3 == v4) {
                r6 = false;
            } else {
                uint32_t v7;
                
                v7 = spm4[0];
                spm5[v7] = v3;
                spm4[0] = (v7 + 1) % 3;
                r6 = true;
            }
            v8 = r6;
            if (v8) {
                break;
            }
        }
        while (1) {
            uint32_t v9;
            uint32_t v10;
            bool r11;
            bool v13;
            
            v9 = spm6[0];
            v10 = spm7[0];
            r11 = false;
            if ((v10 + 1) % 3 == v9) {
                r11 = false;
            } else {
                uint32_t v12;
                
                v12 = spm7[0];
                spm8[v12] = v3;
                spm7[0] = (v12 + 1) % 3;
                r11 = true;
            }
            v13 = r11;
            if (v13) {
                break;
            }
        }
    }
    return 0;
}
