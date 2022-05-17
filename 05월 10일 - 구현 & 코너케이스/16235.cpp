//나무 재테크

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> nutrient; //땅의 양분
vector<vector<int>> ntr_addition; //각 칸에 추가되는 양분
vector<vector<vector<int>>> trees; //각 칸에 있는 나무들의 나이

//봄: 양분 먹고 나이 증가
//[코드리뷰] 죽은 나무 목록 컨테이너에 저장, 리턴하기
vector<vector<int>> spring(int &n) {
    vector<vector<int>> dead_trees(n + 1, vector<int>(n + 1, 0)); //죽은 나무가 변한 양분 양 저장

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) { //모든 칸 순회
            sort(trees[i][j].begin(), trees[i][j].end()); //나무 오름차순 정렬

            for (int k = 0; k < trees[i][j].size(); k++) { //그 칸의 모든 나무 순회
                if (nutrient[i][j] < trees[i][j][k]) { //양분 부족
//                    tries[i][j][k] = -trees[i][j][k]; //사망
                    //죽은 나무 삭제, 따로 저장하여 반환
                    dead_trees[i][j] += trees[i][j][k] / 2;
                    trees[i][j].erase(trees[i][j].begin() + k); //나무 삭제
                    k--; //삭제했으니 인덱스 감소
                } else {
                    nutrient[i][j] -= trees[i][j][k]; //나이만큼 양분 섭취
                    trees[i][j][k]++; //나이 1 증가
                }
            }
        }
    }

    return dead_trees;
}

//여름: 죽은 나무가 양분으로 변함
void summer(int &n, vector<vector<int>> &dead_trees) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) { //모든 칸 순회
            nutrient[i][j] += dead_trees[i][j]; //각 칸에 양분 추가
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
            sort(trees[i][j].begin(), trees[i][j].end()); //나무 오름차순 정렬

            for (int k = 0; k < trees[i][j].size(); k++) { //그 칸의 모든 나무 순회
                if (trees[i][j][k] % 5 != 0) continue; //나무의 나이가 5의 배수가 아니면 번식하지 않음

                for (int l = 0; l < 8; l++) { //인접한 8개의 칸
                    int new_r = i + dr[l];
                    int new_c = j + dc[l];

                    //땅 벗어나는지 체크
                    if (new_r < 1 || new_r > n || new_c < 1 || new_c > n) continue;

                    trees[new_r][new_c].push_back(1); //나이가 1인 나무 생김
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
int countTrees(int &n) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) { //모든 칸 순회
            cnt += trees[i][j].size();
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
    trees.resize(n + 1, vector<vector<int>>(n + 1));

    //겨울에 추가해주는 양분의 양 입력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> ntr_addition[i][j];
        }
    }

    //심은 나무의 정보 입력
    while (m--) {
        cin >> x >> y >> z;
        trees[x][y].push_back(z);
    }

    //k년 만큼 사계절 반복
    while (k--) {
        auto dead_trees = spring(n);
        summer(n, dead_trees);
        fall(n);
        winter(n);
    }

    //출력
    cout << countTrees(n);

    return 0;
}