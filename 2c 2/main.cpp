#include <iostream>
#include <cstdio>

using namespace std;

int n;
char b[5]={'a','e','i','o','u'};

int main()
{
    while(scanf("%d ",&n)!=EOF)
    {
        int i,j;
        char str[105];
        for(i=0;i<n;i++)
        {
            int a[5]={0};
            j=0;
            cin.getline(str,100);
            while(str[j]!='\0')
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
            for(j=0;j<5;j++)
            {
                printf("%c:%d\n",b[j],a[j]);
            }
            if(i!=n-1)printf("\n");
        }
    }
    return 0;
}
