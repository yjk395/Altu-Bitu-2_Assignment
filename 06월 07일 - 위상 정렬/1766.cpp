//문제집

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//위상정렬
vector<int> topologicalSort(int n, vector<int> &indegree, vector<vector<int>> &graph) {
    vector<int> ans;

    priority_queue<int, vector<int>, greater<>> que; //풀 수 있는 문제 중 쉬운 문제=번호 낮은 문제부터, 오름차순

    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) que.push(i); //진입차수 0
    }

    while (!que.empty()) {
        int node = que.top();
        que.pop();
        ans.push_back(node); //문제 풀기

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i];

            indegree[next_node]--;
            if (indegree[next_node]) continue;
            que.push(next_node); //진입차수 0이면
        }
    }
    return ans;
}

int main() {
    int n, m, a, b; //문제의 수, 정보 개수

    cin >> n >> m;
    vector<int> indegree(n + 1, 0); //진입차수
    vector<vector<int>> graph(n + 1, vector<int>(0)); //인접리스트 그래프

    while (m--) {
        cin >> a >> b; //a는 b보다 먼저 푸는 것이 좋음
        graph[a].push_back(b);
        indegree[b]++;
    }

    //연산
    vector<int> ans = topologicalSort(n, indegree, graph);

    //출력
    for (int i: ans) cout << i << ' ';

    return 0;
}