//2436)공약수

//a를 최대공약수, b를 최소공배수로 하는 두 자연수 구하기
//작은 수부터 순회해야 함
//g*l = m*n. g의 배수이면서 m*n의 약수인 둘

#include <iostream>

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
    //m과 n에 g 나누면 l=x*y, x와 y는 서로소
    //1부터 l까지 순회하며 i와 l/i쌍의 최대공약수가 1인지 확인
    //그 쌍들 중 합이 최소인 것이 답
    int tmp = l / g;
    int m = 1;
    int n = 1000000000; //합 최대 되는 초기값
    for (int i = 1; i <= (tmp + 1) / 2; i++) { //1부터 tmp의 절반까지 반복
        if (tmp % i != 0) continue; //tmp의 약수가 아니면 건너뜀(i * j = tmp)
        int j = tmp / i;
        if (gcd(i, j) == 1) { //서로소이면
            if (m + n > i + j) { //합이 더 최소이면
                m = i;
                n = j;
//                cout<<m<<' '<<n<<'\n'; //디버깅
            }
        }
    }
    //출력
    cout << m * g << ' ' << n * g;

    return 0;
}