//

//check 배열엔 도시 들르면 true 체크
//0으로 갈 수 없는 경우는 백트래킹이니 안 감
//모든 도시 시작점으로 n번 반복하며 찾고..

#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 10;
int n, start, min_cost = 1e7; //도시의 수, 순회 시작 도시, 최소 비용
vector<vector<int>> cost(SIZE, vector<int>(SIZE, 0)); //비용 행렬
vector<bool> check(SIZE, false); //도시 방문 여부

//도시 방문 횟수, 현재 출발하는 도시, 누적 비용
void traveling(int cnt, int city, int cur_cost) {
    //순회 완료
    if (cnt == n && city == start) { //현재 도시가 시작점과 같음
//        cout<<"["<<cur_cost<<"]";
        min_cost = min(min_cost, cur_cost); //최솟값 업데이트 후 호출종료
        return;
    }

    for (int i = 0; i < n; i++) {
        //비용 0인 곳, 이미 방문한 도시는 갈 수 없음
        if (!check[i] && cost[city][i]) {
            //한 곳 방문하고 재귀호출
            check[i] = true;
//            cout<<"["<<cur_cost<<' '<<cost[city][i]<<' '<<cnt<<"]";
            traveling(cnt + 1, i, cur_cost + cost[city][i]);

            check[i] = false; //방문여부 되돌리기
        }
    }
}

int main() {
    //입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        start = i; //시작 도시 결정
//        cout<<"start: "<<i<<' ';
        traveling(0, i, 0);
    }

    //출력
    cout << min_cost;

    return 0;
}