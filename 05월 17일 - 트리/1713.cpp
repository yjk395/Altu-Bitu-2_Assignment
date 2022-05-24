//후보 추천하기

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci;

//비교 함수 1.추천 받은 횟수가 적은 순 2.게시된 지 오래된 순
bool cmp(pair<const int, ci> &a, pair<const int, ci> &b) {
    if (a.second.first != b.second.first) return a.second.first < b.second.first;
    return a.second.second < b.second.second;
}

int main() {
    int n, m, p; //사진틀의 개수, 총 추천 횟수, 학생 번호
    cin >> n >> m;

    map<int, ci> frame; //사진틀에 게시된 학생 번호, 추천받은 횟수, 추천받은 순서
//    int rcm_order = 0; //사진틀에 사진이 게시될 때마다 카운트

    //[코드리뷰] 추천순서 계속 증가->for반복문 인자 사용하기, 반복횟수도 m 고정
    for (int i = 0; i < m; i++) {
        cin >> p; //추천받은 학생 번호

//        //사진틀에 게시되어 있으면 추천 횟수 카운트하고 넘어감
//        if (frame.count(p) == 1) {
//            frame[p].first++; //아래 사진틀에 사진 게시랑 코드 중복->첫 게시를 if문으로 바꾸기
//            continue;
//        }

        //비어있는 사진틀 없는 경우 삭제
        if (frame.size() == n && !frame.count(p)) { //입력학생 사진틀에 있으면 continue 코드 삭제했으니 조건 추가
            frame.erase(min_element(frame.begin(), frame.end(), cmp));
        }

        //사진틀에 사진 게시
        if (!frame.count(p)) { //사진틀에 없으면
            frame[p].second = i; //추천받은 순서
        }

        frame[p].first++; //추천 횟수 증가
//        rcm_order++; //반복문 인자로
    }

    //출력, map -> 학생 번호 증가 순
    for (auto it: frame) {
        cout << it.first << ' ';
    }

    return 0;
}