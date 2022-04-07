//키로커

#include <iostream>
#include <deque>

using namespace std;

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
            switch (c) {
                case '<':
                    //front의 원소 하나를 back에 이동
                    if (!pw_front_cur.empty()) { //front가 비어있지 않으면
                        pw_back_cur.push_front(pw_front_cur.back());
                        pw_front_cur.pop_back();
                    }
                    break;
                case '>':
                    //back의 원소 하나를 front에 이동
                    if (!pw_back_cur.empty()) { //back이 비어있지 않으면
                        pw_front_cur.push_back(pw_back_cur.front());
                        pw_back_cur.pop_front();
                    }
                    break;
                case '-':
                    //front의 원소 하나를 삭제
                    if (!pw_front_cur.empty()) pw_front_cur.pop_back();
                    break;
                default:
                    //front에 원소 하나를 삽입
                    pw_front_cur.push_back(c);
            }
        }

        //출력 - front에 먼저 들어간 순, back에 마지막으로 들어간 순
        while (!pw_front_cur.empty()) {
            cout << pw_front_cur.front();
            pw_front_cur.pop_front();
        }
        while (!pw_back_cur.empty()) {
            cout << pw_back_cur.front();
            pw_back_cur.pop_front();
        }
        cout << '\n';
    }

    return 0;
}