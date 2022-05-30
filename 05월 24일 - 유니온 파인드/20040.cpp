//사이클 게임

#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//find 연산
int findParent(int node) {
    if (parent[node] < 0) //루트 정점
        return node;
    return parent[node] = findParent(parent[node]); //압축, 루트 찾기
}

//union 연산
bool unionInput(int x, int y) {
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp) { //같은 집합 -> 사이클 발생(x의 루트와 y의 루트가 같다)
        return true;
    }
    if (parent[xp] < parent[yp]) { //집합크기 더 큰 xp를 새로운 루트로
        parent[xp] += parent[yp]; //크기 합치기
        parent[yp] = xp; //부모를 루트 정점 xp로
    } else {
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
    return false;
}

int main() {
    int n, m, x, y; //점의 개수, 진행된 차례의 수, 두 점의 번호
    cin >> n >> m;

    parent.assign(n, -1);
    int answer = 0;

    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        if (unionInput(x, y)) {
            answer = i;
            break; //여기서 입력을 다 안 끝내고 break해버려도 괜찮은 걸까요..?
        }
    }

    //출력
    cout << answer;

    return 0;
}