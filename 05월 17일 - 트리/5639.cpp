//이진 검색 트리

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};
//트리에 삽입하는 함수
void insertBst(int n, Node *root) {
    Node *node = new Node();
    node->data = n;
    node->left = node->right = NULL;

    if (n < root->data) {
        if (root->left == NULL) {
            root->left = node;
            return;
        }
        insertBst(n, root->left);
    } else {
        if (root->right == NULL) {
            root->right = node;
            return;
        }
        insertBst(n, root->right);
    }
}

//후위 순회 출력
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << '\n';
}

int main() {
    int n; //노드, 루트

//    int t = 8;

    //트리 입력
    cin >> n;
    Node *root = new Node();
    root->data = n;
    root->left = root->right = NULL;

    while (cin >> n) {
//        cin >> n;
        //트리에 삽입
        insertBst(n, root);
    }

    postorder(root);

    return 0;
}