//20920)영단어 암기는 괴로워

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string, int> words; //단어를 key로, 개수를 value로 저장

//개수 세기(20291, 9357 문제와 동일)
void countInMap(string word) {
    auto iter = words.find(word);
    if (iter == words.end()) { //새로운 단어
        words[word] = 1; //map에 삽입, 개수는 1
    } else { //이미 map에 저장된 단어
        (iter->second)++; //개수 1 증가
    }
}

//비교 함수
bool cmp(const pair<string, int> &p1, const pair<string, int> &p2) {
    if (p1.second != p2.second) { //1. 나온 횟수가 다른 경우 자주 나온 단어를 앞에 배치
        return p1.second > p2.second;
    }
    if (p1.first.length() != p2.first.length()) { //2. 단어의 길이가 다른 경우 길이가 길수록 앞에 배치
        return p1.first.length() > p2.first.length();
    }
    return p1.first < p2.first; //3. 알파벳 사전 순으로 배치
}

int main() {
    int n, m; //모든 단어의 개수, 외울 단어의 최소 길이
    //입력
    cin >> n >> m;

    while (n--) {
        string word; //입력받는 단어
        cin >> word;
        if (word.length() < m) { //길이가 m 미만인 단어는 외우지 않음
            continue;
        }

        countInMap(word); //map에 삽입 혹은 개수 업데이트
    }

    //정렬
    vector<pair<string, int>> vec(words.begin(), words.end());
    sort(vec.begin(), vec.end(), cmp);

    //출력
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i].first << '\n';
    }

    return 0;
}