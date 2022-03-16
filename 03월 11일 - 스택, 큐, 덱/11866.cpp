//11866)요세푸스 문제 0

//(7, 3)일 때 3번째 제거->그 위치에서 3번째인 6 제거->그 위치에서 3번째(7,1,2) 제거->...
//queue 사용, pop&push 두 번 한 후 출력&pop하는 것을 반복

#include <iostream>
#include <queue>

using namespace std;

void josephusPr(int n, int k) {
    queue<int> q; //원에 앉아있는 사람
    for (int i = 1; i <= n; i++)
        q.push(i);
    //연산&출력
    cout << "<";
    while (n--) {
        for (int i = 0; i < k - 1; i++) { //k-1명의 사람을 뒤로 보냄
            q.push(q.front());
            q.pop();
        }

        //k번째 사람을 출력
        cout << q.front();
        if (n > 0)
            cout << ", ";
        q.pop();
    }
    cout << '>';
}

int main() {
    int n, k; //k번째 사람 제거, n명의 사람. (n, k)-오세푸스 순열
    //입력
    cin >> n >> k;

    //출력
    josephusPr(n, k);

    return 0;
}