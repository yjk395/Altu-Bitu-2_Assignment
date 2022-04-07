//크리스마스 선물

#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> present;
    int n, a, p; //방문 횟수, 충전하는 선물의 개수(0이면 아이), 선물의 가치
    cin >> n;

    while (n--) {
        cin >> a;
        if (a) { //a가 0이 아니면, a개의 선물 충전
            while (a--) {
                cin >> p; //선물의 가치 입력받아 큐에 삽입
                present.push(p);
            }
        } else {
            //아이를 만나 선물 줌, 출력
            if (present.empty()) { //줄 선물이 없다면 -1 출력
                cout << -1 << '\n';
            } else { //가치가 가장 큰 선물의 가치 출력, 해당 선물 삭제
                cout << present.top() << '\n';
                present.pop();
            }
        }
    }

    return 0;
}