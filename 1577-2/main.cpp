#include <iostream>
#include <cstring>

using namespace std;

int n;
char know[110];
char x[1000][110];


int main()
{
    int i,j,k,m,sum=0;
    char str[1000];
    char s[210],tmp;

    cin>>n;
    cin.get();

    cin>>str;
    j=0;
    while(str[j]!='-')
    {
        j++;
    }
    j++;
    k=0;
    while(str[j]!='-')
    {
        know[k]=str[j];
        k++;
        j++;
    }

    for(i=0; i<n; ++i)
    {
        cin>>str;
        j=0;
        while(str[j]!='-')
        {
            j++;
        }
        j++;
        k=0;
        while(str[j]!='-')
        {
            x[i][k]=str[j];
            k++;
            j++;
        }

    }
    for(i=0; i<n; ++i)
    {
        if(strlen(x[i])!=strlen(know))
            continue;

        strcpy(s,x[i]);
        strcat(s,x[i]);
        if(strstr(s,know)!=NULL)
            sum++;
        else
        {
            m=strlen(s);
            for(k=0; k<m/2; k++)
            {
                tmp=s[k];
                s[k]=s[m-k-1];
                s[m-k-1]=tmp;
            }
            if(strstr(s,know)!=NULL)
                sum++;
        }
    }
    cout<<sum;
    return 0;
}
