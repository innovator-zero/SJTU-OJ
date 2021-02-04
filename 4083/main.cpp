#include <iostream>
#include <cstring>
using namespace std;

struct student
{
    char id[10];
    char name[30];
    int score;
};

void add();
void showall();
void idsearch();
void namesearch();
void idsort();
void scoresort();

student stu[10000];
int n=0;

int main()
{
    int input;
    while(true)
    {

        cin>>input;

        switch(input)
        {
        case 1:
            add();
            break;
        case 2:
            showall();
            break;
        case 3:
            idsearch();
            break;
        case 4:
            namesearch();
            break;
        case 5:
            idsort();
            break;
        case 6:
            scoresort();
            break;
        case 7:
        {
            cout<<"END";
            return 0;
        }
        }
    }
    return 0;
}
void add()
{
    char inputid[10],inputname[30];
    int inputscore;
    cin>>inputid>>inputname>>inputscore;
    int i;

    for(i=0; i<n; ++i)
    {
        if(strcmp(stu[i].id,inputid)==0)
        {
            cout<<"FAILED"<<endl;
            return;
        }
    }

    n++;

    strcpy(stu[n-1].id,inputid);
    strcpy(stu[n-1].name,inputname);
    stu[n-1].score=inputscore;

    cout<<"SUCCESS"<<endl;
    return;

}

void showall()
{
    if(n!=0)
    {
        for(int i=0; i<n; ++i)
        {
            cout<<stu[i].id<<" "<<stu[i].name<<" "<<stu[i].score<<endl;
        }
    }
}

void idsearch()
{
    char inputid[10];
    cin>>inputid;
    for(int i=0; i<n; ++i)
    {
        if(strcmp(inputid,stu[i].id)==0)
        {
            cout<<stu[i].id<<" "<<stu[i].name<<" "<<stu[i].score<<endl;
        }
    }
}

void namesearch()
{
    char inputname[30];
    cin>>inputname;
    for(int i=0; i<n; ++i)
    {
        if(strcmp(inputname,stu[i].name)==0)
        {
            cout<<stu[i].id<<" "<<stu[i].name<<" "<<stu[i].score<<endl;
        }
    }
}

void idsort()
{
    int i,j;
    student tmp;
    bool flag;

    student stu1[10000];
    for(i=0; i<n; ++i)
    {
        stu1[i]=stu[i];
    }

    for(i=1; i<n; ++i)
    {
        flag=false;
        for(j=0; j<n-i; ++j)
        {
            if(strcmp(stu1[j].id,stu1[j+1].id)>0)
            {
                tmp=stu1[j];
                stu1[j]=stu1[j+1];
                stu1[j+1]=tmp;
                flag=true;
            }
        }
        if(!flag)
            break;
    }
    for(i=0; i<n; ++i)
    {
        cout<<stu1[i].id<<" "<<stu1[i].name<<" "<<stu1[i].score<<endl;
    }

}

void scoresort()
{
    int i,j;
    student tmp;
    bool flag;

    student stu1[10000];
    for(i=0; i<n; ++i)
    {
        stu1[i]=stu[i];
    }

    for(i=1; i<n; ++i)
    {
        flag=false;
        for(j=0; j<n-i; ++j)
        {
            if(stu1[j].score<stu1[j+1].score)
            {
                tmp=stu1[j];
                stu1[j]=stu1[j+1];
                stu1[j+1]=tmp;
                flag=true;
            }
        }
        if(!flag)
            break;
    }
    for(i=0; i<n; ++i)
    {
        cout<<stu1[i].id<<" "<<stu1[i].name<<" "<<stu1[i].score<<endl;
    }

}
