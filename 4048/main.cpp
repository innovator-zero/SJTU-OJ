#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int Size=1e5+5;

int n,l[Size],d[Size],a[Size]={0};

int main()
{
    int i,j,maxl=0,cost,mcost=20000000,num;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&l[i]);
        a[l[i]]++;
        if(l[i]>maxl)maxl=l[i];
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&d[i]);
    }

    for(i=maxl;i>0;i--)
    {
        if(!a[i])continue;
        if(a[i]>n/2){printf("0");return 0;}
        num=n;
        cost=0;
        int k=0,b[Size];
        for(j=0;j<n;j++)
        {
            if(l[j]==i)continue;
            if(l[j]>i)
            {
                num--;
                cost+=d[j];
            }
            else if(l[j])
            {
                b[k]=d[j];
                k++;
            }
        }
        sort(b,b+k);
        j=0;
        while(a[i]<=num/2)
        {
            cost+=b[j];
            j++;
            num--;
        }
        if(cost<mcost)mcost=cost;
    }
    printf("%d",mcost);
    return 0;
}
