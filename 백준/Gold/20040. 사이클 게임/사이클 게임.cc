// 20040 사이클 게임
#include <iostream>
#include <vector>
using namespace std;

int get_parent(int parent[], int i) {
    if (parent[i] == i) return i;
    return parent[i] = get_parent(parent, parent[i]);
}

// 숫자가 작은 노드의 부모 따라가도록
void union_parent(int parent[], int a, int b) {
    a = get_parent(parent, a);
    b = get_parent(parent, b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // union find 알고리즘
    // 처음엔 자기 자신을 부모로 갖음
    int parent[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    int round = 0;

    for (int i = 0; i < m; i++) {
        int node1, node2;
        cin >> node1 >> node2;

        if (round != 0) break;

        // 부모가 같을 때 사이클이 있다고 판정
        if (get_parent(parent, node1) == get_parent(parent, node2)) {
            round = i+1;
        }
        else {
            union_parent(parent, node1, node2);
        }
    }

    cout << round << endl;

    return 0;
}