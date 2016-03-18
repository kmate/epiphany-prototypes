#include <e-feldspar.h>
#include <e-hal.h>
#include <e-loader.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
off_t spm0 = 8192;
off_t spm1 = 8196;
off_t spm2 = 8192;
off_t spm3 = 8196;
off_t spm4 = 8192;
off_t spm5 = 8196;
int main()
{
    e_epiphany_t group0;
    bool _a1[1];
    bool *a1 = _a1;
    bool _a2[1];
    bool *a2 = _a2;
    bool _a3[1];
    bool *a3 = _a3;
    
    e_init(0);
    e_reset_system();
    e_open(&group0, 0, 0, 4, 4);
    e_reset_group(&group0);
    a1[0] = false;
    e_fetch(&group0, 0, 0, spm0, a1, 0, 0, 0);
    a2[0] = false;
    e_fetch(&group0, 0, 1, spm2, a2, 0, 0, 0);
    a3[0] = false;
    e_fetch(&group0, 0, 2, spm4, a3, 0, 0, 0);
    e_load("core0.srec", &group0, 0, 0, 1);
    e_load("core1.srec", &group0, 0, 1, 1);
    while (1) {
        int32_t _a4[4];
        int32_t *a4 = _a4;
        uint32_t v5;
        bool _a7[1];
        bool *a7 = _a7;
        int32_t _a8[4];
        int32_t *a8 = _a8;
        bool _a11[1];
        bool *a11 = _a11;
        uint32_t v12;
        
        for (v5 = 0; v5 < 4; v5++) {
            int32_t v6;
            
            fscanf(stdin, "%d", &v6);
            a4[v5] = v6;
        }
        e_fetch(&group0, 0, 0, spm1, a4, 0, 0, 3);
        a7[0] = true;
        e_fetch(&group0, 0, 0, spm0, a7, 0, 0, 0);
        while (1) {
            bool _a9[1];
            bool *a9 = _a9;
            bool v10;
            
            e_flush(&group0, 0, 2, spm4, a9, 0, 0, 0);
            v10 = a9[0];
            if (v10) {
                break;
            }
        }
        a11[0] = false;
        e_fetch(&group0, 0, 2, spm4, a11, 0, 0, 0);
        e_flush(&group0, 0, 2, spm5, a8, 0, 0, 3);
        for (v12 = 0; v12 < 4; v12++) {
            int32_t v13;
            
            v13 = a8[v12];
            fprintf(stdout, "> %d\n", v13);
        }
    }
    e_close(&group0);
    e_finalize();
    return 0;
}
