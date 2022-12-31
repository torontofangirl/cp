#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(a) (ll)((a).size())
#define IN(A, B, C) assert(B <= A && A <= C)
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

constexpr int MAX_SIEVE = 1000;
vector<bool> isPrime(MAX_SIEVE, true);

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (ll i = 2; i*i < MAX_SIEVE; i++) {
        if (isPrime[i])         
            for (ll j = i*i; j < MAX_SIEVE; j += i)
                isPrime[j] = false;
    }
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        vector<ll> a(n); for (auto& x :a) cin >> x;
        sort(all(a));
        bool no = false;
        for (ll i = 0; i < n-1; i++) {
            if (a[i] == a[i+1]) no = true;;
        }
        if (no) {
            cout << "NO\n";
            continue;
        }
        
        bool ok = true;
        for (ll p = 2; p <= n+1/2; p++) {
            if (!isPrime[p]) continue;

            vector<ll> cnt(p, 0);
            cerr << p << endl;
            for (ll i = 0; i < n; i++) {
                cnt[a[i] % p]++;
            }
            cerr << cnt << endl;
            if (*min_element(all(cnt)) >= 2) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << endl;
    } 
    
    return 0;
}
