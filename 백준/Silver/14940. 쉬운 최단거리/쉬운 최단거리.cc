// 14940 쉬운 최단거리
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n+1, vector<int>(m+1));
    // 거리 -1로 초기화
    vector<vector<int>> dist(n+1, vector<int>(m+1, -1));

    int r, c;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 2) {
                r = i;
                c = j;
            }
        }
    }

    // 우 좌 상 하
    int dr[] = {0, 0, -1, 1};
    int dc[] = {1, -1, 0, 0};

    queue<pair<int, int>> q;
    q.push({r,c});
    dist[r][c] = 0;


    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        // 인접한 노드 확인
        for (int i=0; i<4; i++) {
            int nr = p.first + dr[i];
            int nc = p.second + dc[i];

            // 보드를 벗어나거나, 못가는 칸이거나, 이미 방문한 칸이면 큐에 넣지 않음
            if (nr < 1 || nc < 1 || nr > n || nc > m || matrix[nr][nc] == 0 || dist[nr][nc] != -1) {
                continue;
            }
            dist[nr][nc] = dist[p.first][p.second] + 1;
            q.push({nr,nc});
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (matrix[i][j] == 0) cout << 0;
            else cout << dist[i][j];
            if (j < m) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}