//우주신과의 교감

#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

typedef tuple<double, int, int> tp;
typedef pair<double, double> ci;
vector<int> parent;

//find 연산
int findParent(int a) {
    if (parent[a] < 0) return a;
    return parent[a] = findParent(parent[a]);
}

//union 연산
bool unionNode(int a, int b) {
    int pa = findParent(a);
    int pb = findParent(b);

    if (pa == pb) return false; //사이클
    if (parent[pa] < parent[pb]) {
        parent[pa] += parent[pb];
        parent[pb] = pa;
    } else {
        parent[pb] += parent[pa];
        parent[pa] = pb;
    }
    return true;
}

//mst구하기(크루스칼)
double kruskal(int n, vector<tp> &edge) {
    double sum = 0;
    int cnt = 0;

    for (auto[w, a, b]: edge) {
        if (!unionNode(a, b)) continue;
        sum += w;
        cnt++;
        if (cnt == n - 1) return sum;
    }
    return 0; //mst 만들어지지 않음
}

int main() {
    int n, m, a, b; //우주신 개수, 이미 연결된 통로 개수, 우주신 번호
    double x, y;
    cin >> n >> m;

    parent.assign(n + 1, -1);
    vector<tp> edge;
    vector<ci> god(1);

    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        //거리 모두 구하기
        for (int j = 1; j < i; j++) {
            double dx = x - god[j].first;
            double dy = y - god[j].second;
            edge.push_back({sqrt(dx * dx + dy * dy), i, j});
        }
        god.push_back({x, y});
    }
    sort(edge.begin(), edge.end()); //오름차순 정렬

    //이미 연결된 통로 입력
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        //a, b를 union
        unionNode(a, b);
    }

    int rq = 0; //연결해야 할 우주신 개수(이미 연결된 우주신들은 하나로 카운트)
    for (int i = 1; i <= n; i++) {
        if (parent[i] < 0) rq++;
    }

    //연산, 출력
    cout << fixed;
    cout.precision(2); //소수점 2번째 자리까지 출력
    cout << kruskal(rq, edge);

    return 0;
}