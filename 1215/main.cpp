#include <iostream>

using namespace std;

int m,Size=0;
int a[20005];


void ins(int);
void del();
void down(int);

int main()
{
    int i,x;
    cin>>m;
    for(i=0; i<m; i++)
    {
        char s[10];
        cin>>s;
        switch(s[0])
        {
        case 'i':
            cin>>x;
            ins(x);
            break;
        case 'm':
            cout<<a[1]<<'\n';
            break;
        case 'd':
            del();
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

void del()
{
    a[1]=a[Size--];
    down(1);
}

void down(int hole)
{
    int child;
    int tmp=a[hole];

    for(; hole*2<=Size;hole=child)
    {
        child=hole*2;
        if(child!=Size && a[child+1]<a[child])
            child++;
        if(a[child]<tmp)a[hole]=a[child];
        else break;
    }
    a[hole]=tmp;
}
