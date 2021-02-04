#include <iostream>
#include <cstring>

void list(char *[],int,int);
void ins(char [],int,char []);
void del(char [],int,int);
void quit(char *[],int);

using namespace std;

int main()
{
    char *a[101],str[101],cmd[150];
    int i=1,n,m,num=0,k,h;

    while(true)
    {
        a[i]=new char [2001];
        cin.getline(a[i],2001,'\n');
        if(strcmp(a[i],"******")==0)
        {
            delete []a[i];
            break;
        }
        i++;
        num++;
    }

    while(true)
    {
        cin>>cmd;
        if(cmd[0]=='q')
        {
            quit(a,num);
            break;
        }
        cin>>n>>m;
        switch(cmd[0])
        {
        case 'l':
        {
            if(n<=0||n>m||m>num)
            {
                cout<<"Error!"<<endl;
                break;
            }
            list(a,n,m);
            break;
        }
        case 'i':
        {
            cin.get();
            cin.getline(str,101,'\n');
            if(n<=0||n>num)
            {
                cout<<"Error!"<<endl;
                break;
            }
            k=strlen(a[n]);
            if(m>k+1||m<=0)
            {
                cout<<"Error!"<<endl;
                break;
            }
            ins(a[n], m, str);
            break;
        }
        case 'd':
        {
            cin>>h;
            if(n<=0||n>num)
            {
                cout<<"Error!"<<endl;
                break;
            }

            k=strlen(a[n]);
            if(m+h-1>k)
            {
                cout<<"Error!"<<endl;
                break;
            }
            del(a[n], m, h);
            break;
        }
        }
    }

    for(i=1; i<=num; ++i)
        delete a[i];
    return 0;
}
void list(char *a[],int n,int m)
{
    int i;
    for(i=n; i<=m; ++i) {cout<<a[i]<<'\n';}
}

void ins(char a[],int n,char str[])
{
    int c[2001],i,j=0,k=0;

    for(int i=n-1; i<=strlen(a); ++i,++j)
        c[j]=a[i];
    for(int i=n-1; i<=n-1+strlen(str)-1; ++i,++k)
        a[i]=str[k];

    for(int i=n-1+strlen(str); i<=n-1+strlen(str)+j-1; ++i)
        a[i]=c[i-(n-1+strlen(str))];

}

void del(char a[],int n,int m)
{
    int k=0;
    int len=strlen(a);
    for(int i=n-1+m; i<=len; ++i,++k)
        a[n-1+k]=a[i];
}

void quit(char *a[],int n)
{
    int i;
    for(i=1; i<=n; ++i) {cout<<a[i]<<'\n';}
}
