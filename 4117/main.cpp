#include <iostream>
#include <cstdio>

using namespace std;

#define LSON rt<<1
#define RSON rt<<1|1

const int maxn=1e6+7;
long long a[maxn];
long long segT[maxn<<2];  //有log n的空间用来保证最后的数，所以开4*n的空间比较好
long long tag[maxn<<2];
inline void pushup(int rt)
{
    segT[rt]=segT[LSON]+segT[RSON];
}
inline void pushDown(int rt,int ln,int rn)
{
    if(tag[rt])
    {
        segT[LSON]+=tag[rt]*ln;//+=的意义是不覆盖之前存在的标记
        segT[RSON]+=tag[rt]*rn;
        tag[LSON]+=tag[rt];
        tag[RSON]+=tag[rt];
        tag[rt]=0;
    }
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        segT[rt]=a[l];
        return;
    }
    int mid=(r+l)>>1;
    build(l,mid,LSON);
    build(mid+1,r,RSON);
    pushup(rt);
}

void Update(int L,int R,int C,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        segT[rt]+=(r-l+1)*C;
        tag[rt]+=C;//一定要打标记，因为下方儿子应该更新而没更新
        return;
    }
    int mid =(l+r)>>1;
    pushDown(rt,mid-l+1,r-mid);//把(所有祖先)他父亲的标记（全都）算上，进行更新，但是我只更新了我这次要更新的一个儿子
    if(L<=mid)Update(L,R,C,l,mid,LSON);
    if(R>mid)Update(L,R,C,mid+1,r,RSON);
    pushup(rt);

}
long long Query(int L,int R,int l,int r,int rt)//查询需要下推
{
    if(L<=l&&r<=R)
    {
        return segT[rt];
    }
    int mid=(l+r)>>1;
    pushDown(rt,mid-l+1,r-mid);
    long long ans=0;
    if(L<=mid)ans+=Query(L,R,l,mid,LSON);
    if(R>mid)ans+=Query(L,R,mid+1,r,RSON);
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,i;
    cin>>n>>m;

    for (i=1;i<=n;++i)
        cin>>a[i];
    build(1,n,1);
    for (i=0;i<m;++i)
    {
        char op;
        int l,r,v;
        cin>>op;
        if (op=='Q')
        {
            cin>>l>>r;
            cout<<Query(l,r,1,n,1)<<'\n';

        }
        else
        {
            cin>>l>>r>>v;
            Update(l,r,v,1,n,1);
        }
    }
    return 0;
}
