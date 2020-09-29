#include<algorithm>
#include<iostream>
using namespace std;

int d[10005]={0};
int c[1005],w[1005];
int V,N;

int main()
{
    cin>>V>>N;
    for(int i=0;i<N;i++){
        cin>>c[i]>>w[i];
    }
    for (int i = 0; i < N; i++) {
        for (int v = c[i]; v <= V; v++){
            d[v] = max(d[v], d[v - c[i]] + w[i]);
        }
    }
    cout<<d[V]<<endl;

    return 0;
}
