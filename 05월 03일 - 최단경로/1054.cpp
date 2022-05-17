//특정한 최단 경로
//추가 제출

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5 * 8 * 3; //최대 N-1개의 간선을 지나게 됨 * 중복 순회 가능(3)

//다익스트라
vector<int> dijkstra(int start, int v, vector<vector<ci>> &graph) {
    vector<int> dist(v + 1, INF); //각 정점까지의 최단 경로 저장
    priority_queue<ci, vector<ci>, greater<>> pq; //현재 탐색하는 중간 정점까지의 최단 경로

    dist[start] = 0; //시작 정점 초기화
    pq.push({0, start}); //큐에 삽입
    while (!pq.empty()) { //우선순위 큐가 비어있지 않은 동안 반복
        int weight = pq.top().first; //시작점부터 정점까지의 거리
        int node = pq.top().second; //정점
        pq.pop(); //삭제

        if (weight > dist[node]) { //이미 더 작은 값으로 기록된 정점이면
            continue; //넘어감
        }
        for (int i = 0; i < graph[node].size(); i++) { //node와 연결된 모든 정점에 대해
            int next_node = graph[node][i].first; //node와 연결된 정점
            int next_weight = weight + graph[node][i].second; //시작점으로부터 현재 node를 거쳐 다음 정점까지 가는 경로값
            if (next_weight < dist[next_node]) { //더 가까운 정점이면
                dist[next_node] = next_weight; //최단 경로 값 갱신
                pq.push({next_weight, next_node}); //우선순위 큐에 정점 삽입
            }
        }
    }
    return dist; //거리 반환
}

/**
 * [특정한 최단 경로]
 *
 * 가능한 경로
 * 1. 1 -> v1 -> v2 -> n
 * 2. 1 -> v2 -> v1 -> n
 * -> 1, v1, v2를 시작점으로 하는 다익스트라 함수 실행하기
 *
 * !주의! 한 번 이동했던 정점, 간선을 다시 방문할 수 있음. 즉 1->N의 최댓값이 INF(1e5*8)이 아니라 3*INF!
 */

int main() {
    int n, e, a, b, c, v1, v2; //변수 생성

    //입력
    cin >> n >> e; //정점 개수, 간선 개수

    vector<vector<ci>> graph(n + 1, vector<ci>(0)); //무방향 그래프
    vector<vector<int>> dist(3, vector<int>(n + 1, 0));
    while (e--) { //무방향 그래프
        cin >> a >> b >> c; //a정점에서 b정점까지 거리 c
        graph[a].emplace_back(b, c); //그래프 벡터에 삽입, a->b
        graph[b].emplace_back(a, c); //b->a
    }
    cin >> v1 >> v2; //반드시 거쳐야 하는 두 개의 정점 번호

    //연산
    vector<int> start_nodes = {1, v1, v2}; //세 정점에서 각각 연산
    for (int i = 0; i < 3; i++) { //1, v1, v2에서 시작한 다익스트라 결과 저장
        dist[i] = dijkstra(start_nodes[i], n, graph); //연산 결과 dist에 저장
    }

    //1->v1->v2->n의 경로와 1->v2->v1->n의 경로 중 최솟값
    //무방향 그래프기 때문에 v1->v2와 v2->v1은 사실 같은 값!
    int ans = min(dist[0][v1] + dist[1][v2] + dist[2][n], dist[0][v2] + dist[2][v1] + dist[1][n]);

    //출력
    cout << ((ans >= INF) ? -1 : ans); //최단 경로의 길이를 출력, 경로가 없으면 -1 출력
    return 0;
}