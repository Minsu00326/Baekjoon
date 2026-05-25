#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp (const vector<int>& a, const vector<int>& b) {
        if (a[0] != b[0]) return a[0] < b[0];
        if (a[1] != b[1]) return a[1] < b[1];
        return a[2] < b[2];
};



struct cmp_priority {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        if (a[1] != b[1]) return a[1] > b[1]; // 작업 시간
        return a[2] > b[2]; // 작업 번호 
    }
};


// 우선순위 : 소요 시간, 요청 시각, 작업 번호
int solution(vector<vector<int>> jobs) {
    int n = jobs.size(); // 작업 개수 
    vector<vector<int>> new_jobs;
    
    for (int i = 0; i < n; ++i) {
        new_jobs.push_back({jobs[i][0], jobs[i][1], i});
    }
    
    // 요청 시각 -> 소요 시간 -> 작업 번호 순으로 정렬 (미래의 일을 먼저 실행 방지)
    sort(new_jobs.begin(), new_jobs.end(), cmp);
        
    // 소요 시간 -> 작업 번호 순으로 선언
    priority_queue<vector<int>, vector<vector<int>>, cmp_priority> pq;
    
    int current_time = 0;
    int total_turnaround = 0;
    int jobs_completed = 0;
    int idx = 0;
    
    while (jobs_completed < n) {
        while (idx < n && new_jobs[idx][0] <= current_time) {
            pq.push(new_jobs[idx]);
            idx++;
        }
        
        if (!pq.empty()) {
            vector<int> current_job = pq.top();
            pq.pop();
            
            current_time += current_job[1]; 
            // cout << "현재 작업: [" << current_job[0] << ", " << current_job[1] << ", " << current_job[2] << "]" << endl;
            total_turnaround += (current_time - current_job[0]); 
            jobs_completed++;
        } else {
            // 다음 요청 사이의 공간이 있는 경우 바로 요청 시각으로 이동
            current_time = new_jobs[idx][0];
        }
    }
    
    return total_turnaround / n;
}