//로봇 청소기

#include <iostream>
#include <vector>

using namespace std;

//로봇청소기 작동시키고 청소하는 칸의 개수 계산
int clean(vector<vector<int>> &room, int r, int c, int d) {
    //북, 동, 남, 서
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int cleaned_room = 0; //청소하는 칸의 개수

    int rot_cnt = 0; //회전한 횟수
    while (true) {
        //1. 현재 위치 청소
        if (room[r][c] == 0) {
            room[r][c] = 2;
            cleaned_room++;
        }

        //2-a. 인접 칸 탐색
        d = (d + 3) % 4; //왼쪽으로 회전
        rot_cnt++;
        //앞 칸이 청소하지 않은 빈 칸이면, 가장자리는 모두 벽
        if (room[r + dr[d]][c + dc[d]] == 0) {
            r += dr[d]; //청소기 전진
            c += dc[d];
            rot_cnt = 0; //회전한 횟수 초기화
            continue; //1번으로 돌아감
        }

        //2-b. 4번 연속 실행된 경우
        if (rot_cnt == 4) {
            int back_r = r + dr[(d + 2) % 4];
            int back_c = c + dc[(d + 2) % 4];
            //뒤쪽이 벽이면 종료
            if (room[back_r][back_c] == 1) {
                return cleaned_room;
            }
            //한 칸 후진
            r = back_r;
            c = back_c;
            rot_cnt = 0; //회전한 횟수 초기화
        }
    }
}

int main() {
    int n, m, r, c, d; //세로 크기, 가로 크기, 좌표, 바라보는 방향
    //입력
    cin >> n >> m >> r >> c >> d;

    vector<vector<int>> room(n, vector<int>(m, 0)); //장소 정보 저장

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }

    //출력
    cout << clean(room, r, c, d);

    return 0;
}