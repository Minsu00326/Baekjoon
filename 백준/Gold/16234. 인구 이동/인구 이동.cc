// 16234 인구 이동
#include <bits/stdc++.h>
using namespace std;

int n, l, r;
int board[50][50];
bool visited[50][50];

// 상하좌우
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// 인구 이동이 한 번이라도 일어났다면 true, 아니면 false를 반환
bool bfs(int start_x, int start_y) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> alliance;

    q.push({start_x, start_y});
    alliance.push_back({start_x, start_y});
    visited[start_x][start_y] = true;

    int sum = board[start_x][start_y]; // 문이 열린 나라의 총 인구수

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (!visited[nx][ny]) {
                    int diff = abs(board[x][y] - board[nx][ny]);

                    // 인구 차이가 L명 이상, R명 이하
                    if (diff >= l && diff <= r) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                        alliance.push_back({nx, ny});
                        sum += board[nx][ny];
                    }
                }
            }
        }
    }

    if (alliance.size() > 1) {
        int new_pop = sum / alliance.size();

        for (int i = 0; i < alliance.size(); i++) {
            int cx = alliance[i].first;
            int cy = alliance[i].second;
            board[cx][cy] = new_pop;
        }
        return true; // 인구 이동
    }

    return false; // 미이동
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    // 인구 이동 일수
    int days = 0;

    while (true) {
        bool is_moved = false; // 오늘 하루 동안 인구 이동이 있었는지

        // 턴 종료 시 visited 초기화
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (bfs(i, j)) {
                        is_moved = true;
                    }
                }
            }
        }

        // 이동 없을 시
        if (!is_moved) {
            break;
        }

        // 인구 이동이 있었다면 날짜 하루 증가
        days++;
    }

    cout << days << '\n';

    return 0;
}