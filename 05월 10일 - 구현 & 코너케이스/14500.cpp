//테트로미노

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> paper; //종이에 쓰인 수
vector<vector<bool>> visited; //방문 기록

int n, m; //세로, 가로 크기
int max_sum = 0;

//상하좌우
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};

//깊이 우선 탐색으로 최댓값 찾기
void dfs(int r, int c, int sum, int cnt) {
    if (cnt == 3) { //정사각형 4개 이어붙었으면
        max_sum = max(max_sum, sum); //최댓값 업데이트
        return;
    }

    for (int k = 0; k < 4; k++) { //4방향
        int new_r = r + di[k];
        int new_c = c + dj[k];
        //종이 범위 벗어나지 않고 방문하지 않은 칸
        if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && !visited[new_r][new_c]) {
            visited[new_r][new_c] = true; //방문처리

            dfs(new_r, new_c, sum + paper[new_r][new_c], cnt + 1);

            visited[new_r][new_c] = false;
        }
    }
}

//보라색 ㅜ 블럭으로 만들어지는 합 따로 찾기
void purpleTet1(int r, int c) {
    int sum = 0; //칸에 쓰인 수의 합

    sum += paper[r][c];
    sum += paper[r][c + 1];
    sum += paper[r][c + 2];
    sum += paper[r + 1][c + 1];

    max_sum = max(max_sum, sum);
}

void purpleTet2(int r, int c) {
    int sum = 0;

    sum += paper[r + 1][c];
    sum += paper[r + 1][c + 1];
    sum += paper[r + 1][c + 2];
    sum += paper[r][c + 1];

    max_sum = max(max_sum, sum);
}

void purpleTet3(int r, int c) {
    int sum = 0;

    sum += paper[r][c];
    sum += paper[r + 1][c];
    sum += paper[r + 2][c];
    sum += paper[r + 1][c + 1];

    max_sum = max(max_sum, sum);
}

void purpleTet4(int r, int c) {
    int sum = 0;

    sum += paper[r][c + 1];
    sum += paper[r + 1][c + 1];
    sum += paper[r + 2][c + 1];
    sum += paper[r + 1][c];

    max_sum = max(max_sum, sum);
}

//max_sum에 최댓값 저장
void findMax() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = true; //방문처리

            dfs(i, j, paper[i][j], 0);

            visited[i][j] = false;

            //ㅜ 블록 처리
            if (i < n - 1 && j < m - 2) {
                //ㅗ, ㅜ
                purpleTet1(i, j);
                purpleTet2(i, j);
            }
            if (i < n - 2 && j < m - 1) {
                //ㅓ, ㅏ
                purpleTet3(i, j);
                purpleTet4(i, j);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    paper.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }

    findMax();

    //출력
    cout << max_sum;

    return 0;
}