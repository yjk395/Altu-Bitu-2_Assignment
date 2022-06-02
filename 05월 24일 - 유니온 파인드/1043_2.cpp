//거짓말

#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//find 연산
int findParent(int n) {
    if (parent[n] < 0) return n;
    return parent[n] = findParent(parent[n]);
}

//union 연산
void unionInput(int a, int b) {
    int pa = findParent(a);
    int pb = findParent(b);

    if (pa == pb) return;
    if (pa == 0 || pb != 0 && parent[pa] <= parent[pb]) { //루트 0인 곳에 먼저 묶이게
        parent[pa] += parent[pb];
        parent[pb] = pa;
    } else {
        parent[pb] += parent[pa];
        parent[pa] = pb;
    }
}

int main() {
    int n, m, a, b; //사람의 수, 파티의 수, 각 사람의 수, 번호
    cin >> n >> m;

    parent.assign(n + 1, -1);
    vector<int> party_rep; //각 파티 대표자 1명

    //진실을 아는 사람 입력
    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> b;
        unionInput(0, b); //0을 루트로 같은 집합으로 묶기
    }

    //각 파티마다 오는 사람 입력
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        party_rep.push_back(b); //파티 대표

        for (int j = 1; j < a; j++) {
            cin >> b;
            unionInput(party_rep[i], b); //둘 중 하나가 진실 안다면 루트는 0인 집합으로 모두 묶임
        }
    }

    //파티 대표자의 루트 검사해서 카운트
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (findParent(party_rep[i])) ans++; //루트정점이 0이 아니면 카운트(샘플코드: union연산 그대로, 여기서 findParent(0)과 비교)
    }
    cout << ans;

    return 0;
}