#include <iostream>

using namespace std;

int n;
struct num{
    int no,v;
}a[100005],b[100005],tmp[100005];

void mergea(int left,int mid,int right)
{
    int i=left,j=mid,k=0;

    while(i<mid && j<=right)
        if(a[i].v>a[j].v||(a[i].v==a[j].v && a[i].no<a[j].no))
          tmp[k++]=a[i++];
        else
          tmp[k++]=a[j++];

    while(i<mid)
      tmp[k++]=a[i++];
    while(j<=right)tmp[k++]=a[j++];

    for(i=0,k=left;k<=right;) a[k++]=tmp[i++];
}

void mergeSorta(int left,int right)
{
    int mid=(left+right)/2;

    if(left==right)return;
    mergeSorta(left,mid);
    mergeSorta(mid+1,right);
    mergea(left,mid+1,right);

}
void mergeb(int left,int mid,int right)
{
    int i=left,j=mid,k=0;

    while(i<mid && j<=right)
        if(b[i].v<b[j].v||(b[i].v==b[j].v&& b[i].no>b[j].no))
          tmp[k++]=b[i++];
        else
          tmp[k++]=b[j++];

    while(i<mid)
      tmp[k++]=b[i++];
    while(j<=right)tmp[k++]=b[j++];

    for(i=0,k=left;k<=right;) b[k++]=tmp[i++];
}

void mergeSortb(int left,int right)
{
    int mid=(left+right)/2;

    if(left==right)return;
    mergeSortb(left,mid);
    mergeSortb(mid+1,right);
    mergeb(left,mid+1,right);

}

int main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a[i].v;
        a[i].no=i;
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i].v;
        b[i].no=i;
    }
    mergeSorta(0,n-1);
    mergeSortb(0,n-1);

    int p=0,q=0;
    while(a[p].v==a[0].v)p++;
    while(b[q].v==b[0].v)q++;
    int minrange=max(a[0].no,b[0].no)-min(a[0].no,b[0].no)+1;
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            int range=max(a[i].no,b[j].no)-min(a[i].no,b[j].no)+1;
            if(range<minrange)minrange=range;
        }
    }
    cout<<minrange;
    return 0;
}
