#include <stdio.h>
#include <openssl/hmac.h>

void spc_incremental_hmac(unsigned char *key, size_t keylen)
{
	int i;
	HMAC_CTX ctx;
	unsigned int len;
	unsigned char out[20];
	
	HMAC_Init(&ctx, key, keylen, EVP_sha1());
	HMAC_Update(&ctx, "fred", 4);
	HMAC_Final(&ctx, out, &len); 

	for(i=0; i<keylen; i++)
		printf("%02x",out[i]);
	printf("\n");

	HMAC_cleanup(&ctx);
}

void main()
{
	spc_incremental_hmac("THIS",4);
}
