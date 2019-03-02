#include<stdio.h>
#include<cs50.h>
#include<math.h>
int i;
int get_change(float dollars);

int main(void)
{
    float dollars;
    do
    {
        dollars=get_float("Change owed = ");
    }
    while (dollars<0);
    printf("%i\n",get_change(dollars));
}
int get_change(float dollars)
{
    int cents=round(dollars*100);
    int coins=0;
    int denom[]={25,10,5,1};
    for(i=0;i<4;i++)
    {

    coins+=cents/denom[i];
    cents=cents%denom[i];
}
return (coins);
}