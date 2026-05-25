#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const int& a, const int& b) { 
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end(), cmp);
    
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] >= i + 1) {
            answer = i + 1;
        } else {
            break; 
        }
    }
    
    return answer;
}