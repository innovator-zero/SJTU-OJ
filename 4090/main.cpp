class date{
private:
    int year;
    int month;
    int day;

public:
    date();
    void afterdate(int num);
};

#include <iostream>

using namespace std;

int main()
{
    date d;
    int n;
    cin>>n;
    d.afterdate(n);
    return 0;
}

date::date(){
    char str[8];
    cin>>str;
    year=1000*(str[0]-'0')+100*(str[1]-'0')+10*(str[2]-'0')+str[3]-'0';
    month=10*(str[4]-'0')+str[5]-'0';
    day=10*(str[6]-'0')+str[7]-'0';
}

void date::afterdate(int num){
    int res=num;
    switch(month){
    case 4:case 6:case 9:case 11:
        res-=30-day;break;
    case 2:
        res-=28-day;
        if(year%400==0||(year%4==0&&year%100!=0)){res--;}break;
    default: res-=31-day;
    }
    day=0;
    while(res>0&&day==0){
        month=month%12+1;
        if(month==1)year++;
        if(year>9999){cout<<"out of limitation!";return;}
        switch(month){
        case 4:case 6:case 9:case 11:
            if(res>30)res-=30;
            else day=res;
            break;
        case 2:
            if(year%400==0||(year%4==0&&year%100!=0))
                if(res>29)res-=29;
                else day=res;
            else if(res>28)res-=28;
                else day=res;
            break;
        default:
            if(res>31)res-=31;
            else day=res;
            }
    }
    if(year<10)cout<<"000";
    else if(year<100)cout<<"00";
    else if (year<1000)cout<<"0";
    cout<<year;

    if(month<10)cout<<"0";
    cout<<month;

    if(day<10)cout<<"0";
    cout<<day;
}
