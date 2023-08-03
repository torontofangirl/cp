#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define f first
#define s second
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#ifdef I_AM_NOOB
#define gg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__; ((cerr<<exchange(c,',')<<x),...); cerr<<endl; }(__VA_ARGS__);
#else
#define gg(...) 777771449
#endif

constexpr ll INFF = 1e18;
constexpr ll P = 1e9+7;
// constexpr ll P = 998244353;

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    int T; cin >> T; while (T--) {
        ll n, m; cin >> n >> m;
        if (n % 4 == 2) {
            for (ll i = m*(n-1)+1; i <= m*n; i++) {
                cout << i << ' ';
            }
            cout << endl;
        }
        if (n % 4 == 3) {
            for (ll i = m*(n-2)+1; i <= m*(n-1); i++) {
                cout << i << ' ';
            }
            cout << endl;
        }
        vector<vector<ll>> ans(n, vector<ll>(m));
        vector<ll> a = {2, 4, 1, 3};
        for (ll i = 0; i < n/4*4; i++) {
            for (ll j = 0; j < m; j++) {
                cout << m*(4*(i/4) + a[i%4]-1) +j + 1 << ' ';
                //gg(m*(i/4)+a[i%4]-1);
            } 
            cout << endl;
        }
        if (n % 4 == 1) {
            for (ll i = m*(n-1)+1; i <= m*n; i++) {
                cout << i << ' ';
            }
            cout << endl;
        } 
        if (n % 4 == 2) {
            for (ll i = m*(n-2)+1; i <= m*(n-1); i++) {
                cout << i << ' ';
            }
            cout << endl;
        } 
        if (n% 4 == 3) {
            for (ll i = m*(n-3)+1; i <= m*(n-2); i++) {
                cout << i << ' ';
            }
            cout << endl;
            for (ll i = m*(n-1)+1; i <= m*n; i++) {
                cout << i << ' ';
            }
            cout << endl;
        }

        cout << endl;
    } 
    
    return 0;
}
