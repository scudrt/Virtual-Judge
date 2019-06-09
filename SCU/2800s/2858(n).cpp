//sieve the numbers
#include <cmath>
#include <cstdio>
#include <cstring>
int n,t,k,prime[80001]={1,2};
bool isPrime[1000501]={0,0,1};
void preDeal()
{
    for (int i=3;i<=1000500;i+=2)
        isPrime[i]=1;
    for (int i=3;i<=1001;i+=2)
        if (isPrime[i])
            for (int j=i+i;j<=1000500;j+=i)
                isPrime[j]=0;
    for (int i=3;i<=1000500;i+=2)
        if (isPrime[i])
            prime[++prime[0]]=i;
}
int havefun()
{
    memset(isPrime,1,sizeof(isPrime));
    int s=n-1;
    for (int i=1;prime[i]<n;++i)
    {
        if (n%prime[i]==0)
            for (int j=prime[i];j<n;j+=prime[i])
                if (isPrime[j])
                {
                    isPrime[j]=0;
                    --s;
                }
    }
    return s;
}
int main()
{
    preDeal();
    while (scanf("%d%d",&n,&k)==2)
    {
        if (n==1)
        {
            printf("%d\n",k);
            continue;
        }
        int primes=havefun();
        int a=k/primes,b=k%primes,c;
        if (!b)
            printf("%d\n",a*n-1);
        else
        {
            for (int i=1;i<n;++i)
                if (isPrime[i])
                {
                    --b;
                    if (!b)
                    {
                        c=i;
                        break;
                    }
                }
            printf("%d\n",a*n+c);
        }
    }
    return 0;
}
