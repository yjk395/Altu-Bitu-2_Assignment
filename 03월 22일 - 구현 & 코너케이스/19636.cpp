//19636)요요 시물레이션

//원래 체중, 일일 에너지 섭취량 = 일일 기초 대사량, 일일 활동 대사량은 0
//에너지 섭취량과 일일 활동 대사량을 바꿈
//체중과 일일 기초 대사량 변화
//체중 += 일일 에너지 섭취량 - 일일 에너지 소비량(= 기초 대사량+활동 대사량)
//기초 대사량 -> |에너지 섭취량 - 에너지 소비량| > 변화 역치 t -> += (에너지섭취량-에너지소비량)/2

#include <iostream>
#include <cmath>

using namespace std;

//기초 대사량 변화 고려하지 않은 경우의 체중과 기초 대사량(입력과 그대로) 출력
//void diet_first(int w0, int i0, int d, int i, int a) {
//    int w_later = w0; //체중
//    for (int k = 0; k < d; k++) { //d일 동안의 체중 변화 계산
//        w_later += (i - (i0 + a)); //체중 변화
//        if (w_later <= 0) { //체중이 0 이하인 경우 사망
//            cout << "Danger Diet" << '\n';
//            return; //호출 종료
//        }
//    }
//    cout << w_later << ' ' << i0 << '\n';
//}

//다이어트 연산, 일일 기초 대사량 변화를 고려하지 않을 땐 t = 0
void diet(int w0, int i0, int d, int i, int a, int t) {
    int w_later = w0; //체중
    int b = i0; //일일 기초 대사량, 다이어트 전에는 일일 에너지 섭취량과 동일
    for (int k = 0; k < d; k++) { //d일 동안의 체중, 기초 대사량 변화 계산
        w_later += (i - (b + a)); //체중 변화
        if (t >= 1 && abs(i - (b + a)) > t) { //기초 대사량 변화 역치 초과이면 일일 기초 대사량 변화, 두 번째 출력에서만
            b += floor((i - (b + a)) / 2.0);
        }
        if (w_later <= 0 || b <= 0) { //체중, 일일 기초 대사량이 0 이하인 경우 사망
            cout << "Danger Diet" << '\n';
            return; //호출 종료
        }
    }
    cout << w_later << ' ' << b << ' ';

    //요요 현상 발생 여부 확인, 두 번째 출력에서만
    if (t >= 1) {
        if ((i0 - b) > 0) cout << "YOYO";
        else cout << "NO";
    }
    cout << '\n';
}

int main() {
//    cout << floor(-5.0/2.0); //음수의 나눗셈 확인, -3이 나와야 함

    int w0, i0, t, //처음 체중, 일일 에너지 섭취량 및 기초 대사량, 기초 대사량 변화 역치
    d, i, a; //다이어트 기간, 일일 에너지 섭취량, 일일 활동 대사량
    //입력
    cin >> w0 >> i0 >> t >> d >> i >> a;
    
    //출력
    diet(w0, i0, d, i, a, 0);
    diet(w0, i0, d, i, a, t);

    return 0;
}