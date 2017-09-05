#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <openssl/evp.h>
#include <fcntl.h>

#define CIPHER EVP_aes_128_cbc()
#define BlockLength 16
#define KeyLength 16
#define IVLength 16

void main(int argc, char *argv[])
{
	int inFd, outFd, readLen, decLen;
	unsigned char key[KeyLength+1], iv[IVLength+1], readData[BlockLength+1];
	unsigned char *pt;
	EVP_CIPHER_CTX *ctx;

	inFd=open(argv[1],O_RDONLY);
	outFd=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC, 0644);

	memset(key,0,KeyLength+1);
	memset(iv,0,IVLength+1);
	memcpy(key,"0001020304050607",KeyLength);
	memcpy(iv,"0001020304050607",IVLength);

	ctx=malloc(sizeof(EVP_CIPHER_CTX));
	pt=malloc(sizeof(EVP_CIPHER_CTX));

	EVP_CIPHER_CTX_init(ctx);
	EVP_DecryptInit(ctx,CIPHER,key,iv);

	while((readLen=read(inFd,readData,BlockLength))>0)
	{
		EVP_DecryptUpdate(ctx,pt,&decLen,readData,readLen);
		write(outFd,pt,decLen);
	}

	EVP_DecryptFinal(ctx,pt,&decLen);
	write(outFd,pt,decLen);

	close(inFd);
	close(outFd);
	free(ctx);
}



