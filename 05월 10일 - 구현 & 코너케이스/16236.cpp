//아기 상어

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <set>

using namespace std;

typedef pair<int, int> ci;

//아기 상어의 좌표 반환
//[리뷰] 입력받을 때 상어 위치 처리

//너비 우선 탐색, 이동할 곳 찾아 이동 후 추가되는 시간 반환
int bfs(int n, vector<vector<int>> &space, int size, ci &shark_position) {
    // 상, 하, 좌, 우
    int dr[] = {-1, +1, 0, 0};
    int dc[] = {0, 0, -1, +1};

    queue<ci> que;  //탐색을 하기 위해 사용할 큐
    int dist = 0; //먹이 물고기까지의 거리(=걸리는 시간)
    vector<vector<int>> distance(n, vector<int>(n, 0)); //아기 상어로부터 해당 칸까지의 거리 기록 +방문체크
    set<ci> feed_candidate; //먹이 후보 찾아서 저장, 자동 정렬

    //아기 상어의 좌표 큐에 삽입
    que.push(shark_position);
    distance[shark_position.first][shark_position.second] = dist; //상어 자신의 거리는 0
    space[shark_position.first][shark_position.second] = 0; //상어 떠날 자리는 빈자리가 됨

    while (!que.empty()) {
        auto[r, c] = que.front(); //탐색할 칸 좌표
        que.pop();

        if (dist && distance[r][c] > dist) break; //최단거리 모두 찾았으면 탐색 종료

        if (space[r][c] > 0 && space[r][c] < size) { //상어보다 작은 물고기이면
            if (!dist) { //가장 가까운 물고기 처음 등장
                dist = distance[r][c];
                feed_candidate.insert({r, c});
            } else if (distance[r][c] == dist) { //가장 가까운 물고기 여러 마리
                feed_candidate.insert({r, c});
            }
        }

        //상하좌우 네 방향 탐색
        for (int i = 0; i < 4; i++) {
            int new_r = r + dr[i];
            int new_c = c + dc[i];

            //범위체크 및 통과할 수 있는지 확인, 방문여부도 확인
            if (new_r < 0 || new_r >= n || new_c < 0 || new_c >= n || space[new_r][new_c] > size ||
                distance[new_r][new_c])
                continue;

            que.push({new_r, new_c}); //큐에 삽입
            distance[new_r][new_c] = distance[r][c] + 1;
        }
    }

    //먹을 수 있는 물고기가 없다면 -1 반환
    if (!dist) return -1;

    auto it = feed_candidate.begin(); //먹이 후보 중 가장 위, 가장 왼쪽 물고기
    //상어 이동
//    space[it->first][it->second] = 9;
    shark_position = {it->first, it->second};

    return dist; //이동에 걸린 시간 반환
}

int main() {
    int n; //공간의 크기
    cin >> n;

    vector<vector<int>> space(n, vector<int>(n, 0)); //공간 상태
    ci shark_position; //아기 상어의 좌표

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> space[i][j]; //공간의 상태 입력

            if (space[i][j] == 9) { //아기 상어의 좌표이면
                shark_position = {i, j};
            }
        }
    }

    int time = 0, size = 2, feed_cnt = 0; //걸린 시간, 상어의 크기, 물고기 먹은 횟수

    //연산
    while (true) {
        int dt = bfs(n, space, size, shark_position); //탐색
        if (dt == -1) break; //먹을 수 있는 물고기 없으면 종료

        feed_cnt++; //물고기 먹은 횟수 카운트
        if (feed_cnt >= size) { //자신의 크기와 같은 수의 물고기 먹으면
            size++; //크기 1 증가
            feed_cnt = 0; //물고기 먹은 횟수 초기화
        }

        time += dt; //시간 카운트
    }

    //출력
    cout << time;

    return 0;
}