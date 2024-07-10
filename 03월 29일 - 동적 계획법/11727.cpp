//2*n 타일링 2
//점화식 -> 1칸 전 답[2*1] + (2칸 전 답*3-1)[1*2 2개, 2*2]

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; //2*n 직사각형
    cin >> n;

    vector<int> dp(n + 1, 0);

    //dp 채우기
    dp[1] = 1;
    dp[2] = 3; //dp[3] = 3 + (1+1) = 5
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 10007;
        //10007로 나눈 나머지만 알면 되니 나머지 연산 마지막에 하는 것과 중간에 하는 것 값 같다
        //안 나누면 표현 가능한 정수 범위 넘어섬
    }

    //출력
    cout << dp[n];
    return 0;
}