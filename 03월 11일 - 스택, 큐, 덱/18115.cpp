//18115)카드 놓기

#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n, skill; //카드의 개수, 카드를 내려놓을 때 사용한 스킬 번호
    deque<int> d; //손에 든 카드
    deque<int> skill_log; //스킬 사용 내역
    //입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> skill;
        skill_log.push_back(skill);
    }

    //연산
    for (int i = 1; i <= n; i++) { //바닥에 놓인 카드 위에서부터 연산
        switch (skill_log.back()) { //마지막으로 사용한 스킬부터 역으로 연산
            case 1: //제일 위에 카드를 둠
                d.push_back(i);
                break;
            case 2: { //위에서 두 번째에 넣음
                int back_card = d.back(); //(컴파일에러)case문 시작 위치에서 지역변수 선언 -> 중괄호로 묶기, 또는 그냥 switch 시작 전 선언
                d.pop_back();
                d.push_back(i);
                d.push_back(back_card);
                break;
            }
            case 3: //제일 밑에 넣음
                d.push_front(i);
                break;
        }
        skill_log.pop_back(); //연산한 스킬 삭제
    }

    //출력
    while (n--) {
        cout << d.back() << ' ';
        d.pop_back();
    }

    return 0;
}