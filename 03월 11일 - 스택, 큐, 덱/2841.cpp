//2841)외계인의 기타 연주

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//각 줄에서 누르는 프렛 번호를 스택에 저장
vector<stack<int>> v(6); //6개의 줄

//음 하나를 새로 연주할 때 필요한 손가락 움직임 반환
int playOneNote(int string_idx, int fret) {
    int result = 0; //결과값

    //연주해야 할 프렛 번호보다 높은 프렛 누르고 있는 손가락 뗌
    while (!v[string_idx].empty() && v[string_idx].top() > fret) {
        v[string_idx].pop();
        result++;
    }
    //이미 손가락 누르고 있으면
    if (!v[string_idx].empty() && fret == v[string_idx].top()) {
        return result;
    }
    //손가락 새로 누르기
    v[string_idx].push(fret);
    return ++result;
}

int main() {
    int n, p, string, fret, total = 0; //음의 수, 프렛의 수, 한 음의 줄의 번호, 프렛의 번호, 손가락 움직임
    //입력
    cin >> n >> p;

    //멜로디 입력
    while (n--) {
        cin >> string >> fret;
        total += playOneNote(string - 1, fret);
    }

    //출력
    cout << total;
    return 0;
}