#include <stdio.h>
#include <string.h>
#include "aes.h"
#include "base64.h"

int main(int argc, char *argv[])
{
       if (argc<2) {
                printf("usage: decrypt 'string'\n");
                return 1;
       }
       char *inp = argv[1];
       unsigned char buffer[64];       
       base64_decode(buffer, sizeof buffer, "InilahKuncinyaUntukEnkripsiPesan");
       struct AES_ctx ctx1;
       AES_init_ctx(&ctx1, buffer);
       base64_decode(buffer, sizeof buffer, "DanIniAdalahIVuntukEnkripsiPesan");
       AES_ctx_set_iv(&ctx1, buffer);

       unsigned char tmpinp[33];
       memset(tmpinp, 0, sizeof(tmpinp));

       base64_decode(tmpinp, sizeof tmpinp, inp);
       AES_CBC_decrypt_buffer(&ctx1, tmpinp, 32);

       printf("\nSolution: %s\n", tmpinp);
      
       return 0;
}
