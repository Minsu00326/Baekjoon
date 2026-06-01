#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end());
    
    int current_end = -1; 
    
    for (const auto& t : targets) {
        int next_start = t[0];
        int next_end = t[1];
        
        if (next_start >= current_end) {
            answer++;               
            current_end = next_end; 
        } 
        else {
            current_end = min(current_end, next_end);
        }
    }
    
    return answer;
}