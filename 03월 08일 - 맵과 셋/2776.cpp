//2776)암기왕

#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, m, input; //테스크 케이스의 개수, 수첩1, 수첩2에 적어 놓은 정수의 개수
    //입력
    cin >> t;

    while (t--) { //테스크 케이스 개수만큼 반복
        //수첩1의 입력
        cin >> n;
        set<int> note; //수첩1의 정수를 검색을 위해 set에 삽입
        while (n--) {
            cin >> input;
            note.insert(input);
        }
        //수첩2의 입력과 처리
        cin >> m;

        while (m--) {
            cin >> input; //입력받은 수첩2의 정수
            //출력
            //set에 있으면 1, 없으면 0 -> 원소의 개수 찾기
            //로 하면 시간초과. 찾아보니 count랑 find 시간복잡도도 같던데 이유가 뭘까요..
//            cout << note.count(input) << '\n';

            auto iter = note.find(input);
            if (iter != note.end()) {
                cout << 1 << '\n';
            } else
                cout << 0 << '\n';
        }
    }
    return 0;
}