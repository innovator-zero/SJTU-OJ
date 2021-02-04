#include <iostream>
#include <cstring>

using namespace std;

char ming[105],mi[105];
int main()
{
    int l,a,i,j,k,n;
    char tmp[105];
    cin>>ming>>mi;

    l=strlen(ming);
    for(a=2;a<=l;++a)
    {
        if(l%a==0)
        {
            k=0;
            for(i=0;i<a;++i)
            {
                for(j=0;j<l/a;++j)
                {
                    n=i+j*a;
                    tmp[k]=ming[n];
                    k++;
                }
            }
            tmp[k]='\0';
        }
        if(strcmp(tmp,mi)==0){cout<<a;return 0;}
    }
    cout<<"No Solution";
    return 0;
}
