//해킹
//추가 제출

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e7; //최대 n-1개의 연결관계 있으므로 -> n * (가중치 최대값)

//다익스트라
ci dijkstra(int start, int v, vector<vector<ci>> &graph) { //해킹당한 컴퓨터가 시작점, 컴퓨터 개수, 의존성 전달받음
    priority_queue<ci, vector<ci>, greater<>> pq; //현재 탐색하는 중간 정점까지의 최단 경로
    vector<int> dist(v + 1, INF); //각 정점까지의 최단 경로 저장

    dist[start] = 0; //시작 정점 초기화
    pq.push({0, start}); //첫 정점 우선순위 큐에 삽입
    int cnt = 0, t = 0; //총 감염되는 컴퓨터 수, 마지막 컴퓨터 감염까지 걸리는 시간
    while (!pq.empty()) { //우선순위 큐가 비어있지 않은 동안 반복
        int weight = pq.top().first; //시작점부터 정점까지의 거리
        int node = pq.top().second; //정점
        pq.pop(); //삭제

        if (weight > dist[node]) { //이미 더 작은 값으로 기록된 정점이면
            continue; //넘어감
        }
        cnt++; //감염된 컴퓨터 수 업데이트
        t = weight; //지금까지 걸린 시간
        for (int i = 0; i < graph[node].size(); i++) { //node와 연결된 모든 정점에 대해
            int next_node = graph[node][i].first; //node와 연결된 정점
            int next_weight = weight + graph[node][i].second; //시작점으로부터 현재 node를 거쳐 다음 정점까지 가는 경로값
            if (next_weight < dist[next_node]) {  //더 가까운 정점이면
                dist[next_node] = next_weight; //dist값 갱신
                pq.push({next_weight, next_node}); //우선순위 큐에 정점 삽입
            }
        }
    }
    return {cnt, t}; //리턴
}

/**
 * [해킹]
 *
 * - 기본적인 다익스트라 문제
 * - 다익스트라 내에서 이미 더 짧은 경로가 존재하는 정점은 탐색에서 배제하면서, 탐색하는 정점의 수와 마지막 시간을 저장
 *
 * !주의! 그래프 생성 시, a가 b를 의존한다는 건 b 감염 후 a가 감염된다는 뜻이므로 b -> a 방향임
 */

int main() {
    int t, n, d, c, a, b, s;

    //입력
    cin >> t;
    while (t--) {
        cin >> n >> d >> c; //컴퓨터 개수, 의존성 개수, 해킹당한 컴퓨터의 번호
        vector<vector<ci>> graph(n + 1, vector<ci>(0)); //방향 그래프
        while (d--) { //d개의 의존성 입력
            cin >> a >> b >> s; //컴퓨터 a가 b를 의존, b 감염 s초 후 a도 감염
            graph[b].push_back({a, s}); //방향 그래프에 저장
        }

        //연산
        ci ans = dijkstra(c, n, graph);

        //출력
        cout << ans.first << ' ' << ans.second << '\n'; //총 감염되는 컴퓨터 수, 마지막 컴퓨터 감염까지 걸리는 시간
    }
    return 0;
}
