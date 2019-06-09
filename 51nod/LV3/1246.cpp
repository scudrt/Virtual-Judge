#include<stdio.h>
main(){int n,k,c;scanf("%d%d%d",&n,&k,&c);printf("%d\n",c>k/n*n?c+n-k/(k/n+1):c);}
