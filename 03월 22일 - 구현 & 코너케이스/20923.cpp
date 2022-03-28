//20923)숫자 할리갈리 게임

#include <iostream>
#include <deque>
#include <vector>
#include <map>

using namespace std;

//두 사람의 카드덱, 그라운드 맵으로 묶기, 인덱스 0이면 도도, 1이면 수연
map<int, deque<int>> m_deque;
map<int, deque<int>> m_ground;
vector<string> name = {"do", "su"};
//vector<deque<int>> vec = {do_deque, su_deque, do_ground, su_ground}; //벡터에 넣는 건 왜 안 될까요...

//카드덱 맨 위에 위치한 카드를 그라운드 위에 내려놓는 함수
void flipCard(int a) {
    m_ground[a].push_back(m_deque[a].back()); //카드덱 뒤의 원소를 그라운드에 삽입
    m_deque[a].pop_back(); //카드덱 맨 위의 원소를 삭제
}

//상대방과 자신의 그라운드를 자신의 덱에 합치는 함수
void moveGroundToDeque(int a) {
    //상대방 그라운드를 뒤집어 자신의 덱 아래에 합치기
    for (int i = 1; i >= 0; i--) { //i=1이면 상대 그라운드, i=0이면 자신의 그라운드를 처리
        int b = (a + i) % 2; //처리할 그라운드
        while (!m_ground[b].empty()) { //그라운드가 빌 때까지
            m_deque[a].push_front(m_ground[b].front()); //그라운드 아래의 원소를 덱 아래에 삽입
            m_ground[b].pop_front(); //그라운드 아래의 원소 삭제
        }
    }
}

//그라운드 상황에 따라 종을 치고 카드를 처리하는 함수
void ringBell(int a) {
    //앞서 카드덱에서 뒤집은 카드가 5이면 do가 종을 침
    if (m_ground[a].back() == 5) {
        moveGroundToDeque(0);
    }

    //두 그라운드의 가장 위 숫자 합 5이면 su가 종을 침, 그라운드 비어있으면 안 됨
    if (!m_ground[0].empty() && !m_ground[1].empty() && (m_ground[0].back() + m_ground[1].back()) == 5) {
        moveGroundToDeque(1);
    }
}

//게임 진행, 승리자를 반환하는 함수
string playGame(int m) {
    for (int i = 0; i < m; i++) { //m번 진행
        int p = i % 2; //카드를 뒤집는 사람 구분하는 인덱스

        //2. 덱 위의 카드를 그라운드에 내려놓음
        flipCard(p); //짝수이면 도도, 홀수이면 수연이 카드를 뒤집음

        //5. 덱에 있는 카드의 수 0이 되면 즉시 상대방 승리, 게임 종료
        if (m_deque[p].empty()) return name[(p + 1) % 2];

        //3&4. 종 치고 그라운드를 덱에 합침
        ringBell(p);
    }

    //5. 게임 진행 후 덱의 카드 수를 비교하여 승리자 반환
    if (m_deque[0].size() > m_deque[1].size()) return "do";
    else if (m_deque[0].size() == m_deque[1].size()) return "dosu";
    else return "su";
}

int main() {
    int n, m, card; //카드의 개수, 게임 진행 횟수, 카드의 숫자
    //입력
    cin >> n >> m;
    while (n--) { //1. 덱 배분
        cin >> card;
        m_deque[0].push_back(card);
        cin >> card;
        m_deque[1].push_back(card);
    }

    //출력
    cout << playGame(m);
    return 0;
}