//1, 2, 3 더하기

#include <iostream>
#include <vector>

using namespace std;

int main() {
    //n은 11보다 작으니 미리 dp 생성
    vector<int> dp(12, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 10; i++) {
        //n-1값에 +1, n-2값에 +2, n-3값에 +3 더해 나타냄
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    int t, n; //테스크 케이스의 개수, 입력받는 정수
    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << '\n'; //출력
    }

    return 0;
}