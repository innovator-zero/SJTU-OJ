#include <iostream>


using namespace std;

int n,sodoku[20][9][9];

bool check(int);
bool checkline(int,int);
bool checkrow(int,int);
bool checksqu(int,int,int);

int main()
{
    int i,j,k;
    cin>>n;
    for(i=0; i<n; ++i)
    {
        for(j=0; j<9; ++j)
        {
            for(k=0; k<9; ++k)
            {
                cin>>sodoku[i][j][k];
            }
        }
    }

    for(i=0; i<n; ++i)
    {
        if(check(i)==1)cout<<"Right"<<'\n';
        else cout<<"Wrong"<<'\n';
    }
    return 0;
}

bool check(int x)
{
    int i,j;
    for(i=0;i<9;++i)
    {
        if(checkline(x,i)==0)
            return false;
        if(checkrow(x,i)==0)
            return false;
    }
    for(i=0;i<9;i+=3)
    {
        for(j=0;j<9;j+=3)
        {
            if(checksqu(x,i,j)==0)
                return false;
        }
    }
    return true;
}
bool checkline(int a,int b)
{
    int num[9]={0};
    int i,v;
    for(i=0;i<9;++i){
        v=sodoku[a][b][i]-1;
        num[v]=1;
    }
    for(i=0;i<9;++i)
    {
        if(num[i]==0)return false;
    }
    return true;
}
bool checkrow(int a,int b)
{
    int num[9]={0};
    int i,v;
    for(i=0;i<9;++i)
    {
        v=sodoku[a][i][b]-1;
        num[v]=1;
    }
    for(i=0;i<9;++i)
    {
        if(num[i]==0)return false;
    }
    return true;
}
bool checksqu(int a,int b,int c)
{
    int num[9]={0};
    int i,j,v;
    for(i=b;i<b+3;++i)
    {
        for(j=c;j<c+3;++j)
        {
            v=sodoku[a][i][j]-1;
            num[v]=1;
        }
    }
    for(i=0;i<9;++i)
    {
        if(num[i]==0)return false;
    }
    return true;
}
