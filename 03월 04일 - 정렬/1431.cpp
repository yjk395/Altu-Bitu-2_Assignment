#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//시리얼번호에서 숫자인 것을 더한 결과 계산
int calDigit(string n) {
    int total = 0;
    for (int i = 0; i < n.length(); i++) {
        if ('0' <= n[i] && n[i] <= '9') {
            total += (int)n[i] - '0';
        }
    }
    return total;
}

//비교 함수
bool cmp(const string &a, const string &b) {
    if (a.length() != b.length()) { //1. 시리얼번호 길이가 다르면 짧은 것이 먼저
        return a.length() < b.length();
    } else if (calDigit(a) != calDigit(b)) { //2. 자리수의 합이 다르면 작은 합이 먼저
        return calDigit(a) < calDigit(b);
    } else { //사전순으로 비교

        return a < b;
    }
}

int main() {
    int n; //기타의 개수
    cin >> n;
    vector<string> guitars(n, "");
    for (int i = 0; i < n; i++) {
        cin >> guitars[i];
    }

    sort(guitars.begin(), guitars.end(), cmp);

    //출력
    for (int i = 0; i < n; i++) {
        cout << guitars[i] << '\n';
    }
    return 0;
}