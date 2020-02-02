#include <iostream>
#include <cstdio>

using namespace std;

int a[3005],b[10005]= {0};
int n,m;

int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        int i,j;

        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0; i<n; i++)
        {
            for(j=i+1; j<n; j++)
            {
                b[a[i]+a[j]]++;
            }
        }
        i=0;
        j=10000;
        while(i<m && j>0)
        {
            while(b[j]&&i<m)
            {
                if(i==m-1)
                    printf("%d",j);
                else
                    printf("%d ",j);
                i++;
                b[j]--;
            }
            j--;
        }
        printf("\n");
    }
    return 0;
}
