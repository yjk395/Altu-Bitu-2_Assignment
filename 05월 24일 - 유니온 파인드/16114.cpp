//화살표 연산자

#include <iostream>

using namespace std;

int main() {
    int x, n; //변수 x의 초기값, 화살표의 길이
    cin >> x >> n; //입력

    //출력
    if (n != 1 && n % 2) cout << "ERROR"; //단항 부정 연산자 함께 적용된 식에는 적용 불가
    else {
        if (n == 1) { //- 하나면 감소연산자x, 단항부정연산자
            n = 0;
            x = -x;
        }
        if (x <= 0) cout << 0; //x <= 0은 감소 후에도 0 이하
        else if (!n) cout << "INFINITE"; //x > 0 && 화살표 길이 0이면 무한
        else cout << x / (n / 2) + (x % (n / 2) ? 0 : -1); //나머지 없으면 마지막은 0이라 출력x
    }

    return 0;
}