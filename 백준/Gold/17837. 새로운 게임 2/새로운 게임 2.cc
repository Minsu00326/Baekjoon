// 17837 새로운 게임2
#include <bits/stdc++.h>
using namespace std;

// 말 정보
struct Mal {
	int row, col, dir;
};

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	// 칸 색깔 (흰 = 0, 빨 = 1, 파 = 2)
	int board[13][13];
	// 같은 칸에 있는 말 (vector를 담고 있는 이차원 배열)
	vector<int> stack[13][13];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}

	// 말 정보 받기
	Mal mal[11];
	for (int l = 0; l < k; l++) {
		cin >> mal[l].row >> mal[l].col >> mal[l].dir;
		stack[mal[l].row][mal[l].col].push_back(l); // 각 칸에 말의 번호를 넣음
		mal[l].dir--; // 인덱스로 쓰기 위함
	}


	const vector<int> dr = {0,0,-1,1};
	const vector<int> dc = {1,-1,0,0};
	// 반대 방향 (우 좌 상 하 반대인 좌 우 하 상)
	const vector<int> opp = {1, 0, 3, 2};

	for (int round = 1; round <= 1000; round++) {
		for (int i = 0; i < k; i++) {
			int r = mal[i].row;
			int c = mal[i].col;
			int d = mal[i].dir;

			// 이동할 목적지
			int nr = r + dr[d];
			int nc = c + dc[d];

			// 범위 밖이거나 파란색이면 방향 바꾸기
			if (nr < 1 || nr > n || nc < 1 || nc > n || board[nr][nc] == 2) {
				d = opp[d];
				mal[i].dir = d;
				nr = r + dr[d];
				nc = c + dc[d];
				
				if (nr < 1 || nr > n || nc < 1 || nc > n || board[nr][nc] == 2) {
					continue;
				}
			}

			vector<int>& current = stack[r][c];
			int pos = -1;
			for (int j=0; j<current.size(); j++) {
				if (current[j] == i) {
					pos = j;
					break;
				}
			}

			// 이동할 스택 슬라이싱
			vector<int> move_new(current.begin() + pos, current.end());
			current.erase(current.begin() + pos, current.end());

			// 만약 이동하려는 칸이 빨간색이라면 뒤집어 버리기
			if (board[nr][nc] == 1) {
				reverse(move_new.begin(), move_new.end());
			}

			// 이동
			for (int h : move_new) {
				stack[nr][nc].push_back(h);
				mal[h].row = nr;
				mal[h].col = nc;
			}

			if (stack[nr][nc].size() >= 4 ) {
				cout << round << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
    return 0;
}


