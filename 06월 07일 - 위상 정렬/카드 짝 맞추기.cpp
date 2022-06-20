//카드 짝 맞추기

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;
typedef pair<int, int> ci;

map<int, vector<ci>> card; //카드 정보 저장
int answer = INT_MAX; //조작 횟수 최솟값

//커서 이동 후 카드 뒤집을 때 키 조작 횟수 구하기
int keyInputCounter(vector<vector<int>> &board, ci start, ci dest) {
    int count1 = 0, count2 = 0; //ㄱ, ㄴ 두 가지 이동 중 최솟값을 반환

    //1. 수직 이동 후 수평 이동
    switch (abs(start.first - dest.first)) { //r 좌표값 차
        case 0:
            break;
        case 1:
            count1++; //방향키 1회 조작
            break;
        case 2:
            //출발, 중간 좌표 사이 비어있고 중간 좌표에 카드 있거나 마지막 칸이면 ctrl+방향키 1회 조작
            if (!board[(start.first + dest.first) / 2][start.second] &&
                (board[dest.first][start.second] || dest.first == 0 || dest.first == 3))
                count1++;
            else count1 += 2; //그 외에는 2회 조작
            break;
        case 3:
            //출발, 중간 좌표 사이 카드 2개인 경우 방향키 3회 조작
            if (board[1][start.second] && board[2][start.second]) count1 += 3;
                //카드 없으면 ctrl+방향키 1회 조작
            else if (!board[1][start.second] && !board[2][start.second]) count1++;
            else count1 += 2;
    }
    switch (abs(start.second - dest.second)) { //c 좌표값 차
        case 0:
            break;
        case 1:
            count1++; //방향키 1회 조작
            break;
        case 2:
            //중간, 도착 좌표 사이 비어있으면 ctrl+방향키 1회 조작(도착 좌표엔 카드 존재)
            if (!board[dest.first][(start.second + dest.second) / 2])
                count1++;
            else count1 += 2; //그 외에는 2회 조작
            break;
        case 3:
            //중간, 도착 좌표 사이 카드 2개인 경우 방향키 3회 조작
            if (board[dest.first][1] && board[dest.first][2]) count1 += 3;
                //카드 없으면 ctrl+방향키 1회 조작
            else if (!board[dest.first][1] && !board[dest.first][2]) count1++;
            else count1 += 2; //그 외에는 2회 조작
    }

    //2. 수평 이동 후 수직 이동
    switch (abs(start.second - dest.second)) { //c 좌표값 차
        case 0:
            break;
        case 1:
            count2++; //방향키 1회 조작
            break;
        case 2:
            //출발, 중간 좌표 사이 비어있고 중간 좌표에 카드 있거나 마지막 칸이면 ctrl+방향키 1회 조작
            if (!board[start.first][(start.second + dest.second) / 2] &&
                (board[start.first][dest.second] || dest.second == 0 || dest.second == 3))
                count2++;
            else count2 += 2; //그 외에는 2회 조작
            break;
        case 3:
            //출발, 중간 좌표 사이 카드 2개인 경우 방향키 3회 조작
            if (board[start.first][1] && board[start.first][2]) count2 += 3;
                //카드 없으면 ctrl+방향키 1회 조작
            else if (!board[start.first][1] && !board[start.first][2]) count2++;
            else count2 += 2; //그 외에는 2회 조작
    }
    switch (abs(start.first - dest.first)) { //r 좌표값 차
        case 0:
            break;
        case 1:
            count2++; //방향키 1회 조작
            break;
        case 2:
            //중간, 도착 좌표 사이 비어있으면 ctrl+방향키 1회 조작
            if (!board[(start.first + dest.first) / 2][dest.second])
                count2++;
            else count2 += 2; //그 외에는 2회 조작
            break;
        case 3:
            //중간, 도착 좌표 사이 카드 2개인 경우 방향키 3회 조작
            if (board[1][dest.second] && board[2][dest.second]) count2 += 3;
                //카드 없으면 ctrl+방향키 1회 조작
            else if (!board[1][dest.second] && !board[2][dest.second]) count2++;
            else count2 += 2; //그 외에는 2회 조작
    }

    return min(count1, count2) + 1; //enter 입력 횟수 더하여 반환
}

//한 쌍의 카드 뒤집는 순서 모두 탐색
void backtracking(vector<vector<int>> &board, vector<int> &image_list, int cnt, int sum, ci cursor) {
    if (cnt == image_list.size()) { //기저 조건
        answer = min(answer, sum); //최솟값 업데이트
        return;
    }

    //뒤집은 카드 삭제한 새 보드
    vector<vector<int>> new_board = board;
    new_board[card[image_list[cnt]][0].first][card[image_list[cnt]][0].second] =
    new_board[card[image_list[cnt]][1].first][card[image_list[cnt]][1].second] = 0;

    //card[image_list[cnt]][0] 뒤집은 후 card[image_list[cnt]][1] 뒤집기
    //탐색깊이 1 추가, 기존 sum에 현재cursor에서 두 카드 순서대로 이동하는 횟수 더함, 두 번째 카드 좌표가 새로운 cursor
    backtracking(new_board, image_list, cnt + 1, sum + keyInputCounter(board, cursor, card[image_list[cnt]][0]) +
                                                 keyInputCounter(board, card[image_list[cnt]][0],
                                                                 card[image_list[cnt]][1]),
                 card[image_list[cnt]][1]);

    //반대 순서로 카드 뒤집기
    backtracking(new_board, image_list, cnt + 1, sum + keyInputCounter(board, cursor, card[image_list[cnt]][1]) +
                                                 keyInputCounter(board, card[image_list[cnt]][1],
                                                                 card[image_list[cnt]][0]),
                 card[image_list[cnt]][0]);
}

int solution(vector<vector<int>> board, int r, int c) {
    //보드 탐색해 남은 카드 종류, 위치 저장
    for (int i = 0; i < 4; i++) { //보드 탐색
        for (int j = 0; j < 4; j++) {
            if (board[i][j])
                card[board[i][j]].push_back({i, j}); //카드 그림을 키값으로 좌표 저장
        }
    }

    vector<int> image_list; //카드 그림 저장해 순서 지정
    for (auto &it: card) {
        image_list.push_back(it.first); //오름차순으로 저장됨
    }

    //카드 뒤집을 순서 순열 만들어 조작 횟수 연산
    do {
        backtracking(board, image_list, 0, 0, {r, c}); //answer 최솟값으로 업데이트
    } while (next_permutation(image_list.begin(), image_list.end()));

    return answer;
}

int main() {
    vector<vector<int>> board; //보드 상태
    int r, c; //커서

    //예제 1
    board = {{1, 0, 0, 3},
             {2, 0, 0, 0},
             {0, 0, 0, 2},
             {3, 0, 1, 0}};
    r = 1, c = 0;

    //예제 2
//    board = {{3, 0, 0, 2},
//             {0, 0, 1, 0},
//             {0, 1, 0, 0},
//             {2, 0, 0, 3}};
//    r = 0, c = 1;

    cout << solution(board, r, c);

    return 0;
}