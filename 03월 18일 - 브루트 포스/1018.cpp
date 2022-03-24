//1018) 체스판 다시 칠하기

#include <iostream>
#include <vector>

using namespace std;

vector<string> board;

//8 * 8 칸에서 다시 칠해야 하는 칸수를 계산
int calcRepaint(int x, int y, vector<string> b, bool repaint_first) { //vector 복사
    int cnt = 0;

    if (repaint_first) { //인자 true면 첫 번째 색을 교체 후 연산
        cnt++; //횟수 카운트
        if (b[x][y] == 'B') b[x][y] = 'W'; //색깔 교체
        else b[x][y] = 'B';
    }

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

    return cnt;
}


//m * n 보드에서 8 * 8칸을 순회하며 최솟값 계산
int findMinRepaint(int n, int m) {
    int answer = 64; //최댓값 모든 칸을 다 칠하면 8 * 8
    for (int i = 0; i < n - 7; i++) { //행 순회
        for (int j = 0; j < m - 7; j++) { //열 순회
            answer = min(answer,
                         min(calcRepaint(i, j, board, false), calcRepaint(i, j, board, true))); //최솟값으로 업데이트
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