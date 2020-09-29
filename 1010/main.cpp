#include <iostream>

using namespace std;

int main()
{
    int money=0,save=0,cost[12],i;
    for (i=0;i<12;++i)cin>>cost[i];

    for(i=0;i<12;++i){
        money+=300-cost[i];
        if (money<0){cout<<-1*(i+1);return 0;}
        save+=money/100*100;
        money-=money/100*100;
    }
    money+=save+save/5;
    cout<<money;
    return 0;
}
