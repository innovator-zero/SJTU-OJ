#include <iostream>
#include <cstring>

using namespace std;

struct node
{
    int num;
    node *next,*prev;
};

class Link
{
    friend void operator+(const Link &,const Link &);
private:
    node *head,*tail;
    int sum;

public:
    Link(const char*);
    ~Link();

};
int main()
{
    char s1[1000001],s2[1000001];
    cin>>s1>>s2;
    Link a(s1),b(s2);
    a+b;

    return 0;
}

Link::Link(const char* n="\0")
{
    head=new node;
    tail=new node;
    head->next=tail;
    head->prev=NULL;
    tail->prev=head;
    tail->next=NULL;

    int i=0;
    node *tmp;
    node *p=head;


    while(n[i]!='\0')
    {
        tmp=new node;
        tmp->num=n[i]-'0';
        tmp->prev=p;
        p->next=tmp;
        tmp->next=tail;
        tail->prev=tmp;
        p=tmp;
        i++;
    }


}

Link::~Link()
{
    node *p=head->next;
    while(p!=tail)
    {
        node *tmp=p;
        p=p->next;
        delete tmp;
    }
    delete head;
    delete p;

}

void operator+(const Link &o1,const Link &o2)
{
    int res=0;
    Link c;
    node *p=o1.tail->prev,*q=o2.tail->prev,*tmp;
    node *x=c.tail;
    while(p!=o1.head||q!=o2.head||(p==o1.head&&q==o2.head&&res==1))
    {
        tmp=new node;
        if(p==o1.head)p->num=0;
        if(q==o2.head)q->num=0;

        if(p->num+q->num+res>=10){tmp->num=p->num+q->num+res-10;res=1;}
        else {tmp->num=p->num+q->num+res;res=0;}
        //cout<<tmp->num;

        tmp->next=x;
        x->prev=tmp;
        tmp->prev=c.head;
        c.head->next=tmp;
        x=tmp;

        if(p!=o1.head)p=p->prev;
        if(q!=o2.head)q=q->prev;

    }
    p=c.head->next;
    while(p!=c.tail)
    {
        cout<<p->num;
        p=p->next;
    }
}

