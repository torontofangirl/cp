#include <bits/stdc++.h>
using namespace std;
#define int int64_t

#ifdef LOCAL
#include "algo/debug.h"
#endif

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;
using vb = V<bool>;
using vs = V<string>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define len(x) (int)((x).size())
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }
#define pct __builtin_popcount
#define ctz __builtin_ctz
#define clz __builtin_clz
constexpr int p2(int x) { return (int)1 << x; }
constexpr int bits(int x) { return x == 0 ? 0 : 31-clz(x); } // floor(log2(x)) 

// int f(int a,int b,int c,int n){
	// if(a==0)return((b/c)*(n+1));
	// if(a>=c||b>=c)return f(a%c,b%c,c,n)+(a/c)*n*(n+1)/2+(b/c)*(n+1);
	// int m=(a*n+b)/c;
	// return n*m-f(c,c-b-1,a,m-1);
// }
int f(int a, int b, int c, int n) {
    if (a==0) return b/c*(n+1);
    if (a>=c||b>=c) 
        return a/c*n*(n+1)/2 + b/c*(n+1) + f(a%c,b%c,c,n);
    if(a>=c||b>=c)return f(a%c,b%c,c,n)+(a/c)*n*(n+1)/2+(b/c)*(n+1); 
    int m = (a*n+b)/c;
    return n*m - f(c,c-b-1,a,m-1);
}

void solve() {
    int p, q; cin >> p >> q;
    int A = f(q, 0, p, (p-1)/2);
    int B = f(p, 0, q, (q-1)/2);
    cout << A+B << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}