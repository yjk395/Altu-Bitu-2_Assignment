//장난감 조립

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
typedef pair<int, int> ci;

map<int, int> topologicalSort(int n, vector<int> &indegree, vector<vector<ci>> &graph) {
    queue<int> que; //진입차수 0인 노드
    vector<map<int, int>> dp(n + 1); //기본부품 필요 개수 저장
    vector<int> basic_node; //기본부품 번호

    for (int i = 1; i < n; i++) {
        if (!indegree[i]) {
            que.push(i);
            dp[i][i] = 1; //자기 자신이 1개 필요(나머지 부품은 0개)
            basic_node.push_back(i); //처음 진입차수 0인 노드들은 기본부품
        }
    }

    while (!que.empty()) {
        int node = que.front();
        que.pop();

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first; //다음 정점
            for (int j: basic_node) {
                //앞 부품에 필요한 기본부품 각 개수에 다음 정점 완성에 필요한 앞 부품 개수 곱하여 업데이트
                dp[next_node][j] += dp[node][j] * graph[node][i].second;
            }

            indegree[next_node]--; //진입차수 감소
            if (indegree[next_node]) continue;

            //진입차수 0이면
            que.push(next_node);
        }
    }
    return dp[n]; //완제품의 dp값 리턴
}

int main() {
    int n, m, x, y, k; //1~n-1은 부품, n은 완제품 번호, m은 입력받는 관계 수

    cin >> n >> m;
    vector<int> indegree(n + 1, 0); //진입차수
    vector<vector<ci>> graph(n + 1, vector<ci>(0)); //인접리스트 그래프

    while (m--) {
        cin >> x >> y >> k; //x 생산에 y가 k개 필요
        graph[y].push_back({x, k});
        indegree[x]++;
    }

    //연산
    map<int, int> ans = topologicalSort(n, indegree, graph);

    //출력
    for (auto iter:ans) {
        cout << iter.first << ' ' << iter.second << '\n';
    }

    return 0;
}