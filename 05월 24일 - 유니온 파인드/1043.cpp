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

int main() {
    int n, m, p, a, b; //사람의 수, 파티의 수, 각 사람의 수, 사람 번호
    cin >> n >> m >> p;

    parent.assign(m, vector<int>(n + 1, -1));
    truth.assign(n + 1, false);

    vector<int> party(0);

    //진실을 아는 사람 입력
    for (int i = 0; i < p; i++) {
        cin >> a;
        truth[a] = true;
    }

    for (int i = 0; i < m; i++) {
        cin >> p; //파티에 오는 사람 수
        cin >> a;
        party.push_back(a);
        for (int j = 0; j < p - 1; j++) {
            cin >> b;
            unionInput(b, a, i); //파티에 오는 사람을 같은 집합으로
        }
    }

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        bool know_truth = false;
        for (int j = 0; j < m; j++) {
            if (truth[findParent(party[i], j)]) know_truth = true;
        }
        if (!know_truth) cnt++;
    }

    cout << cnt;

    return 0;
}