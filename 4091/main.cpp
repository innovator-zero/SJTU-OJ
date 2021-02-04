#include <iostream>

using namespace std;

class Newtime{
    friend istream& operator>>(istream &in ,Newtime& obj);
    friend ostream& operator<<(ostream &os,const Newtime& obj);
private:
    int hour,minute,second;
    void change();
public:
    Newtime& operator+=(const Newtime& t1);
    Newtime& operator-=(const Newtime& t1);
    Newtime& operator++();
    Newtime& operator--();
    Newtime operator++(int x);
    Newtime operator--(int x);
};
int main()
{
    Newtime time1,time2;
    cin>>time1;
    cin>>time2;

    time1 += (time2++);
    cout<<time1;
    time1 -= time2;
    cout<<time1;
    ++time2;
    cout<<time2;
    time2 += (time1--);
    cout<<time2;
    --time1;
    cout<<time1;
    time2 -= time1;
    cout<<time2;

    return 0;
}
void Newtime::change(){
    while(second>=60){
        second-=60;
        minute++;
    }
    while(second<0){
        second+=60;
        minute--;
    }
    while(minute>=60){
        minute-=60;
        hour++;
    }
    while(minute<0){
        minute+=60;
        hour--;
    }
    while(hour>=24){
        hour-=24;
    }

    while(hour<0){
        hour+=24;
    }

}

istream& operator>>(istream &in ,Newtime& obj){
    in>>obj.hour>>obj.minute>>obj.second;
    obj.change();
    return in;
}

ostream& operator<<(ostream &os,const Newtime& obj){
    if(obj.hour<10){
        os<<"0"<<obj.hour<<":";
    }
    else os<<obj.hour<<":";

    if(obj.minute<10){
        os<<"0"<<obj.minute<<":";
    }
    else os<<obj.minute<<":";

    if(obj.second<10){
        os<<"0"<<obj.second<<endl;
    }
    else os<<obj.second<<endl;

    return os;
}

Newtime& Newtime::operator+=(const Newtime& t1){
    second+=t1.second;
    minute+=t1.minute;
    hour+=t1.hour;
    change();
    return *this;
}

Newtime& Newtime::operator-=(const Newtime& t1){
    second-=t1.second;
    minute-=t1.minute;
    hour-=t1.hour;
    change();
    return *this;
}

Newtime& Newtime::operator++(){
    second++;
    change();
    return *this;
}

Newtime& Newtime::operator--(){
    second--;
    change();
    return *this;
}

Newtime Newtime::operator--(int x){
    Newtime tmp=*this;
    second--;
    return tmp;
}

Newtime Newtime::operator++(int x){
    Newtime tmp=*this;
    second++;
    return tmp;
}
