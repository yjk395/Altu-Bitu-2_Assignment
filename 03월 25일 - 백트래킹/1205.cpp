//1205)등수 구하기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findScore(int p, int score, vector<int> &list) {
    int answer = 1;
    for (int i = 0; i < p; i++) {
        if (score > list[i]) { //새로운 점수가 더 크면 반환
            return answer;
        } else if (score == list[i]) { //같은 점수면 동점 처리하고 다음 점수가 더 작은지 다시 확인
            answer--;
        }
        answer++;
    }
    return -1; //이전보다 더 좋지 않은 점수이면
}

int main() {
    int n, new_score, p; //점수의 개수, 새로운 점수, 올라갈 수 있는 점수의 개수
    //입력
    cin >> n >> new_score >> p;
    vector<int> score_list(p, -1);
    for (int i = 0; i < n; i++) { //n이 0이면 입력x
        cin >> score_list[i];
    }

    //출력
    cout << findScore(p, new_score, score_list);
    return 0;
}