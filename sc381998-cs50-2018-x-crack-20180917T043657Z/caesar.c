#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int main(int argc, char** argv)
{
    if(argc!=2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    int k= atoi(argv[1]);
    if(k<0)
   {
       printf("key must be positive\n");
       return 1;
   }
   string plaintext=get_string("plaintext: ");
   printf("ciphertext: ");
   for(int i=0,len=strlen(plaintext);i<len;i++)
   {
       if(islower(plaintext[i]))
       printf("%c",(plaintext[i]-'a'+k)%26+'a');
      else if(isupper(plaintext[i]))
       printf("%c",(plaintext[i]-'A'+k)%26+'A');
       else
       printf("%c",plaintext[i]);
   }
   printf("\n");
   }