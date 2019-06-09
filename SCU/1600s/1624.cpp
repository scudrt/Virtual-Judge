#include <stdio.h>
int now;
int main()
{
    while ((now=getchar())!=EOF)
    {
        if (now=='\n')
            putchar('\n');
        else if (now != ' ')
            putchar((char)now);
    }
    return 0;
}
