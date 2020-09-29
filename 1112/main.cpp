#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int no,level;
    bool know=false;
    friend bool operator<(node a,node b)
    {
        return a.level<b.level;
    }
};
node p[1005];
int n,k;
bool people[1005][1005];
priority_queue<node> q;

int main()
{
    cin>>n>>k;
    int x;
    for(int i=1; i<=n; i++)
    {
        cin>>p[i].level;
        p[i].no=i;
    }
    for(int i=0; i<k; i++)
    {
        cin>>x;
        p[x].know=true;
        q.push(p[x]);
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>people[i][j];
        }
    }
    while(!q.empty())
    {
        node tmp=q.top();
        q.pop();
        cout<<tmp.no<<"\n";
        for(int i=1; i<=n; i++)
        {
            if(people[tmp.no][i]==true && p[i].know==false)
            {
                p[i].know=true;
                q.push(p[i]);
            }
        }
    }

    return 0;
}
