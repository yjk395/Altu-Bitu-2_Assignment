//20920)영단어 암기는 괴로워

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string, int> words; //단어를 key로, 개수를 value로 저장

//개수 세기(20291, 9357 문제와 동일)
//void countInMap(string word) {
//    auto iter = words.find(word);
//    if (iter == words.end()) { //새로운 단어
//        words[word] = 1; //map에 삽입, 개수는 1
//    } else { //이미 map에 저장된 단어
//        (iter->second)++; //개수 1 증가
//    }
//}

//비교 함수
//bool cmp(const pair<string, int> &p1, const pair<string, int> &p2) {
//    if (p1.second != p2.second) { //1. 나온 횟수가 다른 경우 자주 나온 단어를 앞에 배치
//        return p1.second > p2.second;
//    }
//    if (p1.first.length() != p2.first.length()) { //2. 단어의 길이가 다른 경우 길이가 길수록 앞에 배치
//        return p1.first.length() > p2.first.length();
//    }
//    return p1.first < p2.first; //3. 알파벳 사전 순으로 배치
//}

//[리뷰]
//vector에 단어만 저장했으니 인자도 string 두 개, 등장 횟수(전역변수인 map의 value)는 바로 접근 가능
bool cmp_rev(const string &a, const string &b) {
    if (words[a] != words[b]) { //1. 자주 나오는 단어일수록 앞에 배치
        return words[a] > words[b];
    }
    if (a.length() != b.length()) { //2. 해당 단어의 길이가 길수록 앞에 배치
        return a.length() > b.length();
    }
    return a < b; //3. 알파벳 사전 순으로 배치

}

int main() {
    //[리뷰] vector에 string 중복없이 저장 및 정렬, 카운트는 map에서 하고 cmp함수에서 map에 바로 접근
    vector<string> words_str;

    string word; //입력받는 단어
    int n, m; //모든 단어의 개수, 외울 단어의 최소 길이
    //입력
    cin >> n >> m;

    while (n--) {
        cin >> word;
        if (word.length() < m) { //길이가 m 미만인 단어는 외우지 않음
            continue;
        }

        //[리뷰] map에 key 존재 여부 확인해 중복 방지, 논리 부정 연산자로 판단 가능
        //없는 경우 value값 0 -> 부정하면 조건문 true
        if (!words[word]) {
            words_str.push_back(word); //vector의 끝에 요소 추가, vector의 크기 1 늘어남(자동 재할당)
        }

        //[리뷰] 단어 등장 횟수 증가
//        countInMap(word); //map에 삽입 혹은 개수 업데이트
        words[word]++;
    }

    //정렬
//    vector<pair<string, int>> vec(words.begin(), words.end());
//    sort(vec.begin(), vec.end(), cmp);
    sort(words_str.begin(), words_str.end(), cmp_rev);


    //출력
    for (int i = 0; i < words_str.size(); i++) {
        cout << words_str[i] << '\n';
    }

    return 0;
}