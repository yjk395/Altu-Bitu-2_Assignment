//행렬

#include <iostream>
#include <vector>

using namespace std;

//3*3 부분 행렬의 모든 원소를 뒤집기
void transformMat(int y, int x, vector<string> &a) {
    for (int i = y; i < y + 3; i++) {
        for (int j = x; j < x + 3; j++) {
            a[i][j] = !(a[i][j] - '0') + '0';
        }
    }
}

//두 행렬 받아서 연산 횟수 반환
int solution(int n, int m, vector<string> &a, vector<string> &b) {
    //이게 들어가면 왜 오답일까요..?
//    if (n < 3 || m < 3) return -1; //크기 3보다 작으면 변환 연산 불가

    int cnt = 0; //연산 횟수

    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            if (a[i][j] != b[i][j]) {
                transformMat(i, j, a);
                cnt++;
            }
        }
    }
    //남은 부분 확인하여 다르면 -1
    if (a != b) return -1;
    return cnt;
}

int main() {
    int n, m; //행렬의 크기
    cin >> n >> m;
    vector<vector<string>> mat(2);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            string str;
            cin >> str;
            mat[i].push_back(str);
        }
    }

    cout << solution(n, m, mat[0], mat[1]);

    return 0;
}