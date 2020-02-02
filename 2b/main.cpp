#include <iostream>
#include <cstdio>

using namespace std;

int n,m;
bool a[1000005]= {0};

int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        int i,k;
        for(i=0; i<n; i++)
        {
            scanf("%d",&k);
            a[k+500000]=1;
        }
        for(i=1000004; i>=0,m>0; i--)
            if(a[i])
            {
                if(m==1)
                    printf("%d\n",i-500000);
                else
                    printf("%d ",i-500000);
                m--;
            }
    }

return 0;
}

