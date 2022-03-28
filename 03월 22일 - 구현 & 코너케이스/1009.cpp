//1009)분산처리

//거듭제곱의 1의 자리 수 -> 주기 구해서 지수를 나눈 나머지로 판단

#include <iostream>
#include <vector>

using namespace std;

int main() {
    //거듭제곱 1의 자리 숫자 주기
    vector<vector<int>> v(10);
    v[0] = {0};
    v[1] = {1};
    v[2] = {2, 4, 8, 6};
    v[3] = {3, 9, 7, 1};
    v[4] = {4, 6};
    v[5] = {5};
    v[6] = {6};
    v[7] = {7, 9, 3, 1};
    v[8] = {8, 4, 2, 6};
    v[9] = {9, 1};

    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << v[a % 10][b % (v[a % 10].size())-1] << '\n';

    }

    return 0;
}