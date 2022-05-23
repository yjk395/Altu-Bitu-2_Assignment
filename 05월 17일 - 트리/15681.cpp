//트리와 쿼리

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree_graph; //인접리스트 형태
//vector<vector<int>> tree;
vector<int> node_size; //서브트리 정점의 개수

//트리 구성
void makeTree(int cur, int parent) {
//    if (tree_graph[cur].size() == 1 && tree_graph[cur][0] == parent) return;
    for (int i=0; i<tree_graph[cur].size(); i++) {
        if (tree_graph[cur][i] == parent){ //cur에 연결된 정점 중 부모 노드는 삭제
            tree_graph[cur].erase(tree_graph[cur].begin()+i);
            i--;
        }else{
//            tree[cur].push_back(node);
            makeTree(tree_graph[cur][i], cur); //재귀 호출
        }

    }
}

//서브트리에 속한 정점의 수 계산
void countSubtreeNodes(int cur) {
    if (tree_graph[cur].empty()) return;
    for (int node: tree_graph[cur]) {
        countSubtreeNodes(node);
        node_size[cur] += node_size[node];
    }
}

int main() {
    int n, r, q; //정점의 수, 루트의 번호, 쿼리의 수
    cin >> n >> r >> q;

    tree_graph.assign(n+1, vector<int>(0));
//    tree.assign(n+1, vector<int>(0));
    node_size.assign(n+1, 1); //자신 정점 1로 카운트

    int node1, node2, node_q;

    //간선 입력
    for (int i = 0; i < n - 1; i++) {
        cin >> node1 >> node2;
        tree_graph[node1].push_back(node2);
        tree_graph[node2].push_back(node1);
    }

    //연산
    makeTree(r, -1);
    countSubtreeNodes(r);

    //쿼리 정점 입력 & 출력
    while (q--) {
        cin >> node_q;
        cout << node_size[node_q] << '\n';
    }

    return 0;
}