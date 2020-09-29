#include <iostream>
#include <stdio.h>

using namespace std;

class linkstack
{
private:
    struct node
    {
        char data;
        node *next,*prev;
        node(const char &x,node *N=NULL,node *M=NULL)
        {
            data=x;
            next=N;
            prev=M;
        }
        node():next(NULL),prev(NULL) {}
        ~node() {};
    };

    node *head,*rear;
    int num;
public:
    linkstack();
    ~linkstack();
    void push();
    void pop();
    void top();
    bool match();
};

int n;

int main()
{
    int cmd;
    linkstack a;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>cmd;
        switch(cmd)
        {
        case 1:
            a.push();
            break;
        case 2:
            a.pop();
            break;
        case 3:
            a.top();
            break;
        case 4:
            if(a.match())
                printf("YES\n");
            else
                printf("NO\n");
            break;
        }
    }
    return 0;
}

linkstack::linkstack()
{
    head=rear=new node;
    num=0;
}

linkstack::~linkstack()
{
    node *tmp;
    while(head!=NULL)
    {
        tmp=head;
        head=head->next;
        delete tmp;
    }
}

void linkstack::push()
{
    node *tmp;
    char x;
    cin>>x;
    tmp=new node(x,head,NULL);
    head->prev=tmp;
    head=tmp;
    num++;
}

void linkstack::pop()
{
    if(num!=0)
    {
        node *tmp=head;
        head=head->next;
        delete tmp;
        num--;
    }
}

void linkstack::top()
{
    if(num!=0)
        printf("%c\n",head->data);
}

bool linkstack::match()
{
    if(num==0)
        return true;
    if(num%2!=0)
        return false;
    node *p=head,*q=rear->prev;
    while(q->next!=p)
    {
        if((p->data==')'&&q->data=='(')||(p->data==']'&&q->data=='[')||(p->data=='}'&&q->data=='{'))
        {
            q=q->prev;
            p=p->next;
        }
        else
            return false;

    }
    return true;

}
