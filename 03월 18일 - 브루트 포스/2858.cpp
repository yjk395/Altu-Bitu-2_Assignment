//2858) 기숙사 바닥

#include <iostream>

using namespace std;

int main() {
    int r, b; //빨간색, 갈색 타일의 수
    //입력
    cin >> r >> b;

    int l, w;

    for (l = r / 2 - 1; l > 2; l--) { //r 이용하여 큰 수부터 l 탐색, l의 최소는 3
        w = (r + 4) / 2 - l; //r = 2 * (l + w) - 4
        if ((l - 2) * (w - 2) == b) break; //b 비교, 찾으면 반복 중단
    }

    //출력
    cout << l << ' ' << w;

    return 0;
}