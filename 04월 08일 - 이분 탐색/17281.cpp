//⚾
/*
 * 한 팀은 9명
 * n이닝 동안 게임 진행
 * 한 이닝에 3아웃 -> 이닝 종료, 공수 교대
 * 마지막 타자까지 치고 3아웃x -> 이닝 끝나지 않고 다음 타자
 * 이닝 바뀌어도 타순 유지, 이전 이닝 마지막의 다음 타자부터
 *
 * 선수가 홈까지 진루하면 득점+=1
 * 1, 2, 3 -> 타자와 주자들 그만큼 진루, 홈런(4)->모두 홈까지 진루
 * 아웃 -> 모두 진루x, 공격팀 아웃++
 *
 * 1번 선수가 4번 타자, 다른 선수의 타순 결정하여 득점 최댓값 찾기
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int PLAYER = 9; //9명의 선수
vector<vector<int>> result; //각 선수의 각 이닝별 결과

//공을 한 번 친 후 주자가 진루하고 그 때의 득점을 반환
int run(int hit, vector<int> &runner) {
    runner.push_back(0); //타자도 함께 진루
    int point = 0;

    //홈런인 경우
    if (hit == 4) {
        point = runner.size(); //주자 수만큼 득점
        runner.clear(); //모든 주자가 홈에 들어옴, 모두 삭제
        return point;
    }

    //안타, 2루타, 3루타인 경우
    for (int i = 0; i < runner.size(); i++) {
        runner[i] += hit; //1, 2, 3루씩 진루
        if (runner[i] >= 4) { //홈에 도착하면
            point++; //득점
            runner.erase(runner.begin() + i); //해당 주자 삭제
            i--; //삭제했으니 인덱스 되돌림
        }
    }
    return point;
}

//결정된 타순을 받아 게임 진행 후 득점 반환
int playGame(int n, vector<int> lineup) {
    lineup.insert(lineup.begin() + 3, 0); //1번 선수(인덱스 0)를 4번 타자로 추가
    int score = 0; //전체 득점
    int lineup_pointer = 0; //타순은 이닝이 변경되어도 순서 유지, 인덱스 저장

    for (int inning = 0; inning < n; inning++) { //n이닝까지 반복
        int out = 0; //아웃 횟수
        vector<int> runner; //주자(루에 있는 선수)의 위치

        while (out < 3) { //3아웃이 발생하기 전까지 다음 타자가 공을 침, 3아웃이면 한 이닝 종료
            int hit = result[inning][lineup[lineup_pointer]]; //타자의 결과

            if (!hit) out++; //0이면 아웃
            else score += run(hit, runner); //공을 친 결과에 따라 진루하고 득점 업데이트

            lineup_pointer = (lineup_pointer + 1) % PLAYER; //다음 타자로
        }
    }
    return score;
}


//최대 득점 반환
int findMaxScore(int n) {
    int ans = 0; //최대 득점
    vector<int> lineup = {1, 2, 3, 4, 5, 6, 7, 8}; //1번 선수를 제외한 타순

    //9명의 선수 -> 모든 경우 연산, 순열로 타순 결정
    do {
        //타순 결정한 상태에서 게임 진행 후 결과값과 기존 ans 중 최댓값 업데이트
        ans = max(ans, playGame(n, lineup));
    } while (next_permutation(lineup.begin(), lineup.end()));

    return ans;
}

int main() {
    int n; //이닝 수
    cin >> n;
    //각 선수가 각 이닝에서 얻는 결과 입력
    result.assign(n, vector<int>(PLAYER, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < PLAYER; j++) {
            cin >> result[i][j];
        }
    }

    //출력
    cout << findMaxScore(n);

    return 0;
}