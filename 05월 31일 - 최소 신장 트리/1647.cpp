//도시 분할 계획

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef tuple<int, int, int> tp;
vector<int> parent;

//find 연산
int findParent(int x) {
    if (parent[x] < 0) return x; //루트인 경우
    return parent[x] = findParent(parent[x]);
}

//union 연산
bool unionNode(int x, int y) {
    int px = findParent(x);
    int py = findParent(y);

    if (px == py) return false; //사이클 발생
    if (parent[px] < parent[py]) { //px가 새로운 루트
        parent[px] += parent[py];
        parent[py] = px;
    } else { //py가 새로운 루트
        parent[py] += parent[px];
        parent[px] = py;
    }
    return true;
}

//크루스칼로 mst
int kruskal(int n, vector<tp> &edge) {
    int sum = 0, cnt = 0; //가중치 합, 길 개수 카운트

    for (auto[w, x, y]: edge) {
        //유니온 연산
        if (!unionNode(x, y)) continue; //사이클
        sum += w;
        cnt++;

        //mst에서 가장 마지막에 선택된 가중치 큰 길 없애면 마을 분할 -> n-2개 길 찾기
        if (cnt == n - 2) { //필요한 길 모두 찾음
            return sum;
        }
    }
    return 0;
}

int main() {
    int n, m, a, b, c; //집의 개수, 길의 개수, 집 번호, 길 유지비
    cin >> n >> m;

    vector<tp> edge; //길 정보 저장
    parent.assign(n + 1, -1);

    while (m--) {
        cin >> a >> b >> c;
        edge.push_back({c, a, b});
    }
    sort(edge.begin(), edge.end()); //가중치 오름차순 정렬

    //출력
    cout << kruskal(n, edge);

    return 0;
}