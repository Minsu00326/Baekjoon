#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> target;
    
    for (int i = 0; i < want.size(); i++) {
        target[want[i]] = number[i];
    }
    
    for (int i = 0; i <= discount.size() - 10; i++) {
        unordered_map<string, int> current_window;
        
        for (int j = 0; j < 10; j++) {
            current_window[discount[i + j]]++;
        }
        
        bool is_match = true;
        for (int j = 0; j < want.size(); j++) {
            if (current_window[want[j]] != target[want[j]]) {
                is_match = false;
                break;
            }
        }
        
        if (is_match) {
            answer++;
        }
    }
    
    return answer;
}