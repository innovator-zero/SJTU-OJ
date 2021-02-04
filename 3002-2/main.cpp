#include <iostream>
#include <cstdio>

using namespace std;

int a[1005] = { 0 };
int n,num,sum=0;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if (a[num] == 0)sum++;
		a[num] ++;
	}
	printf("%d\n",sum);
	for (int i = 1; i <= 1000; i++)
	{
		if (a[i])printf("%d ", i);
	}
	return 0;
}
