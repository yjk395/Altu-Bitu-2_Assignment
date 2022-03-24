//1759) 암호 만들기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//사용했을 법한 자음, 모음 알파벳 저장하는 벡터
vector<char> consonant;
vector<char> vowel;

//자음, 모음에서 선택된 수를 string에 추가
void makePw(string &str, vector<bool> &temp, vector<char> &alp) {
    for (int i = 0; i < temp.size(); i++) {
        if(temp[i]){
            str.push_back(alp[i]);
//            cout<<alp[i]<<' ';
        }
    }
}

//가능성 있는 암호를 모두 저장한 벡터를 구하는 함수
vector<string> findPossiblePw(int l) {
    //조합 구하기 위한 임시 벡터
    vector<bool> c_temp(consonant.size(), false);
    vector<bool> v_temp(vowel.size(), false);

    string str;
    vector<string> answer;

    for (int i = 1; i <= l - 2; i++) { //모음을 i개 선택
        fill(v_temp.begin(), v_temp.begin() + i - 1, true); //임시벡터 수정
        fill(c_temp.begin(), c_temp.begin() + l - i - 1, true);

        do {
            makePw(str, v_temp, vowel); //선택된 모음을 string에 추가
            string str_tmp = str;
            //자음 조합 구하기
            do {
                makePw(str, c_temp, consonant); //선택된 자음을 string에 추가
                sort(str.begin(), str.end());
                answer.push_back(str);
                str = str_tmp;
            } while (prev_permutation(c_temp.begin(), c_temp.end()));
        } while (prev_permutation(v_temp.begin(), v_temp.end()));
    }

    sort(answer.begin(), answer.end());
    return answer;

}

//l개 중 1개 이상의 모음 선택, 나머진 자음 선택하고 알파벳을 사전순 배치
//1<=i<=l-2 탐색하며 모음 i개, 자음 l-i개 조합 선택해 string으로 붙이고 sort하여 answer 벡터에 삽입
//사전식 출력->answer 벡터도 정렬되어 있어야 함
int main() {
    int l, c; //사용된 문자의 수, 사용했을 법한 문자의 종류
    //입력
    cin >> l >> c;

    while (c--) {
        char alp;
        cin >> alp;
        if (alp == 'a' || alp == 'e' || alp == 'i' || alp == 'o' || alp == 'u') //입력 알파벳이 모음인 경우
            vowel.push_back(alp);
        else consonant.push_back(alp); //자음인 경우
    }

    vector<string> answer = findPossiblePw(l);

    //출력
    for (string str: answer) {
        cout << str << '\n';
    }

    return 0;
}