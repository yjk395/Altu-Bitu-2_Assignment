//트리

#include <iostream>
#include <vector>

using namespace std;

//[코드리뷰] 정점의 번호 일정->2차원vector 자료형 사용하여 구현하기
vector<vector<int>> tree; //트리

//리프 노드의 수
int leafCnt(int node, int del_node) {
    if (node == del_node) return 0; //삭제된 노드 방문 시 0
    if (tree[node].empty() || (tree[node].size() == 1 && tree[node][0] == del_node)) return 1; //리프 노드는 1 카운트

    int cnt = 0;
    for (int child: tree[node]) {
        cnt += leafCnt(child, del_node);
    }

    return cnt;
}

int main() {
    int n, node, root; //노드의 개수, 입력받는 노드 번호, 루트 노드 번호
    cin >> n;
    tree.assign(n, vector<int>(0));

    //[코드리뷰] 부모가 없는 루트 정점 항상 0x
    for (int i = 0; i < n; i++) {
        cin >> node;
        if(node==-1){
            root = i; //루트 노드 번호 기억
            continue;
        }
        tree[node].push_back(i); //자식 노드로 삽입
    }
    cin >> node; //지울 노드의 번호

    //출력
    cout << leafCnt(root, node);

    return 0;
}