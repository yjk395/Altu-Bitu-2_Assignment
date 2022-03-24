//1759) 암호 만들기
//[리뷰]
//브루트 포스: 모든 경우 만들어 놓고 조건 체크하기

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

//사용했을 법한 알파벳 저장하는 벡터
vector<char> alphabet;

//임시배열을 받아서 l개 알파벳으로 문자열 생성하여 반환
string makePw(vector<bool> &tmp) {
    string pw;
    for (int i = 0; i < tmp.size(); i++) { //정렬된 alphabet 벡터-> 삽입하는 대로 사전순 정렬됨
        if (tmp[i]) pw.push_back(alphabet[i]);
    }
    return pw;
}

vector<string> findPossiblePw(int l, int c) {
    vector<string> answer;
    //길이 l인 조합 생성
    vector<bool> tmp(c, false); //조합 구하기 위한 임시배열
    fill(tmp.begin(), tmp.begin() + l, true);

    do {
        answer.push_back(makePw(tmp)); //생성된 비밀번호를 벡터에 삽입
    } while (prev_permutation(tmp.begin(), tmp.end())); //이전 순열

    //조건 체크
    set<char> vowel({'a', 'e', 'i', 'o', 'u'}); //전체 알파벳 모음 set에 저장하여 모음 체크에 사용
    for (int i = 0; i < answer.size(); i++) {
        int v_cnt = 0;
        for (char c: answer[i]) { //비밀번호의 char 순회
            if (vowel.count(c)) //모음이면 카운트
                v_cnt++;
        }

        if (v_cnt < 1 || v_cnt > l - 2) { //모음 개수는 1개 이상 l-2개 이하여야 함
            answer.erase(answer.begin() + i); //아닐 경우 삭제
            i--; //삭제했으니 인덱스 되돌리기
        }
    }

    //임시배열 true가 앞인 상태에서 이전 순열 구함 -> 정렬된 상태
    return answer;
}

int main() {
    int l, c; //사용된 문자의 수, 사용했을 법한 문자의 종류
    //입력
    cin >> l >> c;
    alphabet.assign(c, '0');
    for (int i = 0; i < c; i++) {
        cin >> alphabet[i]; //벡터에 알파벳 저장
    }

    //알파벳 벡터를 오름차순 정렬하여 넘겨주면 사전순으로 순회 가능
    sort(alphabet.begin(), alphabet.end());
    vector<string> answer = findPossiblePw(l, c);

    //출력
    for (string str: answer) {
        cout << str << '\n';
    }

    return 0;
}