#include <iostream>
#include <cstring>

using namespace std;

struct School
{
    char name[7]; //ѧԺ����
    double score; //��Ȩ�ܷ�
    int count;    //ѧ������
    int s;
    unsigned int r;
};

class Solution
{
public:
    Solution(int cnt)
    {
        numOfSchool = 0;
        schools = new School[cnt];
    }
    //����ѧ����Ϣ���޸�����ѧԺ����Ӧ��Ϣ
    void modify(char* id, double score, char* schoolName);
    void displayResult();  //���
    ~Solution()
    {
        delete []schools;
    }

    // ���Ը������������������Ա


private:
    School *schools;    // ���ѧԺ��Ϣ��ָ��
    unsigned int numOfSchool;  // ѧԺ����

// ���Ը������������������Ա

};

//main������Ҫ���κ��޸�
int main()
{
    int numOfPerson;
    cin >> numOfPerson;   //���뿼������

    char id[7]; //׼��֤��
    int score;  //����
    char schoolName[7]; //ѧԺ����

    Solution solution(numOfPerson);

    for (int i = 0; i < numOfPerson; i++)
    {
        cin >> id >> score >> schoolName;    // ��ȡ������Ϣ
        solution.modify(id, score, schoolName);  //����ѧ����Ϣ���޸�����ѧԺ����Ӧ��Ϣ
    }
    solution.displayResult();    //������

    return 0;
}

void Solution::modify(char* id, double score, char* schoolName)
{
    int j;
    for(j=0; schoolName[j]!='\0'; ++j)
    {
        if(schoolName[j]>='A'&&schoolName[j]<='Z')
        {
            schoolName[j]=schoolName[j]-'A'+'a';
        }
    }


    unsigned int i;
    bool found=false;
    for(i=0; i<numOfSchool; ++i)
    {
        if(strcmp(schools[i].name,schoolName)==0)
        {
            schools[i].count++;
            if(id[0]=='B')
                schools[i].score+=score/1.5;
            if(id[0]=='A')
                schools[i].score+=score;
            if(id[0]=='T')
                schools[i].score+=score*1.5;
            found=true;
            break;
        }
    }
    if(!found)
    {
        strcpy(schools[i].name,schoolName);
        schools[i].count=1;
        if(id[0]=='B')
            schools[i].score=score/1.5;
        if(id[0]=='A')
            schools[i].score=score;
        if(id[0]=='T')
            schools[i].score=score*1.5;
        numOfSchool++;
    }
}

void Solution::displayResult()
{
    cout<<numOfSchool<<endl;

    unsigned int i,j;
    bool flag;
    School tmp;

    for(i=0; i<numOfSchool; i++)
    {
        schools[i].s=int(schools[i].score);
    }
    for(i=0; i<numOfSchool; ++i)
    {
        flag=false;
        for(j=0; j<numOfSchool-i; ++j)
        {
            if(schools[j].s<schools[j+1].s)
            {
                tmp=schools[j];
                schools[j]=schools[j+1];
                schools[j+1]=tmp;
                flag=true;
            }
            else if(schools[j].s==schools[j+1].s)
            {
                if(schools[j].count>schools[j+1].count)
                {
                    tmp=schools[j];
                    schools[j]=schools[j+1];
                    schools[j+1]=tmp;
                    flag=true;
                }
                else if(schools[j].count==schools[j+1].count)
                {
                    if(strcmp(schools[j].name,schools[j+1].name)>0)
                    {
                        tmp=schools[j];
                        schools[j]=schools[j+1];
                        schools[j+1]=tmp;
                        flag=true;
                    }
                }
            }
        }
        if(!flag)
            break;
    }

    cout<<1<<" "<<schools[0].name<<" "<<schools[0].s<<" "<<schools[0].count<<endl;
    schools[0].r=1;
    for(i=1; i<numOfSchool; ++i)
    {

        if(schools[i].s<schools[i-1].s)
        {
            schools[i].r=i+1;
            cout<<schools[i].r<<" "<<schools[i].name<<" "<<schools[i].s<<" "<<schools[i].count<<endl;
        }
        else {
            schools[i].r=schools[i-1].r;
            cout<<schools[i].r<<" "<<schools[i].name<<" "<<schools[i].s<<" "<<schools[i].count<<endl;
        }

    }
}
