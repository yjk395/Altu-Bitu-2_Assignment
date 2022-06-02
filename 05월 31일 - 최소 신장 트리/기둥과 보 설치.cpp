//기둥과 보 설치

#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<bool>>> wall; //벽면 상태. wall[y][x][a] = true -> 구조물 존재

//기둥 삭제 시 체크할 구조물. 위 기둥, 위 양옆 보
vector<vector<int>> ch_p = {{0,  +1, 0},
                            {0,  +1, 1},
                            {-1, +1, 1}};
//보 삭제 시 체크할 구조물. 양옆 기둥, 양옆 보
vector<vector<int>> ch_b = {{0,  0, 0},
                            {+1, 0, 0},
                            {-1, 0, 1},
                            {+1, 0, 1}};

//구조물이 있는지 확인
bool isThereStructure(int x, int y, int a) {
    if (x >= 0 && y >= 0) return wall[y][x][a]; //범위 체크
    return false;
}

//구조물 설치 가능 여부 확인
bool canBuild(int x, int y, int a) {
    if (!a) { //a==0, 기둥 설치
        if (y == 0) return true; //1. 바닥 위
        if (isThereStructure(x - 1, y, 1) || isThereStructure(x, y, 1)) return true; //2. 보의 한쪽 끝 부분 위
        if (isThereStructure(x, y - 1, 0)) return true; //3. 기둥 위
    } else { //a==1, 보 설치
        if (isThereStructure(x, y - 1, 0) || isThereStructure(x + 1, y - 1, 0)) return true; //1. 기둥 위
        if (isThereStructure(x - 1, y, 1) && isThereStructure(x + 1, y, 1)) return true; //2. 양쪽 끝이 보와 연결
    }
    return false;
}

//구조물 삭제 가능 여부 확인
bool canDelete(int x, int y, int a, int n) {
    wall[y][x][a] = false; //삭제 가정 후 주변에 있는 구조물 설치 가능한지 체크(남은 구조물이 규칙 만족하는지)
    bool is_valid = true;

    if (!a) { //a==0, 기둥 삭제
        for (int i = 0; i < 3; i++) {
            int dx = x + ch_p[i][0], dy = y + ch_p[i][1];
            if (isThereStructure(dx, dy, ch_p[i][2]) && !canBuild(dx, dy, ch_p[i][2])) {
                is_valid = false; //주변에 구조물이 있는데 설치 불가능하면 주어진 구조물은 삭제 불가능
                break;
            }
        }
    } else { //a==1, 보 삭제
        for (int i = 0; i < 4; i++) {
            int dx = x + ch_b[i][0], dy = y + ch_b[i][1];
            if (isThereStructure(dx, dy, ch_b[i][2]) && !canBuild(dx, dy, ch_b[i][2])) {
                is_valid = false;
                break;
            }
        }
    }
    wall[y][x][a] = true; //삭제 되돌림
    return is_valid;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    wall.assign(n + 1, vector<vector<bool>>(n + 1, vector<bool>(2, false)));

    for (auto work: build_frame) { //작업 순서대로 수행
        //work[0]: x좌표, work[1]: y좌표, work[2]: 구조물 종류, work[3]: 작업 종류
        //조건 만족하지 않으면 작업 무시. work[3]==1은 설치, 0은 삭제 가능 여부 체크
        if (!(work[3] ? canBuild(work[0], work[1], work[2]) : canDelete(work[0], work[1], work[2], n))) continue;

        //작업 수행
        wall[work[1]][work[0]][work[2]] = work[3];
    }

    //answer 형태 만들기(오름차순 정렬)
    for (int i = 0; i <= n; i++) { //x좌표
        for (int j = 0; j <= n; j++) { //y좌표
            for (int k = 0; k <= 1; k++) { //0: 기둥, 1: 보
                if (!wall[j][i][k]) continue;
                answer.push_back({i, j, k});
            }
        }
    }
    return answer;
}

int main() {
    int n = 5; //벽면의 크기

    //예1
    vector<vector<int>> build_frame = {{1, 0, 0, 1},
                                       {1, 1, 1, 1},
                                       {2, 1, 0, 1},
                                       {2, 2, 1, 1},
                                       {5, 0, 0, 1},
                                       {5, 1, 0, 1},
                                       {4, 2, 1, 1},
                                       {3, 2, 1, 1}};

    //예2
//    vector<vector<int>> build_frame = {{0, 0, 0, 1},
//                                       {2, 0, 0, 1},
//                                       {4, 0, 0, 1},
//                                       {0, 1, 1, 1},
//                                       {1, 1, 1, 1},
//                                       {2, 1, 1, 1},
//                                       {3, 1, 1, 1},
//                                       {2, 0, 0, 0},
//                                       {1, 1, 1, 0},
//                                       {2, 2, 0, 1}};


    vector<vector<int>> answer = solution(n, build_frame);

    //출력
    for (auto &i: answer) {
        cout << '[';
        for (int j = 0; j < 3; j++) {
            cout << i[j] << ' ';
        }
        cout << ']';
    }

    return 0;
}