// 2531 회전초밥

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 접시의 수(n), 가짓수(d), 연속해서 먹는 접시의 수(k), 쿠폰 번호(c)
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    // dish[순서] = 놓인 초밥의 종류
    vector<int> dish(n);
    for (int i=0; i<n; i++) {
        cin >> dish[i];
    }

    // my_sushi[종류] = 개수
    vector <int> my_sushi(d+1, 0);
    int unique_count = 0;
    int max_sushi = 0;

    // 첫 번째 윈도우
    for (int i=0; i<k; i++) {
        if (my_sushi[dish[i]] == 0) { // 처음 속하면 unique_count ++
            unique_count++;
        }
        my_sushi[dish[i]]++; // 기존에 존재
    }

    int current_sushi = unique_count;
    if (my_sushi[c] == 0) {
        current_sushi++;
    }
    
    max_sushi = current_sushi;
    // 슬라이딩 윈도우
    for (int i=0; i<n; i++) {
        my_sushi[dish[i]]--; // 맨 앞 초밥
        if (my_sushi[dish[i]] == 0) { // 똑같은 종류의 남은 초밥이 없다면
            unique_count--;
        }
        // 원형
        int next_sushi = dish[(k+i) % n];
        if (my_sushi[next_sushi] == 0) {
            unique_count++;
        }
        my_sushi[next_sushi]++;

        current_sushi = unique_count;
        if (my_sushi[c] == 0) {
            current_sushi++;
        }

        max_sushi = max(max_sushi, current_sushi);
    }

    cout << max_sushi << endl;
    return 0;
}