#include <iostream>
#include <stdio.h>

using namespace std;

bool match();

int n,numa=0,numb=0;
char a[1000000],b[1000000];

int main()
{
    int cmd;
    char x;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&cmd);
        switch(cmd)
        {
        case 1:
            scanf("%c",&x);
            scanf("%c",&x);
            a[numa]=x;
            numa++;
            break;
        case 2:
            if(numa!=0)
                numa--;
            break;
        case 3:
            if(numa!=0)
                printf("%c\n",a[numa-1]);
            break;
        case 4:
            if(numa==0)
                printf("YES\n");
            else if(numa%2==1)
                printf("NO\n");
            else if(match())
                printf("YES\n");
            else
                printf("NO\n");
            break;
        }
    }
    return 0;
}

bool match()
{
    int i;
    numb=0;
    for(i=0; i<numa; ++i)
    {
        switch(a[i])
        {
        case '(':
        case '[':
        case '{':
            b[numb]=a[i];
            numb++;
            break;
        default:
            if(numb==0)
                return false;
            else
            {
                numb--;
                if((b[numb]=='('&&a[i]!=')')||(b[numb]=='['&&a[i]!=']')||(b[numb]=='{'&&a[i]!='}'))
                    return false;
            }
        }
    }
    if(numb!=0)
        return false;
    else
        return true;
}
