#include <iostream>
#include <stdio.h>

using namespace std;

bool train();
int t,n,m;
int out[1005],station[1005];

int main()
{
    int i,j;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d%d",&n,&m);
        for(j=0; j<n; j++)
        {
            scanf("%d",&out[j]);
        }
        if(train())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

bool train()
{
    int i,j,k;
    i=j=k=0;
    while(i<n)
    {
        if(i==out[j])
        {
            i++;
            j++;
        }
        else
        {
            while(k>0&&station[k-1]==out[j])
            {
                k--;
                j++;
            }
            if(k==m)
                return false;
            station[k]=i;
            k++;
            i++;
        }
    }
    while(k>0)
    {
        if(station[k-1]==out[j])
        {
            j++;
            k--;
        }
        else
            return false;
    }
    return true;
}
