//트리

#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, vector<int>> tree; //트리

//리프 노드의 수
int leafCnt(int node, int del_node) {
    if (node == del_node) return 0;
    if (tree[node].empty() || (tree[node].size() == 1 && tree[node][0] == del_node)) return 1; //리프 노드는 1 카운트

    int cnt = 0;
    for (int child: tree[node]) {
        cnt += leafCnt(child, del_node);
    }

    return cnt;
}

int main() {
    int n, node; //노드의 개수, 입력받는 노드 번호
    cin >> n;

    cin >> node; //루트 입력
    for (int i = 1; i < n; i++) {
        cin >> node;
        tree[node].push_back(i);
    }
    cin >> node; //지울 노드의 번호

    //출력
    cout << leafCnt(0, node);

    return 0;
}