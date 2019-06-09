#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define memest(a,b) memset(a,b,sizeof(a))
#define INF 2100000000
#define maxn 16
bool usedx[maxn],usedy[maxn];
int map[maxn][maxn],lx[maxn],ly[maxn],slack[maxn],match[maxn];
int n;
bool dfs(int now)
{
	usedx[now]=1;
	for (int i=1;i<=n;++i)
	{
		if (usedy[i])
			continue;
		int temp=lx[now]+ly[i]-map[now][i];
		if (!temp)
		{
			usedy[i]=1;
			if (!match[i] || dfs(match[i]))
			{
				match[i]=now;
				return 1;
			}
		}
		else
			slack[i]=min(slack[i],temp);
	}
	return 0;
}
int main()
{
	while (~scanf("%d",&n))
	{
		for (int i=1;i<=n;++i)
		{
			lx[i]=ly[i]=match[i]=0;
			for (int j=1;j<=n;++j)
			{
				scanf("%d",&map[i][j]);
				lx[i]=max(map[i][j],lx[i]);
			}
		}
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=n;++j)
				slack[j]=INF;
			while (1)
			{
				for (int j=1;j<=n;++j)
					usedx[j]=usedy[j]=0;
				if (dfs(i))
					break;
				int d=INF;
				for (int j=1;j<=n;++j)
					if (!usedy[j])
						d=min(d,slack[j]);
				for (int j=1;j<=n;++j)
				{
					if (usedx[j])
						lx[j]-=d;
					if (usedy[j])
						ly[j]+=d;
					else
						slack[j]-=d;
				}
			}
		}
		int ans=0;
		for (int i=1;i<=n;++i)
			ans+=map[match[i]][i];
		printf("%d\n",ans);
	}
	return 0;
}
