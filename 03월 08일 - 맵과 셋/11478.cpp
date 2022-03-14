//11478)서로 다른 부분 문자열의 개수

#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    string s; //문자열 S
    //입력
    cin >> s;
    int size = s.length();
    unordered_set<string> substring; //부분 문자열 저장하는 set, 정렬할 필요 x

    //부분 문자열로 슬라이싱해서 set에 삽입하여 중복 제거
    for (int i = 0; i < size; i++) { //부분 문자열 시작 지점
        for (int j = 1; j <= size - i; j++) { //부분 문자열 길이 1부터 끝까지
            substring.insert(s.substr(i, j));
        }
    }

    //출력
    cout << substring.size();

    return 0;
}