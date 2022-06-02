//할로윈의 양아치

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ci;
vector<ci> parent; //부모, 사탕 수

//find 연산
int findParent(int node) {
    if (parent[node].first < 0) return node; //루트 정점
    return parent[node].first = findParent(parent[node].first);
}

//union 연산
void unionInput(int a, int b) {
    int ap = findParent(a);
    int bp = findParent(b);

    if (ap == bp) return;
    if (parent[ap].first > parent[bp].first) {
        parent[ap].first += parent[bp].first; //아이 수 더하기
        parent[ap].second += parent[bp].second; //사탕 수 더하기
        parent[bp].first = ap;
    } else {
        parent[bp].first += parent[ap].first; //아이 수 더하기
        parent[bp].second += parent[ap].second; //사탕 수 더하기
        parent[ap].first = bp;
    }
}

int findMaxCandy(int n, int k) {
    vector<int> dp(k, 0);

    for (int i = 1; i <= n; i++) {
        if (parent[i].first >= 0) continue; //루트 정점인 아이만 고르기
        int pers = abs(parent[i].first); //친구무리 아이 수
        for (int j = k - 1; j >= pers; j--) {
            dp[j] = max(dp[j - pers] + parent[i].second, dp[j]); //뺏는 경우, 안 뺏는 경우 중 최댓값
        }
    }
    return dp[k - 1];
}

int main() {
    int n, m, k; //거리에 있는 아이들 수, 친구 관계 수, 울음소리 공명하는 최소 수
    cin >> n >> m >> k;

    parent.assign(n + 1, {-1, 0});

    for (int i = 1; i <= n; i++) { //받은 사탕의 수 입력
        cin >> parent[i].second;
    }

    int a, b; //a와 b는 친구
    while (m--) {
        cin >> a >> b;
        unionInput(a, b);
    }

    //출력
    cout << findMaxCandy(n, k);

    return 0;
}