#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

bool isprime(int);
void arrange(int);

int n,arr[17],use[17]= {0};

int main()
{
    scanf("%d",&n);

    if(n%2==0)
    {
        arr[1]=1;
        use[1]=1;
        arrange(2);
    }

    else
        printf("None");

    return 0;
}

bool isprime(int x)
{
    int i;
    for(i=2; i<=sqrt(x); ++i)
    {
        if(x%i==0)
            return false;
    }
    return true;
}

void arrange(int cur)
{
    int i;
    if(cur==n+1&&isprime(arr[1]+arr[n]))
    {
        for(i=1; i<=n; i++)
        {
            printf("%d",arr[i]);
            printf(" ");
        }
        printf("\n");
    }
    else
    {
        for(i=2; i<=n; i++)
        {
            if(use[i]==0&&isprime(i+arr[cur-1]))
            {
                use[i]=1;
                arr[cur]=i;
                arrange(cur+1);
                use[i]=0;
            }
        }
    }

}
