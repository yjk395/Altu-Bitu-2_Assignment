//스위치 켜고 끄기

#include <iostream>
#include <vector>

using namespace std;

int n; //스위치 개수
vector<int> switches; //스위치 상태

//남학생이 스위치 끄고 켜기
void student1(int num) {
    for (int i = 1; i <= n; i++) {
        if (i % num == 0) //배수가 맞으면 상태 바꿈
            switches[i] = !switches[i];
    }
}

//여학생이 스위치 끄고 켜기
void student2(int num) {
    switches[num] = !switches[num]; //해당 번호의 스위치 상태 바꿈
    int bound = min(num - 1, n - num); //탐색할 구간 범위
    for (int i = 1; i <= bound; i++) {
        if (switches[num - i] != switches[num + i]) return; //좌우가 대칭이 아니면 종료
        switches[num - i] = switches[num + i] = !switches[num - i]; //대칭이면 상태 바꿈
    }
}

int main() {
    cin >> n;

    switches.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) { //스위치 상태 입력
        cin >> switches[i];
    }

    int people; //학생수
    cin >> people;

    while (people--) {
        int s, num; //학생의 성별, 받은 수
        cin >> s >> num;

        //연산
        if (s == 1) student1(num); //1이면 남학생
        else student2(num); //2는 여학생
    }

    //출력
    for (int i = 1; i <= n; i++) {
        cout << switches[i] << ' ';
        if (i % 20 == 0) cout << '\n'; //20개 출력 후 줄바꿈
    }

    return 0;
}