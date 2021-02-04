#include <iostream>

using namespace std;

int main()
{
    int year,month;
    cin>>year>>month;
    if(year<0||year>10000||month<1||month>12){cout<<"Error!";return 0;}

    switch(month){
    case 4:case 6:case 9 :case 11:
        cout<<"30";break;
    case 2:
        if (year%400==0||year%4==0&&year%100!=0) cout<<"29";
        else cout<<"28";break;
    default: cout<<"31";break;
    }

    return 0;
}
