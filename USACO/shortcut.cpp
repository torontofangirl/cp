#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
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
    // freopen("shortcut.in", "r", stdin);
    // freopen("shortcut.out", "w", stdout);
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n, m, t; while (cin >> n >> m >> t) {
        // cout <<sizeof (ll) << endl;
        vector<ll> c(n+1); for (ll i = 1; i <= n; i++) cin >> c[i];
        vector<vector<pll>> adj(n+1);
        for (ll i = 0; i < m; i++){
            ll u, v, w; cin >> u >> v >> w;
            adj[u].pb({v, w}), adj[v].pb({u, w});
        }
        
        priority_queue<pll> pq;
        vector<ll> dist(n+1, INFF); dist[1] = 0;
        vector<ll> par(n+1, -1), cnt(n+1);
        for (pq.emplace(0, 1); !pq.empty(); ) {
            auto [d, u] = pq.top(); pq.pop();
            for (auto[v, w] : adj[u]) {
                if (dist[v] > d+w) {
                    dist[v] = d+w;
                    pq.emplace(dist[v], v);
                    par[v] = u;
                //lexo minimum
                } else if (dist[v] == d+w) {
                    if (u < par[v]) {
                        par[v] = u;
                        pq.emplace(dist[v], v);
                    }
                }
            }
        }

        for (ll i = 1; i <= n; i++) {
            ll b = i;
            while (b != -1) {
                cnt[b] += c[i];
                b = par[b];
            }
        }
        
        ll ans = 0;
        for (ll i = 1; i <= n; i++) {
            ans = max(ans, cnt[i]*(dist[i]-t));
        }
        cout << ans << endl;
    }
    
    return 0;
}


