#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<uint8_t> a(n+1, 0), b(n+1, 0);
    int sum_a=0, sum_b=0; // 누적합
    int res=0, res_op=0; // 일반 결과, op 사용 시 결과
    int round = n+1; // 끝난 라운드

    // 한판승 조건
    for (int i = 1; i <= n; i++) {
        int x,y;
        cin >> x >> y;
        a[i] = (uint8_t)x;
        b[i] = (uint8_t)y;

        sum_a += a[i];
        sum_b += b[i];

        if (sum_a >= k || sum_b >= k) {
            round = i;
            if (sum_a >= k && sum_b >= k) {res = 1;}
            else {res = (sum_a >= k) ? 1 : -1;}
            break;
        }

        if (sum_a> sum_b && sum_a - sum_b >= 50) {
            round = i;
            res = 1;
            break;
        }
    }

    if (res == 1) {
        cout << res << endl;
        return 0;
    }

    sum_a=0, sum_b=0;
    // A가 승리하지 않았을 경우 op 확인
    for (int j = 1; j <= min(n, round); j++) {
        sum_a += a[j];
        sum_b += b[j];

        int op = a[j]/2;
        int op_a = sum_a + op;
        int op_b = sum_b;

        if (op_a >= k || op_b >= k) {
            if (op_a >= k && op_b >= k) {res_op = -1;}
            else {res_op = (op_a >= k) ? 1 : -1;}
        }
        else if (op_a > op_b && op_a-op_b >= 50) {res_op = 1;}
        else {
            res_op = res;
        }
        res = max(res, res_op);
        if (res==1) break;
    }
    cout << res << endl;
    return 0;
}
