//비슷한 단어

#include <iostream>
#include <vector>

using namespace std;

//알파벳 종류별 개수 세는 함수
void countAlp(vector<int> &freq_alp, string word) {
    for (int i = 0; i < word.length(); i++) {
        freq_alp[word[i] - 'A']++; //해당 문자 인덱스의 원소 증가
    }
}

//비슷한 단어 개수 찾기
int solution(vector<string> &words, int n) {
    int answer = 0;
    //알파벳 종류별 개수 세는 벡터
    vector<int> freq_alp_first(26, 0);
    vector<int> freq_alp_other(26, 0);

    int length = words[0].length(); //첫 번째 단어의 길이

    //첫 단어의 알파벳 종류별 개수 세기
    countAlp(freq_alp_first, words[0]);

    for (int i = 1; i < n; i++) { //나머지 모든 단어
        int diff = 0; //두 단어 알파벳 차이 나는 개수
        fill(freq_alp_other.begin(), freq_alp_other.end(), 0); //알파벳 개수 벡터 초기화
        countAlp(freq_alp_other, words[i]); //알파벳 개수 세기

        for (int j = 0; j < 26; j++) { //알파벳 차이 계산
            diff += abs(freq_alp_first[j] - freq_alp_other[j]);
        }

        //개수 같으면 같은 구성, 하나 차이면 한 문자 더하거나 빼기, 둘 차이면 문자 바꾸기(=길이 동일)
        if(diff==0||diff==1||(diff==2&&(words[i].length()==length))){
            answer++;
        }
    }
    return answer;
}

int main() {
    int n; //단어 개수
    cin >> n;

    vector<string> words(n); //입력받은 단어 저장
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    //출력
    cout<<solution(words, n);

    return 0;
}