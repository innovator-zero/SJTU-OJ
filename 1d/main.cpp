#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char str[100005];
    while(gets(str))
    {
        int a[26]= {0};
        int j,len;
        len=strlen(str);
        for(j=0;j<len;j++)
        {
            if(str[j]>='a'&&str[j]<='z')
                a[str[j]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            printf("%c:%d\n",'a'+i,a[i]);
        }
        printf("\n");
    }
    return 0;
}
