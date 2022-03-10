#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//시리얼번호에서 숫자인 것을 더한 결과 계산
int calDigit(string n) {
    int total = 0;
    //[리뷰] isdigit() 함수
    //[리뷰] char to int
    //'0'~'9' - '0' -> 아스키 코드 값으로 연산해 해당 숫자 값 구함, (int) '0'~'9' -> 아스키 코드 값
//    for (int i = 0; i < n.length(); i++) {
//        if ('0' <= n[i] && n[i] <= '9') {
//            total += (int) n[i] - '0';
//        }
//    }

    for (int i = 0; i < n.length(); i++) {
        if (isdigit(n[i]) != 0) { //숫자인 경우
            total += n[i] - '0';
        }
    }
    return total;
}

//비교 함수
bool cmp(const string &a, const string &b) {
    //[리뷰] if문 return
    if (a.length() != b.length()) { //1. 시리얼번호 길이가 다르면 짧은 것이 먼저
        return a.length() < b.length();
    }
    if (calDigit(a) != calDigit(b)) { //2. 자리수의 합이 다르면 작은 합이 먼저
        return calDigit(a) < calDigit(b);
    }
    return a < b; //3. 사전순으로 비교
}

int main() {
    int n; //기타의 개수
    cin >> n;
    vector<string> guitars(n, "");
    for (int i = 0; i < n; i++) {
        cin >> guitars[i];
    }

    //정렬
    sort(guitars.begin(), guitars.end(), cmp);

    //출력
    for (int i = 0; i < n; i++) {
        cout << guitars[i] << '\n';
    }
    return 0;
}