#include <iostream>
#include <cstring>

using namespace std;

int n;
char know[110];
char x[1000][110];
char ch;

int main()
{
    int i,j,k,m,sum=0;
    bool flag,flag1;
    char str[1000];

    cin>>n;
    cin.get();

    cin.getline(str,1000,'\n');
    j=0;
    while(str[j]!='-'){j++;}
    j++;
    k=0;
    while(str[j]!='-'){
        know[k]=str[j];
        k++;
        j++;
    }

    for(i=0;i<n;++i){
    cin.getline(str,1000,'\n');
    j=0;
    while(str[j]!='-'){j++;}
    j++;
    k=0;
    while(str[j]!='-'){
        x[i][k]=str[j];
        k++;
        j++;
    }

    }
    for(i=0; i<n; ++i)
    {
        flag=false;
        if(strlen(x[i])!=strlen(know))
            continue;//×Ö·û´®³¤¶ÈÅÐ¶Ï

        j=0;
        while(x[i][j]!='\0')
        {
            if(x[i][j]==know[0])
            {
                k=(j+1)%strlen(x[i]);
                m=1;
                if(x[i][k]==know[m])
                {
                    flag1=true;
                    while(k!=j)
                    {
                        if(x[i][k]!=know[m])
                        {
                            flag1=false;
                            break;
                        }
                        k=(k+1)%strlen(x[i]);
                        m++;
                    }
                    if(flag1)
                        {flag=true;
                    break;}
                }


                k=j-1;
                if(k==-1)
                    k+=strlen(x[i]);
                m=1;
                if(x[i][k]==know[m])
                {
                    flag1=true;
                    while(k!=j)
                    {
                        if(x[i][k]!=know[m])
                        {
                            flag1=false;
                            break;
                        }
                        k--;
                        if(k==-1)
                            k+=strlen(x[i]);
                        m++;
                    }
                    if(flag1)
                        {
                            flag=true;break;
                        }
                }
            }
            j++;//Ê××ÖÄ¸ÅÐ¶Ï
        }
        if(flag)sum++;
    }

    cout<<sum;
    return 0;
}
