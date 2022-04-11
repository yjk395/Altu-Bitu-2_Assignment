//크게 만들기

//시간 초과

#include <iostream>

using namespace std;

//변환한 숫자를 반환
//시간 초과
string solution(int n, int k, string num) {
    int idx = 0;
    while (k) { //k개 수 모두 지워 k가 0이 될 때까지
        if (num[idx] < num[idx + 1]) { //뒤 숫자가 더 크면 앞을 삭제
            num.erase(idx, 1);
            k--;
        } else if (num[idx] > num[idx + 1]) { //앞 숫자가 더 크면 앞을 삭제
            num.erase(idx + 1, 1);
            k--;
        } else { //같으면 두 숫자 모두 남기고 다음 숫자로
            idx += 2;
        }
    }

    return num;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k; //n자리 숫자, k개 지우기
    string num; //입력받은 숫자
    cin >> n >> k >> num;

    cout << solution(n, k, num);

    return 0;
}