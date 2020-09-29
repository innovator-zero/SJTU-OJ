#include <iostream>

using namespace std;

void fun(int);

long long m;
long long xxfs[100000];
int t,u,f,d;
int road[100000];
int main()
{
    int i;
    char ch;
    cin>>m>>t>>u>>f>>d;
    for(i=0; i<t; ++i)
    {
        cin>>ch;
        if(ch=='u')
            road[i]=0;
        if(ch=='f')
            road[i]=1;
        if(ch=='d')
            road[i]=2;
    }

    if(road[0]==0||road[0]==2)
        xxfs[0]=u+d;
    else
        xxfs[0]=2*f;

    for(i=1;i<t;++i)
    {
        fun(i);
    }
    i=0;
    while(xxfs[i]<=m)
    {
        i++;
    }

    if(i>t)i=t;

    cout<<i;
    return 0;
}

void fun(int n)
{
    if(road[n]==0||road[n]==2)
        xxfs[n]=xxfs[n-1]+u+d;
    else
        xxfs[n]=xxfs[n-1]+2*f;
}
