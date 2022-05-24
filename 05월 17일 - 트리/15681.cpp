//트리와 쿼리

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree_graph; //인접리스트 형태
vector<int> node_size; //서브트리 정점의 개수

vector<vector<int>> tree;

//트리 구성
void makeTree(int cur, int parent) {
    if (tree_graph[cur].size() == 1 && tree_graph[cur][0] == parent) return;
    for (int node: tree_graph[cur]) {
        if (node == parent) continue;
        tree[cur].push_back(node);
        makeTree(node, cur); //재귀 호출
    }
}

//서브트리에 속한 정점의 수 계산
void countSubtreeNodes(int cur) {
    if (tree[cur].empty()) return;
    for (int node: tree[cur]) {
        countSubtreeNodes(node);
        node_size[cur] += node_size[node];
    }
}

//[코드리뷰] 메모이제이션 활용하여 dfs 탐색 (샘플코드 참조했습니다)
int treeDp(int cur) {
    if (node_size[cur] != -1) return node_size[cur]; //이미 탐색(=부모)
    node_size[cur] = 0; //여기서 현재 정점의 dp값 0으로 설정 -> 자식 노드만 탐색(부모 노드는 0 리턴받음)
    int cnt = 1; //자기 자신
    for (int node: tree_graph[cur]) {
        cnt += treeDp(node);
    }
    return node_size[cur] = cnt;
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, r, q; //정점의 수, 루트의 번호, 쿼리의 수
    cin >> n >> r >> q;

    tree_graph.assign(n + 1, vector<int>(0));

//    tree.assign(n + 1, vector<int>(0));
//    node_size.assign(n + 1, 1); //자기자신 1 카운트

    node_size.assign(n + 1, -1); //방문하지 않았으면 -1


    int node1, node2, node_q;

    //간선 입력
    for (int i = 0; i < n - 1; i++) {
        cin >> node1 >> node2;
        tree_graph[node1].push_back(node2);
        tree_graph[node2].push_back(node1);
    }

    //연산
//    makeTree(r, -1);
//    countSubtreeNodes(r);

    treeDp(r);


    //쿼리 정점 입력 & 출력
    while (q--) {
        cin >> node_q;
        cout << node_size[node_q] << '\n';
    }

    return 0;
}