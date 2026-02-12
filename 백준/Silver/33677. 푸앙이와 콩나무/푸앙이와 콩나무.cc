#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // 필요한 콩나무의 길이
    ull N;
    cin >> N;
    if (N==0) {
        cout << "0 0" << endl;
        return 0;
    }

    // 일수, 물의 양, 자라나는 콩나무의 길이
    vector<ull> days(N+1, 1e18);
    vector<ull> water(N+1, 1e18);
    queue<ull> q;
    days[0]=0;
    water[0]=0;
    q.push(0);

    // +1, *3, **2 검사 후 N보다 작거나 같으면 교체
    while (!q.empty()) {
        // 길이가 len일 때 일수와 물의 양
        ull len = q.front();
        q.pop();

        ull d = days[len];
        ull w = water[len];


        // 물을 1만큼 줄 때
        if (len + 1 <= N) {
            ull nlen = len + 1;
            ull nd = d + 1;
            ull nw = w + 1;
            // 일수가 적거나, 일수가 같지만 물 양이 적으면 len을 교체
            if (nd < days[nlen] or (nd == days[nlen] && nw < water[nlen])) {
                days[nlen] = nd;
                water[nlen] = nw;
                q.push(nlen);
            }
        }

        // 물을 3만큼 줄 때
        if (len <= N/3) {
            ull nlen = len * 3;
            ull nd = d + 1;
            ull nw = w + 3;

            if (nd < days[nlen] || (nd == days[nlen] && nw < water[nlen])) {
                days[nlen] = nd;
                water[nlen] = nw;
                q.push(nlen);
            }
        }

        // 물을 5만큼 줄 때
        if (len <= sqrt(N)) {
            ull nlen = len * len;
            ull nd = d + 1;
            ull nw = w + 5;

            if (nd < days[nlen] || (nd == days[nlen] && nw < water[nlen])) {
                days[nlen] = nd;
                water[nlen] = nw;
                q.push(nlen);
            }
        }

    }

    cout << days[N] << " " << water[N] << endl;

    return 0;
}