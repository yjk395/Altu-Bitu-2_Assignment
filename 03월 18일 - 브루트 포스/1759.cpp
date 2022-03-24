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
        if (temp[i]) {
            str.push_back(alp[i]);
//            cout<<alp[i]<<' '; //디버깅
        }
    }
}

//가능성 있는 암호를 모두 저장한 벡터를 구하는 함수
vector<string> findPossiblePw(int l) {
    //조합 구하기 위한 임시 벡터
    vector<bool> c_temp(consonant.size(), true);
    vector<bool> v_temp(vowel.size(), false);

    string str;
    vector<string> answer;

    int v_size = vowel.size(); //l-2가 가능한 모음 개수보다 큰 경우 있음 나머지 개수만큼은 비어버림. 둘 중 작은 것으로 고름

    //모음, 자음 모두 선택해야 하는 경우..
    for (int i = 1; i <= min(v_size, l - 2); i++) { //모음을 i개 선택
//        fill(v_temp.begin(), v_temp.begin() + i, true); //임시벡터 수정
        v_temp[i-1] = true; //임시 벡터 수정

        //남은 자음 수로 암호 길이 충족 안 되는 경우 모음 수 늘려야 함
        if(c_temp.size() < l-i) continue;

        if(c_temp.size() > l-i) //모든 자음 선택해야 하는 경우는 false로 바꾸지 않음
            fill(c_temp.begin(), c_temp.end() - (l - i), false); //모음은 선택 개수 점점 줄어듦->false를 증가시킴

        //디버깅
//        for(bool b:c_temp){
//            cout<<b<<' ';
//        }
//        cout<<'\n';

        do {
            makePw(str, v_temp, vowel); //선택된 모음을 string에 추가
            string str_tmp = str;
            //자음 조합 구하기
            do {
                makePw(str, c_temp, consonant); //선택된 자음을 string에 추가
                sort(str.begin(), str.end()); //암호 사전식 정렬
                answer.push_back(str); //결과 벡터에 삽입
                str = str_tmp; //반복 위해 초기화
//                cout<<'\n'; //디버깅
            } while (next_permutation(c_temp.begin(), c_temp.end()));
            str = ""; //반복 위해 초기화
        } while (prev_permutation(v_temp.begin(), v_temp.end()));
    }

    sort(answer.begin(), answer.end()); //결과 벡터 사전식 정렬
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