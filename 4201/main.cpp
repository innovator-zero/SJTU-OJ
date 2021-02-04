#include <iostream>
#include <cstring>

using namespace std;

struct School
{
    char name[7]; //学院名字
    double score; //加权总分
    int count;    //学生人数
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
    //根据学生信息，修改所在学院的相应信息
    void modify(char* id, double score, char* schoolName);
    void displayResult();  //输出
    ~Solution()
    {
        delete []schools;
    }

    // 可以根据设计自行添加所需成员


private:
    School *schools;    // 存放学院信息的指针
    unsigned int numOfSchool;  // 学院数量

// 可以根据设计自行添加所需成员

};

//main函数不要做任何修改
int main()
{
    int numOfPerson;
    cin >> numOfPerson;   //输入考试人数

    char id[7]; //准考证号
    int score;  //分数
    char schoolName[7]; //学院名字

    Solution solution(numOfPerson);

    for (int i = 0; i < numOfPerson; i++)
    {
        cin >> id >> score >> schoolName;    // 读取考试信息
        solution.modify(id, score, schoolName);  //根据学生信息，修改所在学院的相应信息
    }
    solution.displayResult();    //输出结果

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
