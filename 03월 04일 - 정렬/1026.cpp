#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//[리뷰] main()에서만 사용(다른 함수에서 x) -> main에서 지역변수로 선언하기
//vector<int> a, b; //정수 배열 A, B

int main() {
    int n;

    //입력
    cin >> n;
//    a.assign(n, 0);
//    b.assign(n, 0);
    vector<int> a(n, 0), b(n, 0); //정수 배열 A, B 선언
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    //b의 가장 큰 수에 a의 가장 작은 수가 매핑
    //최솟값만 출력하면 되니 a는 오름차순, b는 내림차순 정렬 후 곱하여 출력
    //정렬
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<>());

    //연산
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += a[i] * b[i];
    }

    //출력
    cout << result << '\n';

    return 0;
}