//강의실 배정

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci;

//강의 목록을 받아서 필요한 최소 강의실 개수를 반환
int classroonNum(int n, vector<ci> &classes) {
//    multiset<int, greater<int>> classroom; //길이가 강의실 개수, 수업이 끝나는 시각 저장
    priority_queue<int, vector<int>, greater<>> classroom; //길이가 강의실 개수, 강의실 별로 수업이 끝나는 시각을 오름차순 저장
    for (int i = 0; i < n; i++) {
        auto[start, end] = classes[i];

        //강의 목록은 이미 시작 시간으로 오름차순 정렬됨, 시간차 가장 적은 강의실 찾을 필요x
        //강의실도 내림차순이 아닌 오름차순 정렬 후 가장 앞 원소만 확인 -> 우선순위 큐
//        for (auto iter = classroom.begin(); iter != classroom.end(); iter++) {
//            if (*iter <= start) {
//                classroom.erase(iter);
//                break;
//            }
//        }
//        classroom.insert(end);
        if (!classroom.empty() && classroom.top() <= start) {
            classroom.pop(); //기존 강의실 이어 쓸 수 있으면 삭제 후 새로 삽입하여 시각 업데이트
        }
        classroom.push(end); //강의실 사용 종료 시각 삽입
    }

    return classroom.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; //수업의 개수
    //입력
    cin >> n;
    vector<ci> classes(n, {0, 0});
    for (int i = 0; i < n; i++) {
        cin >> classes[i].first >> classes[i].second;
    }

    sort(classes.begin(), classes.end()); //강의 목록을 1.시작시각 2.종료시각으로 오름차순 정렬

    //출력
    cout << classroonNum(n, classes);

    return 0;
}