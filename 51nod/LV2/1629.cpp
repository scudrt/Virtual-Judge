//math problem
#include <cstdio>
#include <cmath>
#define PI 3.1415926535
int main()
{
	double s;
	scanf("%lf",&s);
	printf("%.6lf",s*sqrt(s/(8*PI))/3);
	return 0;
}
