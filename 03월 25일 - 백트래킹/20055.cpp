//20055)컨베이어 벨트 위의 로봇

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

vector<int> belt; //컨베이어 벨트의 내구도
vector<bool> robot; //로봇이 올라간 벨트의 칸
int putup, putdown; //올리는, 내리는 위치
deque<int> d_robot; //로봇이 있는 인덱스를 올라간 순서대로 저장
//로봇 올리면 앞으로만 이동->2번 연산할 때 내리는 위치부터 순회...

//단계 반복하는 함수 -> k개가 되었을 때 어느 단계인지를 알 수 있어야 함
int rotate(int n, int k) {
    int cnt = 0; //단계, 처음 수행되는 단계는 1번째 단계
    while (++cnt) { //반복하면서 단계 증가
        //1. 벨트와 각 칸의 로봇이 한 칸 회전
        putup = (putup - 1 + 2 * n) % (2 * n); //올리는, 내리는 위치의 인덱스를 한 칸 뒤로 이동
        putdown = (putdown - 1 + 2 * n) % (2 * n);

        if (robot[putdown]) { //내리는 위치에 로봇 있으면 즉시 로봇 내림
            robot[putdown] = false;
            d_robot.erase(find(d_robot.begin(), d_robot.end(), putdown));
        }

        //2. 가장 먼저 벨트에 올라간 로봇 앞으로 한 칸 이동
        int num_of_robot = d_robot.size(); //현재 올라가 있는 로봇의 개수
        for (int i = 0; i < num_of_robot; i++) { //로봇 개수만큼 덱의 front부터 순회
            int idx = d_robot.front(); //먼저 벨트에 올라간 로봇
            int nxt_idx = (idx + 1) % (2 * n); //로봇의 앞 칸의 인덱스
            if (!robot[nxt_idx] && belt[nxt_idx]) { //앞이 비어있으면서 내구도가 남아있으면
                swap(robot[idx], robot[nxt_idx]); //로봇 이동
                belt[nxt_idx]--; //이동한 칸의 내구도 1 감소
                d_robot.pop_front();
                if (nxt_idx == putdown) { //내리는 위치에 로봇 있으면 즉시 로봇 내림
                    robot[putdown] = false;
                } else { //로봇이 내려가지 않았으면 덱 업데이트
                    d_robot.push_back(nxt_idx); //이동한 인덱스 다시 삽입, 2단계 끝난 후엔 다시 들어온 순서대로 저장된 상태
                }
            } else { //로봇 이동하지 못한 경우 덱만 업데이트
                d_robot.push_back(idx);
                d_robot.pop_front();
            }
        }

        //3. 올리는 위치에 로봇을 올림
        if (belt[putup]) { //내구도 0 이상이면
            robot[putup] = true;
            d_robot.push_back(putup);
            belt[putup]--; //올린 칸의 내구도 1 감소
        }

        //4. 내구도 0인 칸의 개수 확인
        if (count(belt.begin(), belt.end(), 0) >= k) { //0의 개수가 k 이상이면 몇 번째 단계인지 반환
            return cnt;
        }
    }
}

int main() {
    int n, k; //컨베이어 벨트 길이, 내구도 0인 칸이 k개 이상이면 종료
    //입력
    cin >> n >> k;
    belt.assign(2 * n, -1);
    robot.assign(2 * n, false);
    putup = 0, putdown = n - 1; //벨트 1, n번 칸 위치
    for (int i = 0; i < 2 * n; i++) { //벨트 내구도 입력
        cin >> belt[i];
    }

    //출력
    cout << rotate(n, k);

    return 0;
}