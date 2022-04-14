//IF문 좀 대신 써줘

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m; //칭호, 캐릭터의 개수
    cin >> n >> m;
    vector<string> title(n);
    vector<int> bound(n + 1);
    bound[0] = -1; //전투력은 0부터, 더 작은 값 첫 번째 인덱스에 저장
    vector<int> character(m);
    for (int i = 0; i < n; i++) { //칭호의 이름, 전투력 상한값 입력
        cin >> title[i] >> bound[i + 1];
    }
    for (int i = 0; i < m; i++) { //캐릭터의 전투력 입력
        cin >> character[i];
    }

    sort(character.begin(), character.end()); //오름차순 정렬

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