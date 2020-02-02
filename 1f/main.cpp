#include<map>
#include<stack>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define rep(i,j,k) for (int i = j; i <= k; i++)
#define per(i,j,k) for (int i = j; i >= k; i--)
#define loop(i,j,k) for (int i = j;i != -1; i = k[i])
#define lson x << 1, l, mid
#define rson x << 1 | 1, mid + 1, r
#define fi first
#define se second
#define mp(i,j) make_pair(i,j)
#define pii pair<int,int>
using namespace std;
typedef long long LL;
const int low(int x) { return x&-x; }
const double eps = 1e-4;
const int INF = 0x7FFFFFFF;
const int mod = 9973;
const int N = 3e5 + 10;
map<int, LL> M;
int n, x;

int gcd(int x, int y)
{
	return x%y ? gcd(y, x%y) : y;
}

int main()
{
	scanf("%d", &n);
	stack<pii> a, b;
	rep(i, 1, n)
	{
		scanf("%d", &x);  a.push(mp(x, 1));
		while (!a.empty()) b.push(mp(gcd(a.top().fi, x), a.top().se)), a.pop();
		while (!b.empty())
		{
			pii q = b.top();	b.pop();
			M[q.fi] += q.se;
			if (!a.empty() && a.top().fi == q.fi) q.se += a.top().se, a.pop();
			a.push(q);
		}
	}
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &x);
		printf("%lld\n", M[x]);
	}
	return 0;
}
