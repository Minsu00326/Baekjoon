#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> vertex) {
    vector<vector<int>> adj(n + 1);
    for (const auto& edge : vertex) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    
    vector<int> dist(n + 1, -1);
    queue<int> q;
    
    q.push(1);
    dist[1] = 0; // 시작노드
    
    int max_dist = 0; 
    
    // BFS
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for (int next : adj[curr]) {
            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1; 
                q.push(next);
                
                max_dist = max(max_dist, dist[next]);
            }
        }
    }
    
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == max_dist) {
            answer++;
        }
    }
    
    return answer;
}