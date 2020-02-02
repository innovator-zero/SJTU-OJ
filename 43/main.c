#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delchar(char *str,char c);

int main()
{
    char a[100],c;
    gets(a);
    scanf("%c",&c);
    delchar(a,c);
    printf("%s",a);
    return 0;
}

void delchar(char *str,char c)
{
    int i=0;
    while(str[i]!='\0'){
        if(str[i]==c)
        {
            int j=i;
            while(str[j]!='\0')
            {
                str[j]=str[j+1];
                j++;
            }
        }
        else i++;
    }
}
