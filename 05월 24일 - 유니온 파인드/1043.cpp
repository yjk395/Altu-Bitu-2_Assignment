//거짓말

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> parent;
vector<bool> truth;

int findParent(int node, int i) {
    if (parent[i][node] < 0) return node;
    return parent[i][node] = findParent(parent[i][node], i);
}

void unionInput(int a, int b, int i) {
    int ap = findParent(a, i);
    int bp = findParent(b, i);

    if (truth[ap] || truth[bp] || truth[a] || truth[b]) {
        truth[ap] = truth[bp] = truth[a] = truth[b] = true;
    }

    if (ap == bp) return;
    if (parent[i][ap] > parent[i][bp]) {
        parent[i][ap] += parent[i][bp];
        parent[i][bp] = ap;
    } else {
        parent[i][bp] += parent[i][ap];
        parent[i][ap] = bp;
    }
}

//a를 루트로 b를 union
void unionInput2(int a, int b, int i) {
    if (truth[b]) truth[a] = true;
    parent[i][b] = a;
}

bool doesPartyKnowTruth(int n, int m, int party_num) { //파티 번호 주어짐
    for (int i = 1; i < n + 1; i++) { //전체 사람
        if (parent[party_num][i] < 0) continue; //파티에 오지 않았으면 건너뜀
        if(truth[i]) return true;
        for (int j = 0; j < m; j++) { //모든 파티에 대해
            if (truth[parent[j][i]]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m, p, a, b; //사람의 수, 파티의 수, 각 사람의 수, 사람 번호
    cin >> n >> m >> p;

    parent.assign(m, vector<int>(n + 1, -1));
    truth.assign(n + 1, false);

    //진실을 아는 사람 입력
    for (int i = 0; i < p; i++) {
        cin >> a;
        truth[a] = true;
    }

    for (int i = 0; i < m; i++) {
        cin >> p; //파티에 오는 사람 수
        cin >> a;
        parent[i][a] = a;
        for (int j = 0; j < p - 1; j++) {
            cin >> b;
            unionInput2(a, b, i); //파티에 오는 사람을 같은 집합으로
        }
    }

    int cnt = 0;
    for (int i = 0; i < m; i++) { //모든 파티
        if (!doesPartyKnowTruth(n, m, i)) cnt++;
    }

    cout << cnt;

    return 0;
}