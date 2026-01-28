#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    int tc = 1; // test cases
    int cost[100001][3], sum[100001][3]; 

    while(true) {
        int N;
        cin >> N;
        if (N==0) break;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> cost[i][j];
            }
        }
        sum[0][0] = 100000000;
        sum[0][1] = cost[0][1]; // start
        sum[0][2] = cost[0][1] + cost[0][2];

        for (int i = 1; i < N; i++) {
            // 이전 row의 1st, 2nd 노드까지 오는데의 합 중 min + 현재 노드 값
            sum[i][0] = min(sum[i-1][0], sum[i-1][1]) + cost[i][0];
            // 이전 row의 1st, 2nd, 3rd 노드까지 오는데의 합과 
            // 같은 row의 1st 노드까지 오는데의 합의 min + 현재 노드 값
            sum[i][1] = min({sum[i-1][0], sum[i-1][1], sum[i-1][2], sum[i][0]}) + cost[i][1];
            // 이전 row의 2nd, 3rd 노드까지 오는데의 합과
            // 같은 row의 2nd 노드까지 오는데의 합의 min + 현재 노드 값
            sum[i][2] = min({sum[i-1][1], sum[i-1][2], sum[i][1]}) + cost[i][2];
        }

        
        cout << tc << ". " << sum[N-1][1] << endl;
        tc++;
    }


    return 0;
}