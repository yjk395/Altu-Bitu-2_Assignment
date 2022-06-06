//물대기

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef tuple<int, int, int> tp;
vector<int> parent;

//find 연산
int findParent(int a) {
    if (parent[a] < 0) return a;
    return parent[a] = findParent(parent[a]);
}

//union 연산
bool unionNode(int a, int b) {
    int ap = findParent(a);
    int bp = findParent(b);

    if (ap == bp) return false; //사이클
    if (parent[ap] < parent[bp]) {
        parent[ap] += parent[bp];
        parent[bp] = ap;
    } else {
        parent[bp] += parent[ap];
        parent[ap] = bp;
    }
    return true;
}

//mst구하기(크루스칼)
int kruskal(int n, vector<tp> &edge) {
    int sum = 0, cnt = 0;

    for (auto[w, a, b]: edge) {
        if (!unionNode(a, b)) continue;

        sum += w;
        cnt++;

        if (cnt == n) return sum; //수원지 포함 n+1개의 노드 연결해야 함, n개의 간선 선택
    }
    return 0; //mst 구할 수 없음
}

int main() {
    int n, w; //논의 수, 비용
    cin >> n;

    parent.assign(n + 1, -1);
    vector<tp> edge;

    for (int i = 1; i <= n; i++) {
        cin >> w; //우물을 팔 때 드는 비용
        edge.push_back({w, 0, i}); //0번(수원지)과 연결하는 간선
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> w; //i, j번 논을 연결하는 데 드는 비용
            if (i == j) continue; //자기 자신
            edge.push_back({w, i, j});
        }
    }
    sort(edge.begin(), edge.end()); //오름차순 정렬

    //연산, 출력
    cout << kruskal(n, edge);

    return 0;
}