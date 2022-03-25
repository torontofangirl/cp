#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q, k; cin >> n >> q >> k;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;

        cout << k + a[r-1] - a[l-1] - 2 * (r - l) - 1 << '\n';
    }
    
    return 0;
}

