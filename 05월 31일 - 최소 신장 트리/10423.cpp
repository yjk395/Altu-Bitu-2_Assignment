//전기가 부족해

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef tuple<int, int, int> tp;
vector<int> parent;

//find 연산
int findParent(int u) {
    if (parent[u] < 0) return u;
    return parent[u] = findParent(parent[u]);
}

//union 연산
bool unionNode(int u, int v) {
    int pu = findParent(u);
    int pv = findParent(v);

    if (pu == pv) return false; //사이클
    if (parent[pu] < parent[pv]) {
        parent[pu] += parent[pv];
        parent[pv] = pu;
    } else {
        parent[pv] += parent[pu];
        parent[pu] = pv;
    }
    return true;
}

//mst 구하기(크루스칼)
int kruskal(int n, vector<tp> &edge) {
    int sum = 0, cnt = 0;

    for (auto[w, u, v]: edge) {
        if (!unionNode(u, v)) continue;
        sum += w;
        cnt++;

        if (cnt == n-1) return sum;
    }
    return 0; //mst 만들 수 없음
}

int main() {
    int n, m, k, u, v, w; //도시 개수, 케이블 수, 발전소 개수, 도시 번호, 비용
    cin >> n >> m >> k;

    parent.assign(n + 1, -1);
    vector<tp> edge;

    //발전소 설치된 도시 번호 k개 입력
    cin >> u;
    for (int i = 0; i < k - 1; i++) {
        cin >> v;
        unionNode(u, v); //발전소 있는 도시들끼리 이미 연결되어 있는 것으로 가정
    }

    //케이블 정보 m개 입력
    while (m--) {
        cin >> u >> v >> w;
        edge.push_back({w, u, v});
    }
    sort(edge.begin(), edge.end()); //오름차순 정렬

    //연산, 출력
    cout << kruskal(n - k + 1, edge); //발전소 있는 도시들을 하나로 보고 mst 구하기

    return 0;
}