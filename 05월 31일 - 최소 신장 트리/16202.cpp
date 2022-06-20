//MST 게임

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ci;
vector<int> parent;

//find 연산
int findParent(int x) {
    if (parent[x] < 0) return x;
    return parent[x] = findParent(parent[x]);
}

//union 연산
bool unionNode(int x, int y) {
    int px = findParent(x);
    int py = findParent(y);

    if (px == py) return false;
    if (parent[px] < parent[py]) {
        parent[px] += parent[py];
        parent[py] = px;
    } else {
        parent[py] += parent[px];
        parent[px] = py;
    }
    return true;
}

//mst 찾기(크루스칼)
int kruskal(int n, int m, vector<ci> &edge, int turn) {
    int sum = 0, cnt = 0;

    //mst에서 가장 가중치 작은 간선 하나 제거 -> 앞 원소 하나씩 제외하고 탐색
    for (int i = turn; i <= m; i++) {
        if (!unionNode(edge[i].first, edge[i].second)) continue;
        sum += i; //가중치 합산
        cnt++;
        if (cnt == n - 1) { //mst 완성
            fill(parent.begin(), parent.end(), -1); //parent 초기화
            return sum;
        }
    }
    return 0; //mst 만들 수 없는 경우
}

int main() {
    int n, m, k; //정점 개수, 간선 개수, 턴 개수
    cin >> n >> m >> k;

    parent.assign(n + 1, -1);
    vector<ci> edge(m + 1);

    //간선 정보 입력
    for (int i = 1; i <= m; i++) {
        cin >> edge[i].first >> edge[i].second;
    }

    //연산, 출력
    for (int i = 1; i <= k; i++) {
        cout << kruskal(n, m, edge, i) << ' ';
    }

    return 0;
}