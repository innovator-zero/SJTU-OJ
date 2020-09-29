#include <iostream>
#include <stdio.h>

using namespace std;

struct mouse
{
    int p,s,no;
};

int n,r;
mouse x[200000];
mouse tmp[200000];

void merge(int left,int mid,int right);

void mergeSort(int left,int right);

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int i,j;
    scanf("%d %d ", &n, &r);

    n*=2;
    for(i=0; i<n; ++i)
    {
      scanf("%d ", &x[i].p);
        x[i].no=i+1;
    }
    for(i=0; i<n; ++i)
    {
      scanf("%d ", &x[i].s);

    }

    for(j=0; j<r; ++j)
    {
        mergeSort(0,n-1);

        for(i=0; i<=n-2; i+=2)
        {
            if(x[i].s>x[i+1].s)
                x[i].p+=2;
            else if(x[i].s<x[i+1].s)
                x[i+1].p+=2;
            else
            {
                x[i].p++;
                x[i+1].p++;
            }
        }
    }

    mergeSort(0,n-1);
    for(i=0; i<n; ++i)
    {
      printf("%d ", x[i].no);
    }

    return 0;
}

void merge(int left,int mid,int right)
{
    int i=left,j=mid,k=0;

    while(i<mid&&j<=right)
        if(x[i].p>x[j].p||(x[i].p==x[j].p&&x[i].no<x[j].no))
          tmp[k++]=x[i++];
        else
          tmp[k++]=x[j++];

    while(i<mid)
      tmp[k++]=x[i++];
    while(j<=right)tmp[k++]=x[j++];

    for(i=0,k=left;k<=right;) x[k++]=tmp[i++];
}

void mergeSort(int left,int right)
{
    int mid=(left+right)/2;

    if(left==right)return;
    mergeSort(left,mid);
    mergeSort(mid+1,right);
    merge(left,mid+1,right);

}
