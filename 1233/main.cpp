#include <iostream>

using namespace std;

struct edgeNode
{
    int end;
    edgeNode *next;

    edgeNode(int e,edgeNode *n=NULL){end=e;next=n;}
};

struct verNode
{
    edgeNode *head;

    verNode(edgeNode *h=NULL){head=h;}
};
verNode verlist[12];

void ins(int x,int y)
{
    verlist[x].head=new edgeNode(y,verlist[x].head);
}

int n,m,start,M,cou=0;
bool visited[12]={0};

void dfs(int,int);

int main()
{
    cin>>n>>m>>start>>M;
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        ins(a,b);
    }
    dfs(start,M);
    cout<<cou;
    edgeNode *p;
    for(int i=0;i<n;++i)
    {
        while((p=verlist[i].head)!=NULL)
        {
            verlist[i].head=p->next;
            delete p;
        }
    }
    return 0;
}

void dfs(int s,int length)
{
    if(length==0){cou++;return;}
    edgeNode *p=verlist[s].head;
    visited[s]=true;
    while(p!=NULL)
    {
        if(visited[p->end]==0)dfs(p->end,length-1);
        p=p->next;
    }
    visited[s]=false;
}
