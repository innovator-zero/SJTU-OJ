#include <iostream>
#include <cstdio>

using namespace std;

int n;
int a[10005];
int Size=0;

void en(const int &x);
int de();
void Down(int hole);

int main()
{
    int i,m;
    long long ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        en(m);
    }
    while(Size>1)
    {
        int s=0;
        s+=de();
        s+=de();
        ans+=s;
        en(s);
    }
    printf("%lld",ans);
    return 0;
}

void en(const int &x)
{
    int hole=++Size;
    for(;hole>1 && x<a[hole/2];hole/=2)
        a[hole]=a[hole/2];
    a[hole]=x;
}

int de()
{
    int minitem=a[1];
    a[1]=a[Size--];
    Down(1);
    return minitem;
}

void Down(int hole)
{
    int child;
    int tmp=a[hole];

    for(;hole*2<=Size;hole=child)
    {
        child=hole*2;
        if(child!=Size && a[child+1]<a[child])
            child++;
        if(a[child]<tmp) a[hole]=a[child];
        else break;
    }
    a[hole]=tmp;
}
