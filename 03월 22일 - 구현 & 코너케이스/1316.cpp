//1316)그룹 단어 체커

#include <iostream>
#include <set>

using namespace std;

//단어 하나를 받아서 그룹 단어인지 판별
bool isGroup(string str) {
    set<char> used_alp; //나온 알파벳 저장하는 set

    for (int i = 1; i < str.length(); i++) { //두 번째 인덱스부터 문자 순회, 길이 1인 단어는 무시
        if (str[i - 1] != str[i]) { //앞 글자와 다른 문자이면
            if (used_alp.count(str[i])) { //새로 나온 문자가 앞에서 이미 나왔으면
                return false;
            }
            used_alp.insert(str[i - 1]); //연속이 끊긴 앞 문자를 set에 삽입
        }
    }
    return true;
}

int main() {
    int n; //단어의 개수
    string word; //입력받는 단어
    //입력
    cin >> n;

    int answer = 0; //그룹 단어의 개수
    while (n--) {
        cin >> word;
        if (isGroup(word)) answer++; //그룹 단어이면 카운트
    }

    //출력
    cout << answer;
    return 0;
}