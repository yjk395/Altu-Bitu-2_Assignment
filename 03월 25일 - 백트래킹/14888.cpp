//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 11; //n 최댓값
vector<int> num(SIZE, 0); //입력받은 숫자 순서대로 저장
vector<char> op; //연산자 선택

vector<int> func(int n) {
    int amin = 1e9, amax = -1e9; //최솟값, 최댓값
    do {
        int result = num[0]; //만들어진 식 연산
        for (int i = 1; i < n; i++) {
            switch (op[i - 1]) {
                case '+':
                    result += num[i];
                    break;
                case '-':
                    result -= num[i];
                    break;
                case '*':
                    result *= num[i];
                    break;
                case '/':
                    result /= num[i];
                    break;
            }
        }
        amin = min(amin, result); //답 업데이트
        amax = max(amax, result);
    } while (next_permutation(op.begin(), op.end())); //연산자 다음 순열

    return {amax, amin};
}

int main() {
    int n, sum, sub, mul, divs; //수의 개수, 각 연산자 개수
    //입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    cin >> sum >> sub >> mul >> divs;
    //연산자 벡터에 삽입
    op.insert(op.begin(), sum, '+');
    op.insert(op.begin(), sub, '-');
    op.insert(op.begin(), mul, '*');
    op.insert(op.begin(), divs, '/');
    sort(op.begin(), op.end()); //정렬

    vector<int> answer = func(n);

    //출력
    cout << answer[0] << '\n' << answer[1];

    return 0;
}