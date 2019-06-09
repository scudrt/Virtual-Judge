//using hash list
#include <cstdio>
const int MAXN = 10000000;
const int MOD = MAXN+7;
int head[MAXN+7],next[MAXN+7],a[MAXN+7];
int n, m, X, Y, Z,s;
void add()
{
	int k=X%MOD;
	a[++s]=X;
	next[s]=head[k];
	head[k]=s;
}
bool ask()
{
	int now=head[X%MOD];
	while (now)
	{
		if (a[now]==X)
			return true;
		now=next[now];
	}
	return false;
}
int main()
{
    scanf("%d%d%d%d", &n, &X, &Y, &Z);
    for(int i = 1; i <= n; i++)
    {
    	X=(X+Y)%Z;
    	add();
    }
    scanf("%d%d%d%d", &m, &X, &Y, &Z);
    for(int i = 1; i <= m; i++)
    {
    	X=(X+Y)%Z;
    	if (ask())
    		printf("%d\n",i);
    }
    return 0;
}
