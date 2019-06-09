#include <stdio.h>
int s,ch;
int main()
{
    while ((ch=getchar())!=EOF && ch!='\n')
        s+=ch-48;
    printf("%d\n",s);
    return 0;
}
