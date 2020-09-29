#include <iostream>
#include <cstdio>
using namespace std;
int flag[67][27];
bool flag2=false;
bool record[27];
bool pass[27];
int num,n,m;
int flag3=false;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    if (ch=='\n')
        flag2=true;
    return f*x;
}
void dfs(int p,int step)
{
    if (flag3)
        return;
    if (step==num)
    {
        for (int i=1; i<=m; ++i)
        {
            bool flag4=false;
            for (int j=1; j<=n; ++j)
            {
                if ((record[j]&&flag[i][j]==1)||(!record[j]&&flag[i][j]==-1))
                {
                    flag4=true;
                    break;
                }
            }
            if (!flag4)
                return;
        }
        flag3=true;
        return;
    }
    for (int i=p+1; i<=n; ++i)
    {
        if (!record[i])
        {
            record[i]=true;
            dfs(i,step+1);
            record[i]=false;
        }
    }
}
int main()
{
    int t,i,j,k;
    scanf("%d",&t);
    for (k=0; k<t; ++k)
    {
        flag3=false;
        scanf("%d%d",&n,&m);
        for (i=1; i<=m; ++i)
            for (j=1; j<=n; ++j)
                flag[i][j]=0;
        for (i=1; i<=m; ++i)
        {
            flag2=false;
            while (!flag2)
            {
                int tmp=read();
                if (tmp<0)
                    flag[i][-tmp]=-1;
                else
                    flag[i][tmp]=1;
            }
        }
        for (num=1; num<=n; ++num)
        {
            if (flag3)
            {
                printf("Bingo!\n");
                break;
            }
            for (i=1; i<=n; ++i)
                record[i]=false;
            dfs(0,0);
        }
        if (!flag3)
            printf("Sigh...\n");
    }
    return 0;
}
