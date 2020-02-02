#include <iostream>
#include <cstdio>

using namespace std;

int n;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int i,j;
        char str[105];
        for(i=0;i<n;i++)
        {
            int a[5]={0};
            j=0;
            scanf("%s",str);
            while(str[j]!='\n')
            {
                switch(str[j])
                {
                    case 'a':a[0]++;break;
                    case 'e':a[1]++;break;
                    case 'i':a[2]++;break;
                    case 'o':a[3]++;break;
                    case 'u':a[4]++;break;
                }
                j++;
            }
            printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n\n",a[0],a[1],a[2],a[3],a[4]);
        }
    }
    return 0;
}
