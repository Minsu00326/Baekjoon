// 21608 상어 초등학교
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 인접 => [r-1][c], [r+1][c], [r][c-1], [r][c+1]
// r = [-1, 1, 0, 0], c = [0, 0, -1, 1]
// 칸마다 돌면서 인접해있는 좋아하는 친구의 수와 비어있는 칸의 수를 셈
void seat(const int& N, vector<vector<int>> &grid, const int stu_num, const vector<vector<int>> &like) {
    int best_like=-1, best_empty=-1; // 친구, 빈 칸
    int best_r = 1, best_c = 1; // 행, 열
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (grid[r][c] != 0) continue; // 누가 이미 앉아있으면 스킵
            int like_cnt = 0, empty_cnt=0; // 칸 마다 좋아하는 친구/빈 칸의 수를 셈

            for (int d = 0; d < 4; d++) { // 4방향 확인
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr < 1 || nr > N || nc < 1 || nc > N) continue; // 보드를 넘어가면 스킵
                if (grid[nr][nc] == 0) {
                    empty_cnt++;
                } else {
                    for (int i=0; i<4; i++) {
                        if (like[stu_num][i] == grid[nr][nc]) {
                            like_cnt++;
                            break;
                        }
                    }
                }
            }
            if (like_cnt > best_like || (like_cnt == best_like && empty_cnt > best_empty)) {
                best_like = like_cnt;
                best_empty = empty_cnt;
                best_r = r;
                best_c = c;
            }
        }
    }
    grid[best_r][best_c] = stu_num;
}

int calTotal(const int& N, vector<vector<int>> &grid, const vector<vector<int>> &like) {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int total = 0;
    for (int r=1; r<=N; r++) {
        for (int c=1; c<=N; c++) {
            int temp = 0;
            int student = grid[r][c];
            for (int d=0; d<4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr < 1 || nr > N || nc < 1 || nc > N) continue;
                for (int i=0; i<4; i++) {
                    if (like[student][i] == grid[nr][nc]) {
                        temp++;
                    }
                }
            }
            if (temp == 0) total += 0;
            else if (temp == 1) total += 1;
            else if (temp == 2) total += 10;
            else if (temp == 3) total += 100;
            else if (temp == 4) total += 1000;
        }
    }
    return total;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> grid(N+1, vector<int>(N+1, 0));
    vector<int> stu_num;
    // like[학생 번호] = {좋아하는 친구 4명}
    vector<vector<int>> like(N*N + 1, vector<int>(4));

    for (int i=0; i< N*N; i++) {
        int num;
        cin >> num;
        stu_num.push_back(num);
        for (int j=0; j<4; j++) {
            cin >> like[num][j];
        }
    }

    for (int num : stu_num) seat(N, grid, num, like);
    cout << calTotal(N, grid, like) << endl;

    return 0;
}

