#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin >> n >> k;


    vector<int> A(2*n,0);
    for (int i = 0; i < 2*n; i++) {
        cin >> A[i];
    }

    vector<bool> robot(n, false);
    int round = 0;

    // 회전마다 가중치 이동 + 로봇 이동 + 로봇 올리기/내리기
    while (true) {
        round++;
        // 가중치와 로봇 이동
        int temp_a = A[2*n-1];
        for (int i = 2*n-1; i > 0; i--) {
            A[i] = A[i-1];
        }
        A[0] = temp_a;

        for (int i = n-1; i > 0; i--) {
            robot[i] = robot[i-1];
        }
        robot[n-1] = false;
        robot[0] = false;

        // 로봇 자체 이동
        for (int i = n-2; i >= 0; i--) {
            if (A[i+1] > 0 && !robot[i+1] && robot[i]) {
                robot[i+1] = true;
                robot[i] = false;
                A[i+1]--;
            }
        }
        robot[n-1] = false;

        if (A[0] > 0) {
            robot[0] = true;
            A[0]--;
        }

        int zero_count = 0;
        for (int i = 0; i < 2 * n; i++) {
            if (A[i] == 0) {
                zero_count++;
            }
        }

        if (zero_count >= k) {
            break;
        }
    }

    cout << round << endl;

    return 0;
}
