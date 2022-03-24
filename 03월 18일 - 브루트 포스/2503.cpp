//2503) 숫자 야구

#include <iostream>
#include <vector>

using namespace std;

vector<string> arr; //가능성이 있는 수를 저장하는 벡터

//한 개의 질문을 통해 가능성 있는 후보를 업데이트
void updateCandidate(string q, int s, int b) {
    //벡터 순회하며 q와 num 비교하여 s, b 계산, 맞지 않으면 벡터에서 삭제
    for (int i = 0; i < arr.size(); i++) {
        string num = arr[i];
        int strike = 0, ball = 0;
        for (int j = 0; j < 3; j++) { //세 자리 수 모두 순회
            if (num[j] == q[j])
                strike++; //동일한 자리에 위치하면 스트라이크
            else if (num[j] == q[(j + 1) % 3] || num[j] == q[(j + 2) % 3])
                ball++; //다른 자리에 위치하면 볼
        }
        //질문의 답변과 맞지 않으면 후보군에서 삭제
        if (strike != s || ball != b) {
            arr.erase(arr.begin() + i);
            i--; //삭제했으니 인덱스 하나씩 당겨옴
        }
    }
}

int main() {
    //가능성이 있는 모든 수를 벡터에 저장, 1~9의 서로 다른 숫자 세 개
    for (int i = 123; i <= 987; i++) {
        string num = to_string(i);
        if (num[0] == num[1] || num[0] == num[2] || num[1] == num[2] || num[0] == '0' || num[1] == '0' ||
            num[2] == '0') { //정수 아니고 char라서 '0'이랑 비교해야 함
            continue; //0이 있거나 같은 수가 있으면 건너뜀
        }
        arr.push_back(num);
    }

    int n, s, b; //질문의 수, 스트라이크, 볼
    string q; //물어본 숫자, 자리별 연산해야 하므로 string형
    //입력
    cin >> n;

    while (n--) {
        cin >> q >> s >> b;
        updateCandidate(q, s, b);
    }

    //디버깅
//    for (string num: arr) {
//        cout << num << ' ';
//    }
//    cout << '\n';

    //출력
    cout << arr.size(); //남은 가능한 수를 저장한 벡터의 크기를 출력

    return 0;
}