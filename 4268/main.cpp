#include <iostream>

using namespace std;

class joseph{
private:
    int n;
    int m;
    int *num;
public:
    joseph(int n1,int m1);
    void simulate();
    ~joseph(){delete []num;};
};

int main()
{
    int inputn,inputm;
    cin>>inputn>>inputm;

    joseph obj(inputn,inputm);

    obj.simulate();
    return 0;
}

joseph::joseph(int n1,int m1){
    n=n1;
    m=m1;
    num=new int[n];
    for(int i=0;i<n;++i){
        num[i]=i+1;
    }
}

void joseph::simulate(){
    int i=0,j,size1=n;
    while(size1>1){
        i=(i+m-1)%size1;
        size1--;
        for(j=i;j<size1;++j){
            num[j]=num[j+1];
        }
}
    cout<<num[0];
}
