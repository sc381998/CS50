#include<stdio.h>
int main(void)
{
	int n,i,j;
	label:
	printf("Height of pyramid : ");
	scanf("%d",&n);
	if(n<=23&&n>=0)
	{
   	 for(i=0;i<n;i++)
	 {
		for(j=0;j<2*n+2;j++)
		{
           if(j-i>=n+3)
           printf("");
           else if(j==n||j==n+1||i+j<(n-1))
           printf(" ");
           else
           printf("#");

     }printf("\n");
    }}
    else
    goto label;
}