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
off_t spm9 = 8192;
off_t spm10 = 8196;
off_t spm11 = 8200;
off_t spm12 = 8212;
off_t spm13 = 8216;
off_t spm14 = 8220;
off_t spm15 = 8192;
off_t spm16 = 8196;
off_t spm17 = 8200;
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
    uint32_t _a7[1];
    uint32_t *a7 = _a7;
    uint32_t _a8[1];
    uint32_t *a8 = _a8;
    uint32_t _a9[1];
    uint32_t *a9 = _a9;
    uint32_t _a10[1];
    uint32_t *a10 = _a10;
    uint32_t _a11[1];
    uint32_t *a11 = _a11;
    uint32_t _a12[1];
    uint32_t *a12 = _a12;
    
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
    a7[0] = 0;
    e_fetch(&group0, 0, 3, spm9, a7, 0, 0, 0);
    a8[0] = 0;
    e_fetch(&group0, 0, 3, spm10, a8, 0, 0, 0);
    a9[0] = 0;
    e_fetch(&group0, 0, 3, spm12, a9, 0, 0, 0);
    a10[0] = 0;
    e_fetch(&group0, 0, 3, spm13, a10, 0, 0, 0);
    a11[0] = 0;
    e_fetch(&group0, 1, 0, spm15, a11, 0, 0, 0);
    a12[0] = 0;
    e_fetch(&group0, 1, 0, spm16, a12, 0, 0, 0);
    e_load("core0.srec", &group0, 0, 0, 1);
    e_load("core1.srec", &group0, 0, 1, 1);
    e_load("core2.srec", &group0, 0, 2, 1);
    e_load("core3.srec", &group0, 0, 3, 1);
    while (1) {
        int32_t _a13[3];
        int32_t *a13 = _a13;
        uint32_t v14;
        uint32_t r16;
        int32_t _a39[3];
        int32_t *a39 = _a39;
        uint32_t r40;
        uint32_t v63;
        
        for (v14 = 0; v14 < 3; v14++) {
            int32_t v15;
            
            fscanf(stdin, "%d", &v15);
            a13[v14] = v15;
        }
        r16 = 0;
        while (1) {
            uint32_t v17;
            uint32_t v22;
            uint32_t _a23[1];
            uint32_t *a23 = _a23;
            uint32_t v24;
            uint32_t _a25[1];
            uint32_t *a25 = _a25;
            uint32_t v26;
            uint32_t let27;
            uint32_t let28;
            uint32_t _a34[1];
            uint32_t *a34 = _a34;
            uint32_t let35;
            uint32_t let36;
            uint32_t let37;
            uint32_t let38;
            
            v17 = r16;
            if (!(v17 < 3)) {
                break;
            }
            while (1) {
                uint32_t _a18[1];
                uint32_t *a18 = _a18;
                uint32_t v19;
                uint32_t _a20[1];
                uint32_t *a20 = _a20;
                uint32_t v21;
                
                e_flush(&group0, 0, 0, spm0, a18, 0, 0, 0);
                v19 = a18[0];
                e_flush(&group0, 0, 0, spm1, a20, 0, 0, 0);
                v21 = a20[0];
                if (!((v21 + 1) % 3 == v19)) {
                    break;
                }
            }
            v22 = r16;
            e_flush(&group0, 0, 0, spm0, a23, 0, 0, 0);
            v24 = a23[0];
            e_flush(&group0, 0, 0, spm1, a25, 0, 0, 0);
            v26 = a25[0];
            let27 = -v22 + 3;
            let28 = -((v26 + 3 - v24) % 3) + 2;
            if (v26 + (let27 <= let28 ? let27 : let28) <= 3) {
                uint32_t let29;
                uint32_t let30;
                
                let29 = -v22 + 3;
                let30 = -((v26 + 3 - v24) % 3) + 2;
                e_fetch(&group0, 0, 0, spm2, a13, v26, v22, v22 + (let29 <=
                                                                   let30 ? let29 : let30) -
                        1);
            } else {
                uint32_t let31;
                uint32_t let32;
                uint32_t let33;
                
                e_fetch(&group0, 0, 0, spm2, a13, v26, v22, v22 + (-v26 + 3) -
                        1);
                let31 = -v26 + 3;
                let32 = -v22 + 3;
                let33 = -((v26 + 3 - v24) % 3) + 2;
                e_fetch(&group0, 0, 0, spm2, a13, 0, v22 + (-v26 + 3), v22 +
                        let31 + ((let32 <= let33 ? let32 : let33) - let31) - 1);
            }
            let35 = -v22 + 3;
            let36 = -((v26 + 3 - v24) % 3) + 2;
            a34[0] = (v26 + (let35 <= let36 ? let35 : let36)) % 3;
            e_fetch(&group0, 0, 0, spm1, a34, 0, 0, 0);
            let37 = -v22 + 3;
            let38 = -((v26 + 3 - v24) % 3) + 2;
            r16 = v22 + (let37 <= let38 ? let37 : let38);
        }
        r40 = 0;
        while (1) {
            uint32_t v41;
            uint32_t v46;
            uint32_t _a47[1];
            uint32_t *a47 = _a47;
            uint32_t v48;
            uint32_t _a49[1];
            uint32_t *a49 = _a49;
            uint32_t v50;
            uint32_t let51;
            uint32_t let52;
            uint32_t _a58[1];
            uint32_t *a58 = _a58;
            uint32_t let59;
            uint32_t let60;
            uint32_t let61;
            uint32_t let62;
            
            v41 = r40;
            if (!(v41 < 3)) {
                break;
            }
            while (1) {
                uint32_t _a42[1];
                uint32_t *a42 = _a42;
                uint32_t v43;
                uint32_t _a44[1];
                uint32_t *a44 = _a44;
                uint32_t v45;
                
                e_flush(&group0, 1, 0, spm15, a42, 0, 0, 0);
                v43 = a42[0];
                e_flush(&group0, 1, 0, spm16, a44, 0, 0, 0);
                v45 = a44[0];
                if (!(v43 == v45)) {
                    break;
                }
            }
            v46 = r40;
            e_flush(&group0, 1, 0, spm15, a47, 0, 0, 0);
            v48 = a47[0];
            e_flush(&group0, 1, 0, spm16, a49, 0, 0, 0);
            v50 = a49[0];
            let51 = -v46 + 3;
            let52 = (v50 + 3 - v48) % 3;
            if (v48 + (let51 <= let52 ? let51 : let52) <= 3) {
                uint32_t let53;
                uint32_t let54;
                
                let53 = -v46 + 3;
                let54 = (v50 + 3 - v48) % 3;
                e_flush(&group0, 1, 0, spm17, a39, v48, v46, v46 + (let53 <=
                                                                    let54 ? let53 : let54) -
                        1);
            } else {
                uint32_t let55;
                uint32_t let56;
                uint32_t let57;
                
                e_flush(&group0, 1, 0, spm17, a39, v48, v46, v46 + (-v48 + 3) -
                        1);
                let55 = -v48 + 3;
                let56 = -v46 + 3;
                let57 = (v50 + 3 - v48) % 3;
                e_flush(&group0, 1, 0, spm17, a39, 0, v46 + (-v48 + 3), v46 +
                        let55 + (let56 <= let57 ? let56 : let57) - let55 - 1);
            }
            let59 = -v46 + 3;
            let60 = (v50 + 3 - v48) % 3;
            a58[0] = (v48 + (let59 <= let60 ? let59 : let60)) % 3;
            e_fetch(&group0, 1, 0, spm15, a58, 0, 0, 0);
            let61 = -v46 + 3;
            let62 = (v50 + 3 - v48) % 3;
            r40 = v46 + (let61 <= let62 ? let61 : let62);
        }
        for (v63 = 0; v63 < 3; v63++) {
            int32_t v64;
            
            v64 = a39[v63];
            fprintf(stdout, "> %d\n", v64);
        }
    }
    e_close(&group0);
    e_finalize();
    return 0;
}
