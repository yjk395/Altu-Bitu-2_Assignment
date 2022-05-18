//오목

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> checkerboard(20, vector<int>(20, 0)); //바둑판
vector<vector<vector<bool>>> visited(20, vector<vector<bool>>(20, vector<bool>(4, false))); //방문여부

//탐색 방향: [0]오른쪽위(1, -1), [1]오른쪽(1, 0), [2]오른쪽아래(1, 1), [3]아래(0, 1)
vector<int> dx{1, 1, 1, 0};
vector<int> dy{-1, 0, 1, 1};

//전달받는 바둑돌의 x, y좌표, 색, 연속된 바둑 개수, 탐색 방향
bool omokChecker(int x, int y, int color, int cnt, int dir) {
    visited[y][x][dir] = true; //방문체크
    if (cnt == 5) { //6번째 바둑돌 체크
        if (x + dx[dir] > 0 && x + dx[dir] < 20 && y + dy[dir] > 0 && y + dy[dir] < 20 &&
            checkerboard[y + dy[dir]][x + dx[dir]] == color) { //육목이면
            return false;
        }
        return true; //오목
    }

    //바둑판 범위 벗어나지 않고 같은 색 연속이면
    if (x + dx[dir] > 0 && x + dx[dir] < 20 && y + dy[dir] > 0 && y + dy[dir] < 20 &&
        checkerboard[y + dy[dir]][x + dx[dir]] == color) {
        return omokChecker(x + dx[dir], y + dy[dir], color, cnt + 1, dir); //재귀호출
    } else {
        return false;
    }
}

//브루트 포스
//[코드리뷰] 바둑돌이 없는 경우를 continue
bool bf(int &color, int &x, int &y) {
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j < 20; j++) {
            if (!checkerboard[i][j]) continue; //바둑돌 없으면 넘어감
            //리턴값 true면 오목, 바둑돌 색과 좌표 출력, 방문한 방향은 탐색x
            for (int k = 0; k < 4; k++) {
                if (visited[i][j][k] || !omokChecker(j, i, checkerboard[i][j], 1, k)) continue;

                //탐색하는 반대 방향 바둑돌 확인(육목 가능)
                if (i - dy[k] > 0 && i - dy[k] < 20 && j - dx[k] > 0 && j - dx[k] < 20 &&
                    checkerboard[i - dy[k]][j - dx[k]] == checkerboard[i][j])
                    continue;

                color = checkerboard[i][j];
                x = i;
                y = j;
                return true;
            }
        }
    }

    return false;
}

int main() {
    int color, x, y; //이긴 팀 색, 바둑알 가로세로줄 번호
    //입력
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j < 20; j++) {
            cin >> checkerboard[i][j];
        }
    }

    //출력
    if (bf(color, x, y)) {
        cout << color << '\n' << x << ' ' << y;
    } else {
        cout << "0";
    }

    return 0;
}