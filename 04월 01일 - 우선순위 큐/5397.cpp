//키로커

#include <iostream>
#include <deque>

using namespace std;

//커서 이동 -> q1의 원소 하나를 q2로 이동
void moveCursor(deque<char> &q1, deque<char> &q2){
    if (!q1.empty()) { //front가 비어있지 않으면
        q2.push_back(q1.back()); //front와 back 덱의 들어가는 위치를 뒤로 통일
        q1.pop_back();
    }
}

void updatePw(char op, deque<char> &front, deque<char> &back){
    switch (op) {
        case '<':
            //front의 원소 하나를 back에 이동
//            if (!front.empty()) { //front가 비어있지 않으면
//                back.push_front(front.back());
//                front.pop_back();
//            }
            moveCursor(front, back);
            break;
        case '>':
            //back의 원소 하나를 front에 이동
//            if (!back.empty()) { //back이 비어있지 않으면
//                front.push_back(back.front());
//                back.pop_front();
//            }
            moveCursor(back, front);
            break;
        case '-':
            //front의 원소 하나를 삭제
            if (!front.empty()) front.pop_back();
            break;
        default:
            //front에 원소 하나를 삽입
            front.push_back(op);
    }
}

int main() {
    int t; //테스크 케이스 개수
    string str; //입력한 문자열
    cin >> t; //입력

    while (t--) {
        //커서 앞, 뒤 부분에서 연산, 출력 시 비밀번호 앞에서부터 접근 - 덱 두 개 사용해 비밀번호 저장
        deque<char> pw_front_cur;
        deque<char> pw_back_cur;

        cin >> str; //문자열 입력
        for (char c: str) { //문자열 처리
            updatePw(c, pw_front_cur, pw_back_cur);
        }

        //출력 - front에 먼저 들어간 순, back에 마지막으로 들어간 순
        //앗 앞에서 커서 뒷 부분 덱의 삽입 위치를 바꾸고 보니 여기는 함수화하기 애매할까요..
        while (!pw_front_cur.empty()) {
            cout << pw_front_cur.front();
            pw_front_cur.pop_front();
        }
        while (!pw_back_cur.empty()) {
            cout << pw_back_cur.back(); //back은 뒤에서부터 출력
            pw_back_cur.pop_back();
        }
        cout << '\n';
    }

    return 0;
}