//키로커

#include <iostream>
#include <deque>

using namespace std;

//덱의 원소를 string으로 만듦
string makeStr(deque<char> &deq){
    string str;
    while (!deq.empty()) {
        str.push_back(deq.front());
        deq.pop_front();
    }
    return str;
}


//비밀번호 구한 후 반환
string findPw(string str) {
    //커서 앞, 뒤 부분에서 연산, 출력 시 비밀번호 앞에서부터 접근 - 덱 두 개 사용해 비밀번호 저장
    deque<char> pw_front; //비밀번호의 커서 앞 부분
    deque<char> pw_back; //비밀번호의 커서 뒷 부분
    string password; //완성된 비밀번호

    for (char op: str) { //문자열 처리
        switch (op) {
            case '<':
                //front의 맨 뒤 원소 하나를 back의 맨 앞으로 이동
                if (!pw_front.empty()) { //front가 비어있지 않으면
                    pw_back.push_front(pw_front.back());
                    pw_front.pop_back();
                }
                break;
            case '>':
                //back의 맨 앞 원소 하나를 front의 맨 뒤로 이동
                if (!pw_back.empty()) { //back이 비어있지 않으면
                    pw_front.push_back(pw_back.front());
                    pw_back.pop_front();
                }
                break;
            case '-':
                //front의 맨 뒤 원소 하나를 삭제
                if (!pw_front.empty()) pw_front.pop_back();
                break;
            default:
                //front에 원소 하나를 삽입
                pw_front.push_back(op);
        }
    }

    return makeStr(pw_front) + makeStr(pw_back);
}

int main() {
    int t; //테스크 케이스 개수
    string str; //입력한 문자열
    cin >> t; //입력

    while (t--) {
        cin >> str; //문자열 입력
        cout<<findPw(str)<<'\n'; //연산 및 출력
    }

    return 0;
}