#include <e-feldspar.h>
#include <e-hal.h>
#include <e-loader.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
off_t spm0 = 8192;
off_t spm1 = 8196;
off_t spm2 = 8200;
off_t spm3 = 8192;
off_t spm4 = 8196;
off_t spm5 = 8200;
off_t spm6 = 8192;
off_t spm7 = 8196;
off_t spm8 = 8200;
int main()
{
    e_epiphany_t group0;
    uint32_t _a1[1];
    uint32_t *a1 = _a1;
    uint32_t _a2[1];
    uint32_t *a2 = _a2;
    uint32_t _a3[1];
    uint32_t *a3 = _a3;
    uint32_t _a4[1];
    uint32_t *a4 = _a4;
    uint32_t _a5[1];
    uint32_t *a5 = _a5;
    uint32_t _a6[1];
    uint32_t *a6 = _a6;
    
    e_init(0);
    e_reset_system();
    e_open(&group0, 0, 0, 4, 4);
    e_reset_group(&group0);
    a1[0] = 0;
    e_fetch(&group0, 0, 0, spm0, a1, 0, 0, 0);
    a2[0] = 0;
    e_fetch(&group0, 0, 0, spm1, a2, 0, 0, 0);
    a3[0] = 0;
    e_fetch(&group0, 0, 1, spm3, a3, 0, 0, 0);
    a4[0] = 0;
    e_fetch(&group0, 0, 1, spm4, a4, 0, 0, 0);
    a5[0] = 0;
    e_fetch(&group0, 0, 2, spm6, a5, 0, 0, 0);
    a6[0] = 0;
    e_fetch(&group0, 0, 2, spm7, a6, 0, 0, 0);
    e_load("core0.srec", &group0, 0, 0, 1);
    e_load("core1.srec", &group0, 0, 1, 1);
    while (1) {
        int32_t _a7[3];
        int32_t *a7 = _a7;
        uint32_t v8;
        uint32_t r10;
        int32_t _a33[3];
        int32_t *a33 = _a33;
        uint32_t r34;
        uint32_t v57;
        
        for (v8 = 0; v8 < 3; v8++) {
            int32_t v9;
            
            fscanf(stdin, "%d", &v9);
            a7[v8] = v9;
        }
        r10 = 0;
        while (1) {
            uint32_t v11;
            uint32_t v16;
            uint32_t _a17[1];
            uint32_t *a17 = _a17;
            uint32_t v18;
            uint32_t _a19[1];
            uint32_t *a19 = _a19;
            uint32_t v20;
            uint32_t let21;
            uint32_t let22;
            uint32_t _a28[1];
            uint32_t *a28 = _a28;
            uint32_t let29;
            uint32_t let30;
            uint32_t let31;
            uint32_t let32;
            
            v11 = r10;
            if (!(v11 < 3)) {
                break;
            }
            while (1) {
                uint32_t _a12[1];
                uint32_t *a12 = _a12;
                uint32_t v13;
                uint32_t _a14[1];
                uint32_t *a14 = _a14;
                uint32_t v15;
                
                e_flush(&group0, 0, 0, spm0, a12, 0, 0, 0);
                v13 = a12[0];
                e_flush(&group0, 0, 0, spm1, a14, 0, 0, 0);
                v15 = a14[0];
                if (!((v15 + 1) % 3 == v13)) {
                    break;
                }
            }
            v16 = r10;
            e_flush(&group0, 0, 0, spm0, a17, 0, 0, 0);
            v18 = a17[0];
            e_flush(&group0, 0, 0, spm1, a19, 0, 0, 0);
            v20 = a19[0];
            let21 = -v16 + 3;
            let22 = -((v20 + 3 - v18) % 3) + 2;
            if (v20 + (let21 <= let22 ? let21 : let22) <= 3) {
                uint32_t let23;
                uint32_t let24;
                
                let23 = -v16 + 3;
                let24 = -((v20 + 3 - v18) % 3) + 2;
                e_fetch(&group0, 0, 0, spm2, a7, v20, v16, v16 + (let23 <=
                                                                  let24 ? let23 : let24) -
                        1);
            } else {
                uint32_t let25;
                uint32_t let26;
                uint32_t let27;
                
                e_fetch(&group0, 0, 0, spm2, a7, v20, v16, v16 + (-v20 + 3) -
                        1);
                let25 = -v20 + 3;
                let26 = -v16 + 3;
                let27 = -((v20 + 3 - v18) % 3) + 2;
                e_fetch(&group0, 0, 0, spm2, a7, 0, v16 + (-v20 + 3), v16 +
                        let25 + ((let26 <= let27 ? let26 : let27) - let25) - 1);
            }
            let29 = -v16 + 3;
            let30 = -((v20 + 3 - v18) % 3) + 2;
            a28[0] = (v20 + (let29 <= let30 ? let29 : let30)) % 3;
            e_fetch(&group0, 0, 0, spm1, a28, 0, 0, 0);
            let31 = -v16 + 3;
            let32 = -((v20 + 3 - v18) % 3) + 2;
            r10 = v16 + (let31 <= let32 ? let31 : let32);
        }
        r34 = 0;
        while (1) {
            uint32_t v35;
            uint32_t v40;
            uint32_t _a41[1];
            uint32_t *a41 = _a41;
            uint32_t v42;
            uint32_t _a43[1];
            uint32_t *a43 = _a43;
            uint32_t v44;
            uint32_t let45;
            uint32_t let46;
            uint32_t _a52[1];
            uint32_t *a52 = _a52;
            uint32_t let53;
            uint32_t let54;
            uint32_t let55;
            uint32_t let56;
            
            v35 = r34;
            if (!(v35 < 3)) {
                break;
            }
            while (1) {
                uint32_t _a36[1];
                uint32_t *a36 = _a36;
                uint32_t v37;
                uint32_t _a38[1];
                uint32_t *a38 = _a38;
                uint32_t v39;
                
                e_flush(&group0, 0, 2, spm6, a36, 0, 0, 0);
                v37 = a36[0];
                e_flush(&group0, 0, 2, spm7, a38, 0, 0, 0);
                v39 = a38[0];
                if (!(v37 == v39)) {
                    break;
                }
            }
            v40 = r34;
            e_flush(&group0, 0, 2, spm6, a41, 0, 0, 0);
            v42 = a41[0];
            e_flush(&group0, 0, 2, spm7, a43, 0, 0, 0);
            v44 = a43[0];
            let45 = -v40 + 3;
            let46 = (v44 + 3 - v42) % 3;
            if (v42 + (let45 <= let46 ? let45 : let46) <= 3) {
                uint32_t let47;
                uint32_t let48;
                
                let47 = -v40 + 3;
                let48 = (v44 + 3 - v42) % 3;
                e_flush(&group0, 0, 2, spm8, a33, v42, v40, v40 + (let47 <=
                                                                   let48 ? let47 : let48) -
                        1);
            } else {
                uint32_t let49;
                uint32_t let50;
                uint32_t let51;
                
                e_flush(&group0, 0, 2, spm8, a33, v42, v40, v40 + (-v42 + 3) -
                        1);
                let49 = -v42 + 3;
                let50 = -v40 + 3;
                let51 = (v44 + 3 - v42) % 3;
                e_flush(&group0, 0, 2, spm8, a33, 0, v40 + (-v42 + 3), v40 +
                        let49 + (let50 <= let51 ? let50 : let51) - let49 - 1);
            }
            let53 = -v40 + 3;
            let54 = (v44 + 3 - v42) % 3;
            a52[0] = (v42 + (let53 <= let54 ? let53 : let54)) % 3;
            e_fetch(&group0, 0, 2, spm6, a52, 0, 0, 0);
            let55 = -v40 + 3;
            let56 = (v44 + 3 - v42) % 3;
            r34 = v40 + (let55 <= let56 ? let55 : let56);
        }
        for (v57 = 0; v57 < 3; v57++) {
            int32_t v58;
            
            v58 = a33[v57];
            fprintf(stdout, "> %d\n", v58);
        }
    }
    e_close(&group0);
    e_finalize();
    return 0;
}
