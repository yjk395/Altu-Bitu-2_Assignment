//나무 재테크

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> nutrient; //땅의 양분
vector<vector<int>> ntr_addition; //각 칸에 추가되는 양분
vector<vector<vector<int>>> tries; //각 칸에 있는 나무들의 나이

//봄: 양분 먹고 나이 증가
void spring(int &n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) { //모든 칸 순회

            sort(tries[i][j].begin(), tries[i][j].end()); //나무 오름차순 정렬

            for (int k = 0; k < tries[i][j].size(); k++) { //그 칸의 모든 나무 순회
                if (nutrient[i][j] < tries[i][j][k]) { //양분 부족
                    tries[i][j][k] = -tries[i][j][k]; //사망
                } else {
                    nutrient[i][j] -= tries[i][j][k]; //나이만큼 양분 섭취
                    tries[i][j][k]++; //나이 1 증가
                }
            }
        }
    }
}

//여름: 죽은 나무가 양분으로 변함
void summer(int &n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) { //모든 칸 순회
            sort(tries[i][j].begin(), tries[i][j].end()); //나무 오름차순 정렬

            for (int k = 0; k < tries[i][j].size(); k++) { //그 칸의 모든 나무 순회
                if (tries[i][j][k] > 0) break;//살아있는 나무면 다음 칸으로

                nutrient[i][j] += (-tries[i][j][k]) / 2; //나무가 있던 칸에 양분 추가
                tries[i][j].erase(tries[i][j].begin() + k); //나무 삭제

                k--; //삭제했으니 인덱스 감소
            }
        }
    }
}

//가을: 나무 번식
void fall(int &n) {
    //인접한 8개의 칸
    int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) { //모든 칸 순회
            sort(tries[i][j].begin(), tries[i][j].end()); //나무 오름차순 정렬

            for (int k = 0; k < tries[i][j].size(); k++) { //그 칸의 모든 나무 순회
                if (tries[i][j][k] % 5 != 0) continue; //나무의 나이가 5의 배수가 아니면 번식하지 않음

                for (int l = 0; l < 8; l++) { //인접한 8개의 칸
                    int new_r = i + dr[l];
                    int new_c = j + dc[l];

                    //땅 벗어나는지 체크
                    if (new_r < 1 || new_r > n || new_c < 1 || new_c > n) continue;

                    tries[new_r][new_c].push_back(1); //나이가 1인 나무 생김
                }
            }
        }
    }
}

//겨울: 땅에 양분 추가
void winter(int &n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) { //모든 칸 순회
            nutrient[i][j] += ntr_addition[i][j];
        }
    }
}

//나무 개수 세기
int countTries(int &n) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) { //모든 칸 순회
            cnt += tries[i][j].size();
        }
    }
    return cnt;
}

int main() {
    int n, m, k; //땅 크기, 심은 나무 개수, 지난 햇수
    int x, y, z; //나무의 위치, 나이
    cin >> n >> m >> k;

    //각 벡터 초기화, 좌표는 1부터 시작
    nutrient.resize(n + 1, vector<int>(n + 1, 5));
    ntr_addition.resize(n + 1, vector<int>(n + 1, 0));
    tries.resize(n + 1, vector<vector<int>>(n + 1));

    //겨울에 추가해주는 양분의 양 입력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> ntr_addition[i][j];
        }
    }

    //심은 나무의 정보 입력
    while (m--) {
        cin >> x >> y >> z;
        tries[x][y].push_back(z);
    }

    //k년 만큼 사계절 반복
    while (k--) {
        spring(n);
        summer(n);
        fall(n);
        winter(n);
    }

    //출력
    cout << countTries(n);

    return 0;
}