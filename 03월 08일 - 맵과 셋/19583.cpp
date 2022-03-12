//19583)싸이버개강총회

#include <iostream>
#include <set>

using namespace std;

//'HH:MM'을 분 단위로 변환하는 함수
int calcTime(string s) {
    //c++은 split 함수가 없다 글자 수로 분리
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}

int main() {
    //채팅 시각을 t라 할 때, 00:00<=t<=s && e<=t<=q인 닉네임을 카운트
    //처음~s까지의 채팅 기록일 때 닉네임을 set에 저장, e~q의 기록일 때 닉네임으로 set에서 검색
    string s, e, q, time, name;//개강총회 시작, 끝, 스트리밍 끝, 채팅 시각, 닉네임
    set<string> enter; //입장 확인이 된 닉네임 저장하는 set

    //입력
    cin >> s >> e >> q;
    int begin, end, streaming_end;
    begin = calcTime(s);
    end = calcTime(e);
    streaming_end = calcTime(q);

    //채팅 기록 입력 및 연산
    int count = 0; //출석이 확인된 학회원의 수

    while (cin >> time >> name) {
        //조건문에 쓴 거, 아래 코드 모두 백준에선 됐음
//        cin >> time >> name;
//        if (cin.eof()) break; //입력이 없으면 반복 종료

        int chat_log = calcTime(time); //채팅 기록 시각 계산

        if (chat_log <= begin) { //00:00 ~ 개강총회 시작 사이의 채팅 기록일 때
            enter.insert(name); //입장이 확인된 사람을 기록
        } else if (end <= chat_log && chat_log <= streaming_end) { //개강총회 종료 ~ 스트리밍 종료 사이의 채팅 기록일 때
            if (enter.find(name) != enter.end()) { //입장과 퇴장이 모두 확인된 사람일 때
                count++; //학회원 수 카운트
                enter.erase(name); //확인한 사람 삭제
            }
        } else if (chat_log >= streaming_end) { //스트리밍 종료 후
            break;
        }
    }

    //출력
    cout << count;
    return 0;
}