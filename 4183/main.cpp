#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int nextPermutation(int a[],int x);

int m,n[10],k[10],num[10][1000];

int main()
{
    cin>>m;
    int i,j;
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
            if(nextPermutation(num[i],n[i])==1)
            {
                for(j=0; j<n[i]; ++j)
                {
                    cout<<num[i][j]<<' ';
                }
            }
            else
                for(j=n[i]-1; j>=0; --j)
                {
                    cout<<num[i][j]<<' ';
                }
        }

        printf("\n");
    }
    return 0;
}


int nextPermutation(int a[],int x)
{
    for (int i = x - 1; i >= 0; i--)
    {
        for (int j = x - 1; j>i; j--)
        {
            if (a[i]<a[j])
            {
                swap(a[i], a[j]);
                sort(a + i + 1, a+x);
                return 1;
            }
        }
    }
    return -1;
}

