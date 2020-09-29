#include <iostream>

using namespace std;

int m,Size=0;
int a[20005];


void ins(int);
int fin(int);
void der(int,int);

int main()
{
    int i,x,v;
    cin>>m;
    for(i=0; i<m; i++)
    {
        char s[10];
        cin>>s>>x;
        switch(s[0])
        {
        case 'i':
            ins(x);
            break;
        case 'f':
            cout<<fin(x)<<'\n';
            break;
        case 'd':
            cin>>v;
            der(x,v);
            break;
        }
    }
    return 0;
}

void ins(int x)
{
    int hole=++Size;
    for( ; hole>1 && x<a[hole/2]; hole/=2)
        a[hole]=a[hole/2];
    a[hole]=x;
}

int fin(int x)
{
    int min = 200000000;
    int minindex = 1;
    int i;
    for (i=1 ; i <= Size; ++i)
    {
        if (a[i] > x && a[i] < min)
        {
            min = a[i];
            minindex = i;
        }
    }
    return minindex;
}

void der(int i,int v)
{
    a[i]-=v;
    int x=a[i];
    int hole=i;
    for(; hole>1 && x<a[hole/2]; hole/=2)
        a[hole]=a[hole/2];
    a[hole]=x;
}
