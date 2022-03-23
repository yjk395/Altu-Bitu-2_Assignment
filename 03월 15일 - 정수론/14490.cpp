//14490)백대열

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
    string s;
    //입력
    cin >> s;

    int index = s.find(':'); //입력에서 ':'의 인덱스
    int n = stoi(s.substr(0, index));
    int m = stoi(s.substr(index + 1));
    int g = gcd(max(n, m), min(n, m)); //최대공약수

    //출력
    cout << n / g << ':' << m / g;

    return 0;
}