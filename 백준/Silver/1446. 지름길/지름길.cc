#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    cin >> N >> D;

    // 지름길[끝] = (시작, 길이)
    vector<vector<pair<int,int>>> shortcut(D+1);

    for (int i = 1; i <= N; i++) {
        int start, end, len;
        cin >> start >> end >> len;
        // 끝이 D를 넘지 않고 진짜 지름길일 때만 넣기
        if (end <= D && len <= end-start) {
            shortcut[end].push_back({start, len});
        }
    }

    vector<int> dist(D+1, 1e8);
    dist[0] = 0;

    for (int j = 1; j <= D; j++) {
        // 일반 도로로 가는 길
        dist[j] = dist[j-1] + 1;

        // x로 오는 지름길 반영
        for (auto &path : shortcut[j]) {
            dist[j] = min(dist[j], dist[path.first] + path.second);
        }
    }

    cout << dist[D] << "\n";
    return 0;
    }


