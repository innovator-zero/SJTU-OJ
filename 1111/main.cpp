#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char data;
    node *l, *r;
} *root;
node *creat(char a[], char b[], int n);
void out();
int L;

int main()
{
    char a[30], b[30];
    scanf("%s %s", a, b);
    L = strlen(a);
    root = creat(a, b, L);
    out();
    return 0;
}
node *creat(char a[], char b[], int n) // ����ǰ���������
{
    if(n <= 0)
        return NULL;

    node *p = new node;
    p->data = a[0];
    int i;
    for(i = 0; i < n; i++)
    {
        if(b[i] == a[0])
            break;
    }
    p->l = creat(a + 1, b, i);
    p->r = creat(a + i + 1, b + i + 1, n - i - 1);
    return p;
};

void out()
{
    int t = 0, i = 0, cou=0;
    node *s[1005], *q, *x;//ָ����������
    s[0] = root;
    x=new node;
    x->data=' ';

    while(t <= i && cou< L)
    {
        q = s[t++];
        if(q->data!=' ')
        {
            printf("%c ", q->data);
            cou++;
        }
        else
            printf("NULL ");

        if(q->l != NULL)
        {
            s[++i] = q->l;
        }
        else
        {
            s[++i] = x;
        }
        if(q->r != NULL)
        {
            s[++i] = q->r;
        }
        else
        {
            s[++i] = x;
        }
    }
}
