//행운의 바퀴

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, char> ci;

vector<char> wheel; //알파벳 대문자가 적힌 행운의 바퀴
int arrow = 0; //화살표가 가리키는 칸의 인덱스

//바퀴에 적힌 글자 찾고 바퀴가 있으면 true, 없으면 false 반환
bool findWheel(int n, int k, vector<ci> rot_record) {
    vector<bool> alp(26, false); //알파벳 사용 여부 체크
    for (int i = 0; i < k; i++) {
        int s = rot_record[i].first; //가리키는 글자 바뀐 횟수
        char ch = rot_record[i].second; //화살표가 가리키는 글자

        arrow = (arrow + s) % n; //바퀴 회전
        if (wheel[arrow] == '?') { //결정되지 않은 칸이면 업데이트
            //바퀴 없는 경우2: 바퀴에 같은 글자 두 번 이상 등장x -> 다른 위치에 같은 글자 이미 있는 경우 체크
            if (alp[ch - 'A']) return false;

            wheel[arrow] = ch; //바퀴 업데이트
            alp[ch - 'A'] = true; //알파벳 사용 여부 체크
        } else if (wheel[arrow] != ch) { //모순 있으면 바퀴 존재x
            return false;
        }
    }
    return true;
}

int main() {
    int n, k; //바퀴의 칸 수, 바퀴를 돌리는 횟수
    cin >> n >> k;
    wheel.assign(n, '?'); //바퀴 초기화, 결정되지 않은 칸은 '?'

    vector<ci> rot_record(k); //회전한 기록 저장
    for (int i = 0; i < k; i++) {
        cin >> rot_record[i].first >> rot_record[i].second;
    }

    //출력
    if (findWheel(n, k, rot_record)) { //바퀴가 존재하면
        for (int i = n; i > 0; i--) {
            cout << wheel[(i + arrow) % n]; //바퀴는 시계방향으로 돌아감, 출력은 시계 방향이니 벡터 거꾸로 출력
        }
    } else cout << '!';

    return 0;
}