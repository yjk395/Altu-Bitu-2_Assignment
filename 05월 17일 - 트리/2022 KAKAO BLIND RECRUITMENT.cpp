//양궁대회

/*
 * 과녁을 맞히는 모든 경우
 * 11개짜리 bool 임시벡터로 모든 순열 구함, true일 때 내가 점수 획득
 * 점수 획득하는 과녁 수 1개~총 화살 개수인 n개, for 1부터 n까지
 * 이기지 못하거나 화살 모자라면 버림, 점수 차 max인 경우 찾기
 * 그 중 낮은 점수를 더 많이 맞힌 경우 고르기
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//필요한 화살 개수에 부합하는지 체크, 상대방과 점수 차 계산, 화살상태 나타내는 벡터 저장됨
int scoreCalc(int n, vector<bool> &is_get_score, vector<int> &arrow, vector<int> &info) {
    int arrow_cnt = 0, my_score = 0, other_score = 0;
    for (int i = 0; i < 11; i++) {
        if (!is_get_score[i]) { //상대방 점수 획득, 내 화살 0개 사용
            if (info[i] != 0) other_score += 10 - i; //둘 모두 화살 0개이면 득점x, 상대 득점하기로 한 상황에 상대 화살도 0개 아닐 때 점수 카운트
        } else {
            my_score += 10 - i; //내가 점수 획득
            arrow_cnt += info[i] + 1; //화살 개수는 상대방이 쏜 거+1
            if (arrow_cnt > n) return -1; //화살 모자라면

            arrow[i] = info[i] + 1; //상대보다 1 많은 화살 사용
        }
    }
    if (my_score <= other_score) return -1; //우승하지 못하면

    if (arrow_cnt < n) arrow[10] += n - arrow_cnt; //남은 화살은 제일 낮은 과녁점수에 몰기
    return my_score - other_score; //점수차 반환
}

//ans가 other보다 낮은 점수를 더 많이 맞혔는지
bool isLowerScoreHit(vector<int> &ans, vector<int> &other) {
    for (int j = 10; j >= 0; j--) { //낮은 점수 과녁부터 비교
        if (ans[j] < other[j]) return false;
        if (ans[j] > other[j]) return true;
    }
    return false; //전부 같으면 아예 동점인 상황..? 오류뜨길래 추가
}

vector<int> solution(int n, vector<int> info) {
    int max = 0; //점수차 최대값
    vector<vector<int>> myArrows(0, vector<int>(11, 0)); //내 화살 배분 후보

    vector<bool> is_get_score(11, false); //점수 획득하면 true, 상대가 획득하면 false
    for (int i = 1; i <= n; i++) {
        fill(is_get_score.begin(), is_get_score.begin() + i, true);
        do {
            //화살 개수 체크
            vector<int> arrow(11, 0); //scoreCalc에서 만든 화살 상태 벡터 저장
            int res = scoreCalc(n, is_get_score, arrow, info); //점수 차 혹은 -1(불가능)

            if (res >= max) {
                if (res > max) { //max 바뀌면
                    myArrows.clear(); //저장해온 정보 초기화
                    max = res;
                }
                myArrows.push_back(arrow); //정답 후보에 추가
            }
        } while (prev_permutation(is_get_score.begin(), is_get_score.end())); //순열 구하기
    }

    if (myArrows.empty()) return {-1}; //우승할 방법이 없는 경우

    //화살상태 후보 중 낮은 점수 많이 맞힌 경우 찾아 반환
    vector<int> answer = myArrows[0];
    for (int i = 1; i < myArrows.size(); i++) {
        if (!isLowerScoreHit(answer, myArrows[i])) answer = myArrows[i]; //다른 벡터가 낮은 점수 더 맞혔으면 answer 업데이트
    }
    return answer;
}

int main() {
    int n; //화살 개수
    vector<int> info; //상대가 맞힌 과녁 점수 개수, 전역변수에 뒀다가 프로그래머스 제출한다고 옮겨옴
    info.assign(11, 0); //상대가 맞힌 과녁 점수 개수
    cin >> n;
    for (int i = 0; i < 11; i++) {
        cin >> info[i];
    }

    vector<int> ans = solution(n, info);

    //출력
    if (ans.size() == 1) cout << "-1";
    else {
        for (int i = 0; i < 11; i++) {
            cout << ans[i] << ',';
        }
    }

    return 0;
}