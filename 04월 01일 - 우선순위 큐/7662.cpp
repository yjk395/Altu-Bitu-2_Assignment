//이중 우선순위 큐

#include <iostream>
#include <queue>
#include <map>

using namespace std;

priority_queue<int, vector<int>> max_heap; //우선순위가 가장 높은 데이터 삭제
priority_queue<int, vector<int>, greater<int>> min_heap; //우선순위가 가장 낮은 데이터 삭제
map<int, int> m; //삭제된 원소 확인, 중복 가능하니 bool 말고 int로 개수 체크

//Q에 삽입
void insertQ(int n) {
    max_heap.push(n);
    min_heap.push(n);
    m[n]++; //삽입된 개수 체크
}

//Q에서 최댓값 삭제
void deleteQMax() {
    //이미 삭제되어 개수 0인 값은 삭제
    while (!max_heap.empty() && m[max_heap.top()] == 0) {
        max_heap.pop();
    }
    //비어있으면 연산 무시
    if (max_heap.empty()) return;

    m[max_heap.top()]--; //맵 업데이트
    max_heap.pop(); //삭제
}

//Q에서 최솟값 삭제
void deleteQMin() {
    //이미 삭제된 값은 삭제
    while (!min_heap.empty() && m[min_heap.top()] == 0) {
        min_heap.pop();
    }
    //비어있으면 연산 무시
    if (min_heap.empty()) return;

    m[min_heap.top()]--; //맵 업데이트
    min_heap.pop(); //삭제
}

int main() {
    int t; //입력 데이터 수
    cin >> t;
    while (t--) {
        int k, n; //연산의 개수, 삭제 시 1 or -1, 삽입하는 정수
        char op; //연산 문자, 'D' or 'I'
        cin >> k;
        while (k--) {
            cin >> op >> n;
            switch (op) {
                case 'I': //삽입
                    insertQ(n);
                    break;
                case 'D': //삭제
                    if (n == 1) { //최댓값 삭제
                        deleteQMax();
                    } else { //최솟값 삭제
                        deleteQMin();
                    }
            }
        }

        //출력
        while (!max_heap.empty() && m[max_heap.top()] == 0) {
            max_heap.pop();
        }
        if (max_heap.empty()) {
            cout << "EMPTY" << '\n';
        } else {
            while (!min_heap.empty() && m[min_heap.top()] == 0) {
                min_heap.pop();
            }
            cout << max_heap.top() << ' ' << min_heap.top() << '\n';
        }
    }

    return 0;
}