class arr{
private:
    int num[200];

public:
    arr();
    void maxnum();
};
#include <iostream>

using namespace std;

int n;

int main()
{
    arr a;
    a.maxnum();
    return 0;
}
arr::arr(){
    int i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>num[i];
    }
}

void arr::maxnum(){
    int m=num[0],i,j=0;
    for(i=1;i<n;i++){
        if(num[i]>m){m=num[i];j=i;}
    }
    cout<<m<<" "<<j+1;
}
