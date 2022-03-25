//1018) 체스판 다시 칠하기

#include <iostream>
#include <vector>

using namespace std;

const int BOARD_SIZE = 64;
vector<string> board;

//8 * 8 칸에서 다시 칠해야 하는 칸수를 계산
//int calcRepaint(int x, int y, vector<string> b, bool repaint_first) { //vector 복사
//    int cnt = 0;
//
//    if (repaint_first) { //인자 true면 첫 번째 색을 교체 후 연산
//        cnt++; //횟수 카운트
//        if (b[x][y] == 'B') b[x][y] = 'W'; //색깔 교체
//        else b[x][y] = 'B';
//    }
//
//    for (int i = x; i < x + 8; i++) { //행 순회
//        //행의 첫 칸 색칠 확인
//        if (i > x && b[i][y] == b[i - 1][y]) { //두 번째 행부터, 전 행과 같은 색이면
//            cnt++; //횟수 카운트
//            if (b[i][y] == 'B') b[i][y] = 'W'; //색깔 교체
//            else b[i][y] = 'B';
//        }
//
//        for (int j = y + 1; j < y + 8; j++) { //두 번째 열부터 순회
//            if (b[i][j] == b[i][j - 1]) { //앞 열과 같은 색이면
//                cnt++; //횟수 카운트
//                if (b[i][j] == 'B') b[i][j] = 'W'; //색깔 교체
//                else b[i][j] = 'B';
//            }
//        }
//    }
//
//    return cnt;
//}

//[리뷰]시작하는 칸 B, W일 때 만들어야 하는 최종 모습 반대 -> 바꿔야 하는 칸도 반대
int calcRepaint(int x, int y, vector<string> b) { //vector 복사
    int cnt = 0;

    for (int i = x; i < x + 8; i++) { //행 순회
        //행의 첫 칸 색칠 확인
        if (i > x && b[i][y] == b[i - 1][y]) { //두 번째 행부터, 전 행과 같은 색이면
            cnt++; //횟수 카운트
            if (b[i][y] == 'B') b[i][y] = 'W'; //색깔 교체
            else b[i][y] = 'B';
        }

        for (int j = y + 1; j < y + 8; j++) { //두 번째 열부터 순회
            if (b[i][j] == b[i][j - 1]) { //앞 열과 같은 색이면
                cnt++; //횟수 카운트
                if (b[i][j] == 'B') b[i][j] = 'W'; //색깔 교체
                else b[i][j] = 'B';
            }
        }
    }

    return min(cnt, BOARD_SIZE - cnt); //첫 번째 칸 주어진 대로, 색 바꾸는 경우 중 최솟값 리턴
}

/* [리뷰] 샘플코드
 * 완성된 보드의 색 배치, 인덱스마다 무슨 색이어야 하는지 이미 알고 있음
 * 첫 번째 칸([0][0]) B일 때 i+j가 짝수면 B, 홀수면 W -> 행열 순회하면서 색이 다르면 카운트
 * if((i + j) % 2 == 0 && board[x + i][y + j] != 'B') cnt++; 짝수일 때 B가 아니면 색 교체해야 하니 카운트
 * else if((i + j+ % 2 && board[x + i][y + j] != 'W') cnt++; 홀수일 때 W가 아니면 카운트
 * 첫 번째 칸이 W일 때는 BOARD_SIZE - cnt -> cnt가 BOARD_SIZE / 2보다 작으면 최솟값인 cnt를 반환
 */

//m * n 보드에서 8 * 8칸을 순회하며 최솟값 계산
int findMinRepaint(int n, int m) {
    int answer = BOARD_SIZE; //최댓값 모든 칸을 다 칠하면 8 * 8
    for (int i = 0; i < n - 7; i++) { //행 순회
        for (int j = 0; j < m - 7; j++) { //열 순회
            answer = min(answer, calcRepaint(i, j, board)); //최솟값으로 업데이트
        }
    }
    return answer;
}

using namespace std;

int main() {
    int n, m; //m * n 크기의 보드
    //입력
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        board.push_back(str);
    }

    //출력
    cout << findMinRepaint(n, m);

    return 0;
}