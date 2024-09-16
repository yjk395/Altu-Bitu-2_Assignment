//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int SIZE = 8;

int n, m;
vector<int> num(SIZE);
vector<int> v(SIZE);
vector<bool> check(SIZE, false);

void backtracking(int cnt) { //cnt는 수열의 인덱스
    //길이 m인 수열 만든 경우
    if (cnt == m) {
        //출력
        for (int i = 0; i < cnt; i++) {
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int previous = 0;
    for (int i = 0; i < n; i++) {
        if (!check[i] && v[i] != previous) {
            num[cnt] = v[i]; //사용
            check[i] = true;
            previous = v[i];
            backtracking(cnt + 1); //다음 인덱스 호출

            check[i] = false; //되돌려 놓음
        }
    }
}

int main() {
    //입력
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.begin() + n); //입력받은 만큼 오름차순 정렬

    backtracking(0);

    return 0;
}