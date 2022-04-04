//가장 긴 증가하는 부분 수열

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; //수열의 크기
    cin >> n;
    vector<int> a(n); //수열 A
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    //해당 수보다 작은 수의 dp 중 최댓값 가져오기
    vector<int> dp(n, 1); //해당 원소를 포함했을 때 가장 긴 증가하는 부분 수열 길이
    for (int i = 1; i < n; i++) {
        int m = 0;
        for (int j = 0; j < i; j++) { //i번 앞 원소들 순회
            if (a[j] < a[i]) { //증가하는 수열이 되면
                m = max(m, dp[j]); //길이 최댓값 업데이트
            }
        }
        dp[i] = m + 1; //구한 길이에 해당 원소 포함되니 + 1
    }

//    for(int i: dp){
//        cout<<i<<' ';
//    }

    //출력
    cout << *max_element(dp.begin(), dp.end());

    return 0;
}