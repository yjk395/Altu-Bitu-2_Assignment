//2048 (Easy)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int answer = 0;

//게임판의 블록 중 최댓값 반환
int findMaxBlock(int n, vector<vector<int>> &board) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result = max(result, *max_element(board[i].begin(), board[i].end()));
    }
    return result;
}

//왼쪽으로 블록 이동(뿌요뿌요..)
vector<vector<int>> moveBlock(int n, vector<vector<int>> &board) {
    vector<vector<int>> new_board(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        queue<int> temp; //이동할 블록 저장
        for (int j = 0; j < n; j++) {
            if (board[i][j]) temp.push(board[i][j]); //숫자블록이면 큐에 삽입
        }

        int idx = 0;
        while (!temp.empty()) {
            int block = temp.front(); //블록 가져옴
            temp.pop(); //가져온 블록 삭제
            if (!temp.empty() && temp.front() == block) { //다음 블록 있고 같은 블록이면 합치기
                block *= 2;
                temp.pop();
            }
            new_board[i][idx++] = block; //블록 이동
        }
    }
    return new_board; //이동 완료한 게임판 리턴
}

//게임판 90도 회전
vector<vector<int>> rotateBoard(int n, vector<vector<int>> &board) {
    vector<vector<int>> new_board(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            new_board[i][j] = board[n - j - 1][i];
        }
    }
    return new_board;
}

//4방향 5번 이동 모두 탐색
void bf(int n, vector<vector<int>> board, int cnt) {
    if (cnt == 5) { //5번 이동 완료(기저조건)
        answer = max(answer, findMaxBlock(n, board)); //게임판에서 max값 찾아서 답 업데이트
        return;
    }

    for (int i = 0; i < 4; i++) { //4방향 이동
        bf(n, moveBlock(n, board), cnt + 1);
        board = rotateBoard(n, board); //게임판 회전(이동 방향 바꿈)
    }
}

int main() {
    int n; //보드의  크기
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0)); //게임판

    //게임판 초기 상태 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    bf(n, board, 0);

    //출력
    cout << answer;

    return 0;
}