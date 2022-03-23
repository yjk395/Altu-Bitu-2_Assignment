//2436)공약수

//a를 최대공약수, b를 최소공배수로 하는 두 자연수 구하기
//g*l = m*n. g의 배수이면서 m*n의 약수인 둘

#include <iostream>
#include <cmath>

using namespace std;

//최대공약수 구하기
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int g, l;
    //입력
    cin >> g >> l;

    //g*l = m*n
    //1부터 g*l까지 순회하며 i와 l/i쌍의 최대공약수가 g인지 확인
    //m과 n에 g 나누면 l/g=x*y, x와 y는 서로소
    //1부터 l/g까지 순회하며 i와 (l/g)/i쌍의 최대공약수가 1인지 확인
    //그 쌍들 중 합이 최소인 것이 답
    int tmp = l / g;

    //[리뷰] 상수, 10의 배수 표현
//    int m = 1;
//    int n = 1000000000; //합 최대 되는 초깃값
    int m, n;

    //[리뷰] 두 자연수의 합이 최소이려면 두 수의 차이가 가장 작을 때부터 체크
    //sqrt(tmp)(i*i=tmp일 때)에서부터 1까지 or tmp까지 반복

//    for (int i = 1; i <= (tmp + 1) / 2; i++) { //1부터 tmp의 절반까지 반복
//        if (tmp % i != 0) continue; //tmp의 약수가 아니면 건너뜀(i * j = tmp)
//        int j = tmp / i;
//        if (gcd(i, j) == 1) { //서로소이면
//            if (m + n > i + j) { //합이 기존 값보다 더 작으면
//                m = i;
//                n = j;
//                cout<<m<<' '<<n<<'\n'; //디버깅
//            }
//        }
//    }

    for (int i = sqrt(tmp); i > 0; i--) { //루트(tmp) 부터 1까지 반복
        if (!(tmp % i) && gcd(i, tmp / i) == 1) { //i가 tmp의 약수이면서 i,j(tmp/i)가 서로소이면
            m = i;
            n = tmp / i;
            break;
        }
    } //함수화가 나을 것 같지만 귀찮아요

    //출력
    cout << m * g << ' ' << n * g;

    return 0;
}