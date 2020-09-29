#include <iostream>

using namespace std;

int main()
{
    int money,tax;
    cin>>money;
    money-=3500;
    if (money<=1500)tax=money*3/100;
    else if (money<=4500) tax=money/10-105;
    else if (money<=9000) tax=money/5-555;
    else if (money<=35000) tax=(money-9000)/4+1245;
    else if (money<=55000) tax=(money-35000)*3/10+7745;
    else if (money<=80000) tax=(money-55000)*35/100+13745;
    else tax=(money-80000)*45/100+22495;

    cout<<tax;
    return 0;
}
