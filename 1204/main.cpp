#include <iostream>
#include <cstring>
using namespace std;

void List();
void Ins();
void Del();
void Quit();

char a[110][2200];
int num=0;

int main()
{
    char in[2200],cmd[6];

    while(true)
    {
        cin.getline(in,2200,'\n');
        if(strcmp(in,"******")==0)
            break;
        num++;
        strcpy(a[num],in);
    }

    while(true)
    {
        cin>>cmd;
        if(strcmp(cmd,"list")==0)
            List();
        if(strcmp(cmd,"ins")==0)
            Ins();
        if(strcmp(cmd,"del")==0)
            Del();
        if(strcmp(cmd,"quit")==0)
        {
            Quit();
            break;
        }
    }


return 0;
}

void List()
{
    int n1,n2,i;
    cin>>n1>>n2;

    if(n1<=0||n1>num||n2<=0||n2>num||n1>n2)
    {
        cout<<"Error!"<<'\n';
        return;
    }
    for(i=n1; i<=n2; ++i)
    {
        cout<<a[i]<<'\n';
    }
}

void Ins()
{
    int n,m,i,j=0,k=0,tmp[2001];
    char str[110];
    cin>>n>>m;
    cin.get();
    cin.getline(str,110,'\n');

    if(n<=0||n>num||m<=0||m>strlen(a[n])+1)
    {
        cout<<"Error!"<<'\n';
        return ;
    }

    for(int i=m-1; i<=strlen(a[n]); ++i,++j)
        tmp[j]=a[n][i];
    for(i=m-1; i<=m-1+strlen(str)-1; ++i,++k)
        a[n][i]=str[k];

    for(int i=m-1+strlen(str); i<=m-1+strlen(str)+j-1; ++i)
        a[n][i]=tmp[i-(m-1+strlen(str))];

}

void Del()
{
    int i,j,n,m;
    cin>>i>>j>>n;

    if(i<=0||i>num||j<=0||j>strlen(a[i])||n>strlen(a[i])-j+1)
    {
        cout<<"Error!"<<'\n';
        return;
    }
    m=j;
    while(a[i][m+n-1]!='\0')
    {
        a[i][m-1]=a[i][m+n-1];
        m++;
    }
    a[i][m]='\0';
}

void Quit()
{
    int i;
    for(i=1;i<=num;++i)
    {
        cout<<a[i]<<'\n';
    }
}
