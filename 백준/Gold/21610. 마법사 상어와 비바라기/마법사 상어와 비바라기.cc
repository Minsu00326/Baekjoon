// 21610 마법사 상어와 비바라기
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>>n>>m;

    int A[n][n];

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> A[i][j];
        }
    }

    int d[m], s[m];
    for (int i=0; i<m; i++) {
        cin >> d[i] >> s[i];
    }

    // 방향
    int dr[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
    int dc[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

    int cloud[n][n];

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cloud[i][j] = 0;
        }
    }

    cloud[n-1][0] = 1;
    cloud[n-1][1] = 1;
    cloud[n-2][0] = 1;
    cloud[n-2][1] = 1;
    int nr, nc;

    // 메인 루프
    for (int i=0; i<m; i++) {
        int dir = d[i]; // 방향
        int dist = s[i]; // 거리

        // 초기화
        int next_cloud[n][n];
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                next_cloud[j][k] = 0;
            }
        }
        // 구름 이동
        for (int r = 0; r<n; r++) {
            for (int c = 0; c<n; c++) {
                if (cloud[r][c] == 1) {
                    nr = (r + dr[dir]*(dist % n) + n) % n;
                    nc = (c + dc[dir]*(dist % n) + n) % n;
                    A[nr][nc]++;
                    next_cloud[nr][nc] = 2;
                }
            }
        }

        // 물 복사
        int mulbok_r[] = {-1,-1, 1,1};
        int mulbok_c[] = {-1, 1, -1, 1};
        for  (int r=0; r<n; r++) {
            for (int c=0; c<n; c++) {
                for (int j=0; j<4; j++) {
                    if (next_cloud[r][c] == 2) {
                        int cnt=0;
                        int nnr = r + mulbok_r[j];
                        int nnc = c + mulbok_c[j];
                        if (nnr >= 0 && nnr < n && nnc >= 0 && nnc < n ) {
                            if (A[nnr][nnc] > 0) cnt++;
                        }
                        A[r][c] += cnt;
                    }
                }
            }
        }

        for (int r=0; r<n; r++) {
            for (int c=0; c<n; c++) {
                if (A[r][c] >= 2 && next_cloud[r][c] == 0) {
                    A[r][c] -= 2;
                    next_cloud[r][c] = 1;
                }
            }
        }

        for (int r=0; r<n; r++) {
            for (int c=0; c<n; c++) {
                if (next_cloud[r][c] == 2) {
                    next_cloud[r][c] = 0;
                }
                cloud[r][c] = next_cloud[r][c];
            }
        }
    }

    int ans =0;
    for (int r=0; r<n; r++) {
        for (int c=0; c<n; c++) {
            ans += A[r][c];
        }
    }

    cout << ans << endl;

    return 0;
}