#include <iostream>
#include <cstring>

using namespace std;

void Quit();
void Empty(int);
void Move(int,int);
void Pile(int,int);

int pos[25][25],box[25];
int n;

int main()
{

    int i,j,a,b;
    char cmd1[5],cmd2[5];
    cin>>n;
    for (i=0; i<n; ++i)
    {
        pos[i][0]=i;
    }
    for(i=0; i<n; ++i)
    {
        for(j=1; j<n; ++j)
        {
            pos[i][j]=-1;
        }
    }
    for(i=0; i<n; ++i)
    {
        box[i]=i;
    }

    cin>>cmd1;

    while(true)
    {
        if(strcmp(cmd1,"quit")==0)
        {
            Quit();
            return 0;
        }
        cin>>a>>cmd2>>b;
        if(box[a]==box[b]||a==b)
        {
            cin>>cmd1;
            continue;
        }
        if(strcmp(cmd1,"move")==0&&strcmp(cmd2,"over")==0)
        {
            Empty(a);
            Move(a,b);
        }
        if(strcmp(cmd1,"move")==0&&strcmp(cmd2,"onto")==0)
        {
            Empty(a);
            Empty(b);
            Move(a,b);
        }
        if(strcmp(cmd1,"pile")==0&&strcmp(cmd2,"over")==0)
        {
            Pile(a,b);
        }
        if(strcmp(cmd1,"pile")==0&&strcmp(cmd2,"onto")==0)
        {
            Empty(b);
            Pile(a,b);
        }
        cin>>cmd1;
    }
    return 0;
}

void Empty(int a)
{
    int i=0,k=box[a];
    while(pos[k][i]!=a)
    {
        i++;
    }
    i++;
    while(pos[k][i]!=-1)
    {
        box[pos[k][i]]=pos[k][i];
        pos[pos[k][i]][0]=pos[k][i];
        pos[k][i]=-1;
        i++;
    }
}

void Move(int a,int b)
{
    int i=0;
    while(pos[box[a]][i]!=a)
    {
        i++;
    }
    pos[box[a]][i]=-1;

    box[a]=box[b];
    i=0;
    while(pos[box[b]][i]!=-1)
    {
        i++;
    }
    pos[box[b]][i]=a;
}

void Pile(int a,int b)
{
    int i=0,j=0,k=box[a];
    while(pos[box[a]][i]!=a)
    {
        i++;
    }
    while(pos[box[b]][j]!=-1)
    {
        j++;
    }

    while(pos[k][i]!=-1)
    {
        pos[box[b]][j]=pos[k][i];
        pos[k][i]=-1;
        box[pos[box[b]][j]]=box[b];

        i++;
        j++;
    }
}

void Quit()
{
    int i,j;
    for(i=0; i<n; ++i)
    {
        cout<<i<<":";
        j=0;
        while(pos[i][j]!=-1)
        {
            cout<<" "<<pos[i][j];
            j++;
        }
        cout<<'\n';
    }
}
