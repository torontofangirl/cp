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
const ll K = (1<<10);
const ll N=2e3+5, M = 2e3+5;
using tp = tuple<ll, ll, ll>;

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n,m,k; cin >> n >> m >> k;
    vector<ll> t(n+1);
    for (ll i = 1; i <= n; i++) {
        t[i] = K;
        ll cnt; cin >> cnt;
        for (ll j = 0; j < cnt; j++) {
            ll fish; cin >> fish; fish--;
            t[i] |= (1 << fish);
        }
    }

    vector<vector<ll>> adj(n+1), ws(n+1);
    for (ll i = 0; i < m; i++) {
        ll w, u, v; cin >> w >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
        ws[u][v] = ws[v][u] = w;
    }

    priority_queue<tp> pq;
    vector<vector<ll>> dist(n+1, vector<ll>(K, INFF));
    dist[1][0] = 0;
    for (pq.emplace(0, 1, 0); !pq.empty(); ) {
        auto [w, u, b] = pq.top(); pq.pop();

        for (ll v : adj[u]) {
            tp me(w+ws[u][v], v, b | t[v]); 
            if (dist[v][b] > w+ws[u][v]) {
                pq.push(me);
            }
        }
    }

    ll ans = INFF;
    for (ll i = 0; i < K; i++) {
        ll res = dist[n][i] + dist[n][~i];
        ans = min(ans, res);
    }

    cout << ans << endl;
    
    return 0;
}
