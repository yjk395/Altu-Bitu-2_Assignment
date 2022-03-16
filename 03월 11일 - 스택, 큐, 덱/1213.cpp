//1213)팰린드롬 만들기

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<char, int> alphabet_cnt; //알파벳과 개수를 중복 없이 사전순 정렬하여 저장

//map 정보로 팰린드롬 만들어 결과 반환
string makePalindrome() {
    string front; //팰린드롬 결과의 앞 절반 부분
    string middle = ""; //중간 부분

    //map 순회하며 연산
    for (auto iter = alphabet_cnt.begin(); iter != alphabet_cnt.end(); iter++) {
        int cnt = iter->second; //알파벳의 개수 가져오기

        if (cnt % 2) { //알파벳 개수 홀수일 때
            if (middle != "") { //이미 하나만 남은 알파벳(가운데 자리 차지)이 있다면
                return "I'm Sorry Hansoo"; //불가능, 함수 호출 종료
            }
            middle = iter->first; //가운데 글자는 해당 알파벳
            cnt--;
        }
        front.append(cnt / 2, iter->first); //뒤에 알파벳 삽입
    }

    //결과
    string result = front; //앞 문자열
    result.append(middle); //중간 알파벳 삽입, 개수가 짝수일 경우 ""삽입
    reverse(front.begin(), front.end()); //앞 절반 부분 역순으로 뒤집기
    result.append(front); //뒤집은 문자열 이어붙이기
    return result;
}

int main() {
    string name; //영어 이름
    //입력
    cin >> name;

    for (char alp: name) { //알파벳으로 분리하여 map에 삽입, 개수 카운트
        alphabet_cnt[alp]++;
    }

    //출력
    cout << makePalindrome();

    return 0;
}