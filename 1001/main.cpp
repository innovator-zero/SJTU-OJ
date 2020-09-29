#include <iostream>

using namespace std;

int l1,l2,n,m=0,k;
int main()
{
    cin>>l1>>l2>>n;
    l1+=l2;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        if(k<=l1)m++;
    }
    cout << m << endl;
    return 0;
}
