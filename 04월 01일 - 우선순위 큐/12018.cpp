//Yonsei TOTO

#include <iostream>
#include <queue>

using namespace std;

//수강신청에 성공하기 위해 넣어야 하는 최소 마일리지 반환
int findRequiredMile(priority_queue<int> &q, int p, int l) {
    if (p < l) { //인원 미달이면 최소 마일리지 넣어도 수강 가능
        return 1;
    }
    //높은 순부터 l번째 사람과 같은 마일리지
    for (int i = 0; i < l - 1; i++) {
        q.pop();
    }
    return q.top();
}

int main() {
    priority_queue<int, vector<int>, greater<int>> required_mile;

    int n, m; //과목 수, 마일리지
    cin >> n >> m;
    while (n--) {
        int p, l; //신청한 사람 수, 수강인원
        cin >> p >> l;
        priority_queue<int> q;

        //각 사람이 마일리지 얼마나 넣었는지 입력
        for (int i = 0; i < p; i++) {
            int mile;
            cin >> mile;
            q.push(mile);
        }

        required_mile.push(findRequiredMile(q, p, l));
    }

    //연산
    int answer = 0;
    m -= required_mile.top();
    while (m >= 0 && !required_mile.empty()) { //모두 수강신청 성공하면 큐 비어있으니 체크
        required_mile.pop();
        answer++;
        m -= required_mile.top();
    }

    //출력
    cout << answer;

    return 0;
}