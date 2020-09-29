#include <iostream>

using namespace std;

int a[105][105],bx[5],by[5];
bool visited[105][105];
int n,m,boxnum=0,sx,sy;
int minlen=10000;
int dirx[4]={1,-1,0,0};
int diry[4]={0,0,1,-1};

void dfs(int,int,int,int);

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            visited[i][j]=false;
            if(a[i][j]==1)
            {
                bx[boxnum]=i;
                by[boxnum]=j;
                boxnum++;
            }
            else if(a[i][j]==2)
            {
                sx=i;
                sy=j;
            }
        }
    }
    dfs(sx,sy,boxnum,0);
    return 0;
}

void dfs(int x,int y,int num,int length)
{
    if(a[x][y]==1)
    {
        visited[x][y]=true;
        num--;
        if(num==0)
        {
            if(length<minlen)minlen=length;
            return;
        }
        else{
            for(int i=0;i<4;i++)
        {
            if(x+dirx[i]>=0 && x+dirx[i]<n && y+diry[i]>=0 && y+diry[i]<m && visited[x+dirx[i]][y+diry[i]]==false)
                dfs(x+dirx[i],y+diry[i],num-1,length+1);
        }
        }
    }
    else{
        for(int i=0;i<4;i++)
        {
            if(x+dirx[i]>=0 && x+dirx[i]<n && y+diry[i]>=0 && y+diry[i]<m && a[x+dirx[i]][y+diry[i]]!=-1 && visited[x+dirx[i]][y+diry[i]]==false)
                dfs(x+dirx[i],y+diry[i],num,length+1);
        }
    }
}
