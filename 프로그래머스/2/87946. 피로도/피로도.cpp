#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max_dungeons = 0; 
bool visited[8] = {false, }; 

// fatigue = 피로도
void dfs(int current_fatigue, int count, const vector<vector<int>>& dungeons) {
    max_dungeons = max(max_dungeons, count);

    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i] && current_fatigue >= dungeons[i][0]) {
            visited[i] = true;
            dfs(current_fatigue - dungeons[i][1], count + 1, dungeons);
            
            visited[i] = false; // 다른 순서 찾기
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(k, 0, dungeons);
    
    return max_dungeons;
}