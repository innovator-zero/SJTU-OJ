#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int nextPermutation(int a[],int x);

int m,n[10],k[10],num[10][1000];

int main()
{
    cin>>m;
    int i,j,p;
    for(i=0; i<m; ++i)
    {
        cin>>n[i]>>k[i];
        for(j=0; j<n[i]; ++j)
        {
            cin>>num[i][j];
        }
    }

    for(i=0; i<m; ++i)
    {
        for(j=0; j<k[i]; ++j)
        {
            nextPermutation(num[i],n[i]);
        }
        for(p=0; p<n[i]; ++p)
        {
            cout<<num[i][p]<<' ';
        }
        printf("\n");
    }
    return 0;
}


int nextPermutation(int a[],int x)
{
    int i,j;
    for (i = x - 1; i >= 0; i--)
    {
        for (j = x - 1; j>i; j--)
        {
            if (a[i]<a[j])
            {
                swap(a[i], a[j]);
                sort(a + i + 1, a+x);
                return 1;
            }
        }
    }
    int tmp;
    for(i=0;i<x/2;++i)
    {
        tmp=a[i];
        a[i]=a[x-1-i];
        a[x-1-i]=tmp;
    }
    return -1;
}

