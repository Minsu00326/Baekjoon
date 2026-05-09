#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2, 0);
    int left = 0;
    long long sum = 0;
    int min_len = 2000000;

    for (int right = 0; right < sequence.size(); right++) {
        sum += sequence[right];

        while (sum > k && left <= right) {
            sum -= sequence[left];
            left++;
        }

        if (sum == k) {
            int current_len = right - left + 1;
            
            if (current_len < min_len) {
                min_len = current_len;
                answer[0] = left;
                answer[1] = right;
            }
        }
    }

    return answer;
}