// 22342 계산 로봇 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    // 경계 접근(i+1, i-1) 대비해 m+2 크기로 선언
    vector<vector<ll>> weight(m+2, vector<ll>(n+1, 0));
    vector<vector<ll>> dp(m+2, vector<ll>(n+1,0));

    // 가중치 입력 (공백 없는 문자열이므로 한 글자씩 파싱)
    for (int i=1; i<=m; i++) {
        string s;
        cin >> s;
        for (int j=1; j<=n; j++) {
            weight[i][j] = s[j-1] - '0';
        }
    }

    ll ans = 0;

    // 1열은 입력값이 0 하나이므로 저장값=0, 출력값=가중치
    for (int i = 1; i <= m; i++) {
        dp[i][1] = weight[i][1];
    }

    // 2열부터는 왼쪽 대각선 3칸의 출력값 중 최댓값이 저장값
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