#include <e-feldspar.h>
#include <e-hal.h>
#include <e-loader.h>
#include <stdint.h>
#include <stdio.h>
off_t spm0 = 8192;
off_t spm1 = 8192;
off_t spm2 = 8192;
int main()
{
    e_epiphany_t group0;
    int32_t _a1[10];
    int32_t *a1 = _a1;
    uint32_t v2;
    int32_t _a4[10];
    int32_t *a4 = _a4;
    uint32_t v5;
    
    e_init(0);
    e_reset_system();
    e_open(&group0, 0, 0, 4, 4);
    e_reset_group(&group0);
    for (v2 = 0; v2 <= 9; v2++) {
        int32_t v3;
        
        fprintf(stdout, "Item %d> ", v2);
        fscanf(stdin, "%d", &v3);
        a1[v2] = v3;
    }
    e_fetch(&group0, 0, 0, spm0, a1, 0, 0, 9);
    e_load("core0.srec", &group0, 0, 0, 1);
    e_load("core1.srec", &group0, 0, 1, 1);
    e_flush(&group0, 0, 2, spm2, a4, 0, 0, 9);
    fprintf(stdout, "Output:");
    for (v5 = 0; v5 <= 9; v5++) {
        int32_t v6;
        
        v6 = a4[v5];
        fprintf(stdout, " %d", v6);
    }
    fprintf(stdout, "\n");
    e_close(&group0);
    e_finalize();
    return 0;
}
