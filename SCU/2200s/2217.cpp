#include <stdio.h>
int n;
int main()
{
    scanf("%d",&n);
    while (~scanf("%d",&n))
        printf("%d\n",n*4/5+1);
    return 0;
}
