#include <openssl/evp.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

#define BlockLength 16
#define CIPHER EVP_aes_128_cbc()
#define KeyLength 16
#define IVLength 16

int main(int argc, char **argv)
{
	int inFd, outFd, decLen, readLen;
	unsigned char key[KeyLength+1], iv[IVLength+1];
	unsigned char readData[BlockLength+1];
	unsigned char *ct;
	EVP_CIPHER_CTX *ctx;

	inFd=open(argv[1], O_RDONLY);
	outFd=open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0644);

	memset(key,0,KeyLength+1);
	memset(iv,0,IVLength+1);
	memcpy(key,"0001020304050607",KeyLength);
	memcpy(iv,"0001020304050607",IVLength);

	ctx = malloc(sizeof(EVP_CIPHER_CTX));

	EVP_CIPHER_CTX_init(ctx);
	EVP_DecryptInit(ctx, CIPHER, key, iv);
	
	ct = malloc(EVP_CIPHER_CTX_block_size(ctx));

	while((readLen=read(inFd,readData, BlockLength)) > 0)
	{
		EVP_DecryptUpdate(ctx, ct, &decLen, readData, readLen);
		write(outFd, ct, decLen);
	}
	
	EVP_DecryptFinal(ctx, ct, &decLen);
	write(outFd, ct, decLen);

	close(inFd);
	close(outFd);
	free(ctx);
	free(ct);
}
