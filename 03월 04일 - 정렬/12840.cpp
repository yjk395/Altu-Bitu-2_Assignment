#include <iostream>

//하루는 86400초
//[리뷰] const 사용
//#define DAY 86400

using namespace std;

//시계의 상황 출력
//[리뷰] 출력은 main에서
//void printWatch(int sec) {
//    cout << sec / (60 * 60) << ' ' << (sec / 60) % 60 << ' ' << sec % 60 << '\n';
//}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const int DAY = 86400; //하루는 86400초
    int watch; //시계의 현재 시각을 초 단위로 저장
    //입력
    int h, m, s, q, t, c;
    cin >> h >> m >> s >> q;

    //시계 설정
    watch = h * 60 * 60 + m * 60 + s; //초 단위로 변환하여 저장

    //q개의 쿼리 입력받아 처리
    int index = 0;
    for (int i = 0; i < q; i++) {
        cin >> t;
        if (t == 3) { //3. 시계의 상황 출력
            //출력
//            printWatch(watch);
            cout << watch / (60 * 60) << ' ' << (watch / 60) % 60 << ' ' << watch % 60 << '\n';
        } else if (t == 1) { //1. 시계 앞으로 돌리기
            cin >> c; //t가 1, 2일 경우 c 입력받아 처리
            watch = (watch + c) % DAY; //날짜 넘어가는 경우 나머지만 남김
        } else { //2. 시계 뒤로 돌리기
            cin >> c;
            watch = (watch - c) % DAY;
            if (watch < 0) { //음수인 경우 날짜 뒤로 가기
                watch = DAY + watch;
            }
        }
    }

    return 0;
}