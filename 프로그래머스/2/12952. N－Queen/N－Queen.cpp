#include <vector>
#include <cmath>

using namespace std;

int answer = 0;
vector<int> col;

bool isSafe(int row) {
    for (int i = 0; i < row; ++i) {
        if (col[i] == col[row] || abs(col[row] - col[i]) == row - i) {
            return false;
        }
    }
    return true;
}

void dfs(int row, int n) {
    if (row == n) {
        answer++;
        return;
    }
    
    for (int c = 0; c < n; ++c) {
        col[row] = c;
        if (isSafe(row)) {
            dfs(row + 1, n);
        }
    }
}

int solution(int n) {
    answer = 0;
    col.assign(n, 0);
    dfs(0, n);
    return answer;
}