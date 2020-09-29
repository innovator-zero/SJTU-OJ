#include <iostream>
#include <stdio.h>

using namespace std;

void push();
void pop();

int n,numa=0,numb=0;
char a[1000005],b[1000005];
bool flag[1000005];

int main()
{
    int cmd;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&cmd);
        switch(cmd)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
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
            else if(flag[numa])
                printf("YES\n");
            else
                printf("NO\n");
            break;
        }
    }
    return 0;
}

void push()
{
    char x;
    scanf("%c",&x);
    scanf("%c",&x);
    a[numa]=x;
    numa++;

    if(x=='('||x=='['||x=='{')
    {
        b[numb]=x;
        numb++;
    }
    else
    {
        if(numb==0)
        {
            flag[numa]=false;
            return;
        }
        else
        {
            numb--;
            if((b[numb]=='('&&x!=')')||(b[numb]=='['&&x!=']')||(b[numb]=='{'&&x!='}'))
            {
                flag[numa]=false;
                return;
            }
        }
    }
    if(numb!=0)
    {
        flag[numa]=false;
        return;
    }
    else
        flag[numa]=true;
}

void pop()
{
    if(numa==0)
        return;
    numa--;
    if(flag[numa+1])
    {
        if(a[numa]==')')
        {
            b[numb]='(';
            numb++;
        }
        if(a[numa]==']')
        {
            b[numb]='[';
            numb++;
        }
        if(a[numa]=='}')
        {
            b[numb]='{';
            numb++;
        }
    }
}
