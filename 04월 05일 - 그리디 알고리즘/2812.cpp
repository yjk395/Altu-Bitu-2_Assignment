//크게 만들기

#include <iostream>
#include <deque>

using namespace std;

//변환한 숫자를 반환
string solution(int n, int k, string num) {
    deque<char> deq;
    string answer;

    for (int i = 0; i < n; i++) {
        //i번째 수보다 앞에 있는 작은 수는 전부 삭제 -> 덱에서 크거나 같은 수 나올 때까지(삽입할 수보다 작을 동안)
        while (!deq.empty() && k && deq.back() < num[i]) { //비어있지 않고, 삭제할 개수 0보다 클 때
            deq.pop_back();
            k--; //삭제한 수 카운트, k가 0이 되면 나머지 수는 삽입만 함
        }

        //덱에 삽입
        deq.push_back(num[i]);
    }

    while (k && !deq.empty()) { //삭제해야 할 숫자 개수 남아있으면 개수 맞춰 뒷 부분 삭제
        deq.pop_back();
        k--;
    }

    //먼저 삽입된 수부터 나와야 하므로 스택 말고 덱 사용
    while (!deq.empty()) {
        answer.push_back(deq.front());
        deq.pop_front();
    }
    return answer;
}

int main() {
    int n, k; //n자리 숫자, k개 지우기
    string num; //입력받은 숫자
    //입력
    cin >> n >> k >> num;

    //연산 및 출력
    cout << solution(n, k, num);

    return 0;
}