#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
int n,sum,k=1,s;
int main()
{
    while ((s=getchar())!='\n')
    {
        if (s>='A')
        {
            k=max(s-'A'+10,k);
            sum+=s-'A'+10;
        }
        else
        {
            k=max(k,s-'0');
            sum+=s-'0';
        }
    }
    for (int i=k;i<36;++i)
        if (sum%i==0)
        {
            printf("%d\n",i+1);
            return 0;
        }
    printf("No Solution\n");
    return 0;
}
