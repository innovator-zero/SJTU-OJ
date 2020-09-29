#include <iostream>
#include <cstdio>
const int maxn=5e5+7;
int num[maxn];
int maxi=1;
int cnt;
bool flag[maxn];
int parent[maxn];
using namespace std;
int Find(int x)
{
    if (parent[x]<0)
        return x;
    else
        return parent[x]=Find(parent[x]);
}
void uni(int x,int y)
{
    int a=Find(x),b=Find(y);
    if (a<b)
    {
        parent[a]+=parent[b];
        parent[b]=a;
    }
    else
    {
        parent[b]+=parent[a];
        parent[a]=b;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,i,a,b,k;
    cin>>n>>m;
    char ch;
    cnt=n;
    for (i=1; i<=n; ++i)
        parent[i]=-1;
    num[1]=n;
    for (k=0; k<m; ++k)
    {
        cin>>ch;
        if (ch=='C')
        {
            cin>>a>>b;
            int t1=Find(a),t2=Find(b);
            if (t1==t2||flag[t1]||flag[t2])
                continue;
            num[-parent[t1]]--;
            num[-parent[t2]]--;
            int tmp=-(parent[t1]+parent[t2]);
            if (maxi<tmp)
                maxi=tmp;
            num[tmp]++;
            --cnt;
            uni(t1,t2);
        }
        else if (ch=='D')
        {
            cin>>a;
            int t=Find(a);
            if (flag[t])
                continue;
            num[-parent[t]]--;
            --cnt;
            flag[t]=true;
        }
        else
        {
            cin>>a;
            if (cnt<a)
                cout<<'0'<<'\n';
            else
                for (i=maxi; i>=1; --i)
                {
                    if (num[i]==0)
                        continue;
                    else
                    {
                        if (num[i]>=a)
                        {
                            cout<<i<<'\n';
                            break;
                        }
                        else
                            a-=num[i];
                    }
                }
        }
    }
    return 0;
}
