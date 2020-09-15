#include <stdio.h>
#include <string.h>
#include "aes.h"
#include "base64.h"

int main(int argc, char *argv[])
{
       if (argc<2) {
                printf("usage: encrypt 'string'\n");
                return 1;
       }
       char *inp = argv[1];
       if (strlen(inp)>32) {
                printf("input must be <= 32 char\n");
                return 1;
       }
       unsigned char buffer[64];       
       base64_decode(buffer, sizeof buffer, "InilahKuncinyaUntukEnkripsiPesan");
       struct AES_ctx ctx1;
       AES_init_ctx(&ctx1, buffer);
       base64_decode(buffer, sizeof buffer, "DanIniAdalahIVuntukEnkripsiPesan");
       AES_ctx_set_iv(&ctx1, buffer);

       unsigned char tmpinp[32];
       memset(tmpinp, 0, sizeof(tmpinp));
       strcpy((char*)tmpinp, inp);

       printf("INP: '%s'\n", tmpinp);

       AES_CBC_encrypt_buffer(&ctx1, tmpinp, 32);

       printf("INP: %s\n", tmpinp);

       base64_encode((char*)buffer, sizeof buffer, (unsigned char*)tmpinp, 32);
       printf("Buffer: %s\n", buffer);
      
       return 0;
}
