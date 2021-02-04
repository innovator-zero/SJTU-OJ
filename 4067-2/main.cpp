class intplus{
private:
    char num[50];
public:
    intplus();
    void plusone(int m);
    void printint();
};
#include <iostream>

using namespace std;

int n=0;

int main()
{
    intplus a;

    a.plusone(n);

    a.printint();

    return 0;
}
intplus::intplus(){

    cin>>num;

    while(num[n]!='\0'){
        n++;
    }
    n--;
}

void intplus::printint(){
    for(int i=0;i<=n;++i)
        cout<<num[i];
}

void intplus::plusone(int m){
    if (num[m]=='9'){
            if (m>0){num[m]='0';plusone(m-1);}
            else {num[m]='0';cout<<"1";}}
    else num[m]++;
}
