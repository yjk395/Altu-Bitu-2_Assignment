//게임 개발

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//위상정렬
vector<int> topologicalSort(int n, vector<int> &delay, vector<int> &indegree, vector<vector<int>> &graph) {
    queue<int> que; //진입차수 0인 정점 관리
    vector<int> dp(n + 1, 0); //건물 짓기까지 걸리는 최소 시간

    for (int i = 1; i <= n; i++) {
        dp[i] = delay[i]; //dp 초기화
        if (!indegree[i]) que.push(i); //진입차수 0이면
    }

    while (!que.empty()) {
        int node = que.front();
        que.pop();

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i];

            dp[next_node] = max(dp[next_node], dp[node] + delay[next_node]);

            indegree[next_node]--; //진입차수 감소
            if (indegree[next_node]) continue;
            //진입차수 0이면
            que.push(next_node);
        }
    }
    return dp;
}

int main() {
    int n, a; //건물 종류 수, 건물 번호

    cin >> n;
    vector<int> indegree(n + 1, 0); //각 정점의 진입차수
    vector<vector<int>> graph(n + 1, vector<int>(0)); //인접 리스트 그래프
    vector<int> delay(n + 1, 0); //건물 건설에 걸리는 시간

    for (int i = 1; i <= n; i++) {
        cin >> delay[i];
        while (true) {
            cin >> a;
            if (a == -1) break;
            graph[a].push_back(i);
            indegree[i]++;
        }
    }

    //연산
    vector<int> answer = topologicalSort(n, delay, indegree, graph);

    //출력
    for (int i = 1; i <= n; i++)
        cout << answer[i] << '\n';

    return 0;
}