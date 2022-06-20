//11723)집합

#include <iostream>
#include <vector>

using namespace std;

vector<bool> v(21, false); //숫자가 집합 S에 있는지 체크하는 벡터

void processOp(string op, int x) {
    if (op == "add") {
        if (!v[x]) v[x] = true; //x를 추가
    } else if (op == "remove") {
        if (v[x]) v[x] = false; //x를 삭제
    } else if (op == "check") {
        cout << v[x] << '\n'; //x가 있으면 1, 없으면 0 출력
    } else if (op == "toggle") {
        if (v[x]) v[x] = false;  //x가 있으면 제거
        else v[x] = true; //x가 없으면 추가
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n; //연산의 수, 입력받은 수
    string op; //입력받은 연산 종류
    cin >> m; //m 입력
    while (m--) {
        cin >> op;
        if (op == "all") {
            fill(v.begin() + 1, v.end(), true); //모든 숫자가 S에 포함됨
        } else if (op == "empty") {
            fill(v.begin() + 1, v.end(), false); //모든 숫자가 S에 포함되지 않음
        } else {
            cin >> n;
            processOp(op, n);
        }
    }

    return 0;
}