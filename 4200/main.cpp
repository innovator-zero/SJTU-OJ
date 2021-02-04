#include <iostream>
#include <cstring>

using namespace std;

class Person
{
public:
    Person() {}
    bool isLegal(); //�ж������Ƿ����������true,���򷵻�false
    void read();    //���������Ϣ
    int year,month,day;
    // ���Ը������������������Ա


    char name[7];        //����
    char birthday[11];   //����

    // ���Ը������������������Ա

};
class Solution
{
public:
    Solution()
    {
        count = 0;
    }
    void regPerson(const Person &person);//ͳ����Ч�����������Լ������������곤����
    void displayResult();  //��������Ϣ
    void eldest (const Person &person);
    void youngest(const Person &person);

// ���Ը������������������Ա

private:
    char eldestName[7]; //���곤�˵�����
    char eldestBirthday[11]; //���곤�˵�����
    char youngestName[7]; //�������˵�����
    char youngestBirthday[11];  //�������˵�����
    int count;   //��Ч��������
    int eyear,emonth,eday;
    int yyear,ymonth,yday;
};
//main������Ҫ���κ��޸�
int main()
{
    Solution solution;
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        Person person;
        person.read();
        if (person.isLegal())
        {
            solution.regPerson(person);
        }
    }
    solution.displayResult();

    return 0;
}

void Person::read()
{
    cin>>name>>birthday;
    year=(birthday[0]-'0')*1000+(birthday[1]-'0')*100+(birthday[2]-'0')*10+birthday[3]-'0';
    month=(birthday[5]-'0')*10+birthday[6]-'0';
    day=(birthday[8]-'0')*10+birthday[9]-'0';
}

bool Person::isLegal()
{
    if (year<1898||year>2018)
        return false;
    if(year==2018&&month==12&&day>20)
        return false;
    if(year==1898&&month<12)
        return false;
    if(year==1898&&month==12&&day<=20)
        return false;
    return true;
}

void Solution::regPerson(const Person &person)
{
    if(count==0)
    {
        eldest(person);
        youngest(person);
    }
    else
    {
        if(person.year>yyear){youngest(person);}
        if(person.year==yyear){
            if (person.month>ymonth){youngest(person);}
            else if(person.month==ymonth&&person.day>yday){youngest(person);}
        }
        if(person.year<eyear){eldest(person);}
        if(person.year==eyear){
            if (person.month<emonth){eldest(person);}
            else if(person.month==emonth&&person.day<eday){eldest(person);}
        }

    }
    count++;
}

void Solution::eldest(const Person &person)
{
    strcpy(eldestName,person.name);
    strcpy(eldestBirthday,person.birthday);
    eyear=person.year;
    emonth=person.month;
    eday=person.day;
}

void Solution::youngest(const Person &person)
{
    strcpy(youngestName,person.name);
    strcpy(youngestBirthday,person.birthday);
    yyear=person.year;
    ymonth=person.month;
    yday=person.day;
}

void Solution::displayResult()
{
    cout<<count<<" "<<eldestName<<" "<<youngestName;
}
