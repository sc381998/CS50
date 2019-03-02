#include<stdio.h>
int main(void)
{
	int n,i,j,k;
    label:
	printf("Height of pyramid = ");
	scanf("%i",&n);
	if(n>=0&&n<=23)
	{
    	for(i=1;i<=n;i++)
    	{
     		for(j=0;j<n-i;j++)
     		printf(" ");
                for(k=0;k<=i;k++)
                printf("#");
           printf("\n");
    	}
     }
   else
    goto label;
}