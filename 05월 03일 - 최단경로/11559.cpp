//Puyo Puyo

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;
vector<vector<char>> field(6, vector<char>(12)); //필드 저장

//4개 이상 모인 같은 색 뿌요 터뜨리기
void popPuyo(vector<ci> &puyo_pop_list) {
    for (ci p: puyo_pop_list) {
        field[p.first][p.second] = '.'; //빈 공간으로 수정
    }
}

//뿌요 아래로 떨어지는 연산
void fallPuyo() {
    for (int i = 0; i < 6; i++) {
        int fall_point = -1; //뿌요가 떨어질 y좌표
        for (int j = 0; j < 11; j++) { //제일 위 이전 줄까지
            if (field[i][j] == '.' && fall_point == -1) { //뿌요 떨어질 포인트 업데이트
                fall_point = j;
            } else if(field[i][j] != '.' && fall_point != -1) { //뿌요 등장하고 떨어진다면 교환
                swap(field[i][fall_point], field[i][j]);
                fall_point++; //떨어진 뿌요 윗칸에 다음 뿌요 떨어짐
            }
        }
    }
}

//너비 우선 탐색, 한 연쇄에서 뿌요 터뜨리는 연산
bool bfs() {
    bool is_poped = false; //터질 수 있는 뿌요가 있는지 확인

    // 상, 하, 좌, 우
    int dx[] = {-1, +1, 0, 0};
    int dy[] = {0, 0, -1, +1};

    queue<ci> q;

    vector<vector<bool>> visited(6, vector<bool>(12, false));

    //모든 칸 순회
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 12; j++) {
            if (field[i][j] == '.' || visited[i][j]) continue; //뿌요 없거나 방문했으면 넘어감

            char puyo_color = field[i][j]; //해당 칸의 뿌요
            visited[i][j] = true; //방문 처리
            q.push({i, j}); //좌표를 큐에 삽입
            vector<ci> puyo_pop_list; //터뜨릴 뿌요의 좌표 저장

            while (!q.empty()) { //큐 빌 때까지
                auto[y, x] = q.front(); //큐 첫 번째 원소의 좌표 가져오기
                puyo_pop_list.push_back({y, x}); //좌표 저장

                q.pop(); //큐에서 원소 제거

                for (int k = 0; k < 4; k++) { //상하좌우 탐색
                    int new_y = y + dy[k];
                    int new_x = x + dx[k];

                    //새 좌표의 범위, 색, 방문여부 확인
                    if (new_y >= 0 && new_y < 6 && new_x >= 0 && new_x < 12 && !visited[new_y][new_x] &&
                        field[new_y][new_x] == puyo_color) {
                        q.push({new_y, new_x});
                        visited[new_y][new_x] = true; //방문 처리
                    }
                }
            }

            //뿌요가 4개 이상 모여있으면 터짐
            if (puyo_pop_list.size() >= 4) {
                popPuyo(puyo_pop_list);
                is_poped = true;
            }
            puyo_pop_list.clear(); //뿌요 좌표 리스트 초기화, size 0으로
        }
    }

    //뿌요 아래로 떨어짐
    if (is_poped) {
        fallPuyo();
    }

    return is_poped;
}

//연쇄 횟수 구하기
int solution() {
    int chain_cnt = 0; //연쇄 횟수
    while (bfs()) { //false가 나올 때까지(터지는 뿌요 없을 때까지) 반복
        chain_cnt++;
    }

    return chain_cnt;
}

int main() {
    //입력
    for (int i = 0; i < 12; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < 6; j++) {
            field[j][11 - i] = s[j];
        }
    }

    //출력
    cout << solution();

    return 0;
}