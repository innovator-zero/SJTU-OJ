#include <iostream>
#include <cstdio>

using namespace std;

int x,y,n;
int m[1200][1200]= {0};
int len=0,minlen=1000000;
void dfs(int,int);

int main()
{
    int i,j;
    scanf("%d %d %d",&x,&y,&n);
    for(int k=0; k<n; k++)
    {
        scanf("%d %d",&i,&j);
        m[i+600][j+600]=-1;
    }
    dfs(600,600);
    printf("%d",minlen);
    return 0;
}

void dfs(int a,int b)
{
    if(a==x+600&&b==y+600)
    {
        if(len<minlen)minlen=len;
    }
    if(m[a][b]==1)return;
    if(len>=minlen)return;
    m[a][b]=1;
    len++;
    if(m[a+1][b]==0&&a+1<1200)dfs(a+1,b);
    if(m[a-1][b]==0&&a-1>=0)dfs(a-1,b);
    if(m[a][b+1]==0&&b+1<1200)dfs(a,b+1);
    if(m[a][b-1]==0&&b-1>=0)dfs(a,b-1);
    m[a][b]=0;
    len--;
}

