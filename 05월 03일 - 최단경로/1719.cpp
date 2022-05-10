//택배
//추가 제출

#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e5 * 2; //최대 n-1개의 간선을 지나게 됨

//플로이드-워셜
void floydWarshall(int n, vector<vector<int>> &graph, vector<vector<int>> &table) {
    for (int k = 1; k <= n; k++) { //중간 정점
        for (int i = 1; i <= n; i++) { //출발 정점
            for (int j = 1; j <= n; j++) { //도착 정점
                int new_dist = graph[i][k] + graph[k][j]; //중간에 k를 거쳐서 i에서 j로 갈 때의 비용
                if (new_dist < graph[i][j]) { //더 짧은 경로 선택
                    graph[i][j] = new_dist; //더 짧은 경로로 업데이트
                    table[i][j] = table[i][k]; //경로표 업데이트
                }
            }
        }
    }
}

/**
 * [택시]
 *
 * graph : 플로이드-워셜 결과 행렬 그래프
 * table : 경로표. table[i][j] = i->j로 가기 위해 제일 먼저 거쳐야 하는 정점
 *
 * 1. i->j의 중간 경로를 i로 초기화
 * 2. i->k->j가 i->j보다 짧다면 i->j의 중간 경로를 i->k의 중간 경로(table[i][k])로 갱신
 *    k로 갱신하는게 아니라 table[i][k]로 갱신하는 이유는?
 *    만약 i->k의 경로가 i->t->k라면 최종 경로는 i->t->k->j
 *    바로 k로 갱신하면 t를 놓칠 수 있기 때문에 table[i][k]로 갱신
 *    line 14을 table[i][j] = k로 바꾸면 결과가 어떻게 되는지 확인해보세요
 */

int main() {
    int n, m, s, d, c; //입력 받는 변수

    //입력
    cin >> n >> m; //집하장의 개수, 집하장간 경로 개수
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF)); //경로 저장
    vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) { //자기 자신과의 거리는 0
        graph[i][i] = 0;
    }

    while (m--) { //무방향 그래프
        cin >> s >> d >> c; //두 집하장의 번호, 오가는 데 필요한 시간
        //간선 정보
        graph[s][d] = graph[d][s] = c; //두 방향 거리 저장

        //경로 정보
        table[s][d] = d; //s번에서 d번으로 최단 경로 통해 가기 위해서는 d번으로 이동해야 함
        table[d][s] = s;
    }

    //연산
    floydWarshall(n, graph, table);

    //출력
    for (int i = 1; i <= n; i++) { //n*n 경로표 출력
        for (int j = 1; j <= n; j++) {
            if (i == j) { //자기 자신으로 이동하는 칸은 '-' 출력
                cout << "- ";
            } else {
                cout << table[i][j] << ' '; //가장 먼저 거쳐야 하는 집하장 출력
            }
        }
        cout << '\n';
    }
    return 0;
}