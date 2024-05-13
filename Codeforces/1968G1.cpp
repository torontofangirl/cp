#include <bits/stdc++.h>
using namespace std;

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
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-bg(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-bg(a); }

using u64 = uint64_t;
struct polyhash {
    static const int base = 1e9+9;
    static const int mod = 1e9+123;
    static vi pow1;
    static V<u64> pow2;
    vi pre1;
    V<u64> pre2;
    polyhash(const string& s) : pre1(s.size()+1), pre2(s.size()+1) {
        while (pow2.size() <= s.size()) pow2.pb(pow2.back()*base);
        while (pow1.size() <= s.size()) pow1.pb(1LL*pow1.back()*base%mod);
        for (int i = 0; i < s.size(); i++) {
            pre2[i+1] = pre2[i] + pow2[i]*s[i];
            pre1[i+1] = pre1[i] + 1LL*pow1[i]*s[i]%mod;
            if (pre1[i+1] >= mod) pre1[i+1] -= mod;
        }
    }
    pair<int, u64> operator()(int l, int r, int max_pow) {
        int hash2 = pre2[r]-pre2[l];
        int hash1 = pre1[r]-pre1[l];
        if (hash1 < 0) hash1 += mod;
        if (max_pow != 0) {
            hash2 *= pow2[max_pow-r];
            hash1 = 1LL*pow1[max_pow-r]*hash1%mod;
        }
        return {hash1, hash2};
    }
};

vi polyhash::pow1 = {1};
V<u64> polyhash::pow2 {1};

int n, l, r; 
string s;

void solve() {
    cin >> n >> l >> r;
    cin >> s;
    auto S = polyhash(s);
    
    int lo = 1, hi = n+1;
    while (lo < hi) {
        int len = (lo+hi)/2;

        int cnt = 0;
        int i = 0;
        for (; i+len <= n; ) {
            if (S(i, i+len, n) == S(0, len, n)) {
                cnt++;
                i += len;
            } else {
                i++;
            }
        }

        cnt >= l ? lo = len+1 : hi = len;
    }

    cout << hi-1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
