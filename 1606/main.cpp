#include <iostream>
#include <cstdio>
using namespace std;
struct site
{
    int x;
    int y;
};
bool flag[55][55];
site s[2502];
int num=0;
char Map[55][55];
int dir[4][2]= {-1,0,1,0,0,1,0,-1};
int record[55][55];
int cnt=0;
int ji=1;
int n,m,startx=1,starty=1;
void dfs(int x,int y);
int main()
{
    scanf("%d%d",&n,&m);
    int i,j,k;
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
        {
            cin>>Map[i][j];
            if (Map[i][j]=='.')
            {
                record[i][j]=1;
                startx=i;
                starty=j;
                ++cnt;
            }
            else if (Map[i][j]=='?')
            {
                record[i][j]=1;
                s[num].x=i;
                s[num++].y=j;
            }
        }
    dfs(startx,starty);
    if (cnt!=ji)
    {
        printf("Impossible");
        return 0;
    }
    for (i=0; i<num; ++i)
    {
        if (!flag[s[i].x][s[i].y])
            Map[s[i].x][s[i].y]='#';
    }
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
        {
            if (Map[i][j]=='.'||Map[i][j]=='?')
                record[i][j]=1;
        }
    for (i=0; i<num; ++i)
    {
        if (!flag[s[i].x][s[i].y])
            continue;
        ji=1;
        record[s[i].x][s[i].y]=0;
        dfs(startx,starty);
        if (ji==cnt)
        {
            printf("Ambiguous");
            return 0;
        }
        record[s[i].x][s[i].y]=1;
        for (k=1; k<=n; ++k)
            for (j=1; j<=m; ++j)
            {
                if (Map[k][j]=='.'||Map[k][j]=='?')
                    record[k][j]=1;
            }
    }
    for (i=0; i<num; ++i)
    {
        if (flag[s[i].x][s[i].y])
            Map[s[i].x][s[i].y]='.';
        else
            Map[s[i].x][s[i].y]='#';
    }
    for (i=1; i<=n; ++i)
    {
        for (j=1; j<=m; ++j)
            printf("%c",Map[i][j]);
        printf("\n");
    }
    return 0;
}
void dfs(int x,int y)
{
    for (int i=0; i<4; ++i)
    {
        int xx=x+dir[i][0];
        int yy=y+dir[i][1];
        record[x][y]=0;
        if (xx<1||xx>n||yy<1||yy>m||record[xx][yy]==0)
            continue;
        if (Map[xx][yy]=='.')
            ++ji;
        else
            flag[xx][yy]=true;
        dfs(xx,yy);
    }
    return;
}
