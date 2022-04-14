//IF문 좀 대신 써줘

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1e9;

int main() {
    int n, m; //칭호, 캐릭터의 개수
    cin >> n >> m;
    vector<string> title(n);
    vector<int> bound(n);
    vector<int> character(m);
    for (int i = 0; i < n; i++) { //칭호의 이름, 전투력 상한값 입력
        cin >> title[i] >> bound[i];
    }
    bound.insert(bound.begin(), -1);
    for (int i = 0; i < m; i++) {
        cin >> character[i];
    }

    //출력
    for (int i = 0; i < n; i++) {
//        cout<<bound[i]<<' '<<bound[i+1]<<' ';
        int cnt = upper_bound(character.begin(), character.end(), bound[i + 1]) -
                  upper_bound(character.begin(), character.end(), bound[i]);
        for (int j = 0; j < cnt; j++) {
            cout << title[i] << '\n';
        }
    }


    return 0;
}