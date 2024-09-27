//IF문 좀 대신 써줘

#include <iostream>
#include <map>

using namespace std;

int main() {
    //입출력 속도 향상
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, c; //칭호, 캐릭터의 개수, 전투력
    string str; //칭호 이름
    cin >> n >> m;

    //[리뷰] 상한값과 그때의 칭호를 map에 저장
    map<int, string> title; //전투력 상한값, 칭호 이름

    for (int i = 0; i < n; i++) { //칭호의 이름, 전투력 상한값 입력
        cin >> str >> c;
        //칭호가 여러 개인 경우 가장 먼저 입력된 칭호 하나만 출력 -> 나중에 들어온 중복은 무시
        if(!title.count(c)){
            title[c] = str; //map에 저장, 상한값으로 이분 탐색
        }
    }

    for (int i = 0; i < m; i++) { //캐릭터의 전투력 입력받아 맞는 칭호 출력
        cin >> c;
        //[리뷰] 맵, 셋에 자체적으로 이분탐색 함수
        cout<<title.lower_bound(c)->second<<'\n';
    }

    return 0;
}