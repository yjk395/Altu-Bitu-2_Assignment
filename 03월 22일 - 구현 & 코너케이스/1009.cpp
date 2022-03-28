//1009)분산처리

//거듭제곱의 1의 자리 수 -> 주기 구해서 지수를 나눈 나머지로 판단

#include <iostream>
#include <vector>

using namespace std;

int main() {
    //거듭제곱 1의 자리 숫자 주기
    vector<vector<int>> v(10);
    v[0] = {10}; //10번 컴퓨터 출력해야 함
    v[1] = {1};
    v[2] = {6, 2, 4, 8};
    v[3] = {1, 3, 9, 7};
    v[4] = {6, 4};
    v[5] = {5};
    v[6] = {6};
    v[7] = {1, 7, 9, 3};
    v[8] = {6, 8, 4, 2};
    v[9] = {1, 9};

    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << v[a % 10][b % (v[a % 10].size())] << '\n'; //지수를 주기로 나눈 나머지를 인덱스로
    }

    return 0;
}