#include <iostream>

//하루는 86400초
#define DAY 86400

using namespace std;

//시계의 상황 출력
void printWatch(int sec) {
    cout << sec / (60 * 60) << ' ' << (sec / 60) % 60 << ' ' << sec % 60 << '\n';
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int watch; //시계의 현재 시각을 초 단위로 저장
    //입력
    int h, m, s, q, t, c;
    cin >> h >> m >> s >> q;

    //시계, 쿼리 설정
    watch = h * 60 * 60 + m * 60 + s; //초 단위로 변환하여 저장

    //q개의 쿼리 입력. T가 1, 2일 때 c 입력받아 시계 조작, 3일 때 상황 출력
    int index = 0;
    for (int i = 0; i < q; i++) {
        cin >> t;
        if (t == 3) { //시계의 상황 출력
            printWatch(watch);
        } else if (t == 1) { //시계 앞으로 돌리기
            cin >> c; //t가 1, 2일 경우 c 입력받아 처리
            watch = (watch + c) % DAY; //날짜 넘어가는 경우 나머지만 남김
        } else { //시계 뒤로 돌리기
            cin >> c;
            watch = (watch - c) % DAY;
            if (watch < 0) { //음수인 경우 날짜 뒤로 가기
                watch = DAY + watch;
            }
        }
    }

    return 0;
}