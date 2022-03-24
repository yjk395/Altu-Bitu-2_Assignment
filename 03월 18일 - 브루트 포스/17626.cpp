//17626) Four Squares

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


int main() {
    int n;
    //입력
    cin >> n;

    //결과 = (제곱수) + (숫자-제곱수의 제곱근)의결과
    //제곱수는 점화식에 +1
    //저 제곱수의 제곱근을 i로 잡고 탐색
    //[2] = 1+[2-1], [3] = 1+[2], [4]=min(1+[4-1], 1+[4-2^2]), [5] = min(1+[5-1], 1+[5-2^2])
    //[0], [1]은 값 넣고 나머지 계산

    vector<int> sqr_cnt(n + 1, 5); //최솟값 구하기 -> 5로 초기화
    sqr_cnt[0] = 0;
    sqr_cnt[1] = 1;

    //sqr_cnt 배열 채우기
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= sqrt(i); j++) { //첫 제곱수 1부터 루트n까지 잡고 최솟값 구하기
            sqr_cnt[i] = min(sqr_cnt[i], 1 + sqr_cnt[i - j * j]);
        }
    }

    //디버깅
//    for(int i:sqr_cnt){
//        cout<<i<<' ';
//    }
//    cout<<'\n';

    //출력
    cout << sqr_cnt[n];

    return 0;
}
