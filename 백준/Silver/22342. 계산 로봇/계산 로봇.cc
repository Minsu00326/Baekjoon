#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<vector<ll>> weight(m+2, vector<ll>(n+1, 0));
    vector<vector<ll>> dp(m+2, vector<ll>(n+1,0));
    for (int i=1; i<=m; i++) {
        string s;
        cin >> s;
        for (int j=1; j<=n; j++) {
            weight[i][j] = s[j-1] - '0';
        }
    }

    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        dp[i][1] = weight[i][1];
    }
    
    for (int j=2; j<=n; j++) {
        for (int i=1; i<=m; i++) {
            ll storage = max({dp[i-1][j-1], dp[i][j-1], dp[i+1][j-1]});
            ans = max(ans, storage);

            dp[i][j] = storage + weight[i][j];
        }
    }

    cout << ans << endl;

    return 0;
}