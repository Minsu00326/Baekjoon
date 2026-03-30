#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool compare(pair<int,int> x, pair<int,int> y) {
	if (x.second == y.second) {
		return x.first > y.first;
	}
	return x.second < y.second;
}

bool books[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N, M;
		cin >> N >> M;

		memset(books, 0, sizeof(books));
		// M만큼의 학생의 a, b 값
		vector<pair<int, int>> student(M);

		for (int i = 0; i < M; i++) {
			cin >> student[i].first >> student[i].second;
		}

		int ans = 0;
		sort(student.begin(), student.end(), compare);
		for (int i=0; i<M; i++) {
			int start = student[i].first;
			int end = student[i].second;

			for (int j=start; j<=end; j++) {
				if (books[j] == false) {
					books[j] = true;
					ans++;
					break;
				}
			}
		}
		cout << ans << "\n";
	}

	return 0;
}