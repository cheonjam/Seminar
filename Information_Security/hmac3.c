#include <stdio.h>
#include <openssl/hmac.h>

void spc_incremental_hmac(unsigned char *key, size_t keyLen)
{
	int i;
	HMAC_CTX ctx;
	unsigned char out[20];
	unsigned int len;
	
	HMAC_Init(&ctx,key,keyLen,EVP_sha1());
	HMAC_Update(&ctx,"fred",4);
	HMAC_Final(&ctx,out,&len);

	for(i=0; i<len ; i++)
		printf("%02X",out[i]);
	printf("\n");

	HMAC_cleanup(&ctx);
}

void main()
{
	spc_incremental_hmac("THIS",4);
}
