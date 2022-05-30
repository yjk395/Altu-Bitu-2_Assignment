//친구 네트워크

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> parent;

//find 연산
int findParent(int node) {
    if (parent[node] < 0) return node;
    return parent[node] = findParent(parent[node]);
}

//union 연산, 집합의 크기 반환
int unionInput(int a, int b) {
    int ap = findParent(a);
    int bp = findParent(b);

    if (ap == bp) return abs(parent[ap]);
    if (parent[ap] > parent[bp]) {
        parent[ap] += parent[bp];
        parent[bp] = ap;
        return abs(parent[ap]);
    } else {
        parent[bp] += parent[ap];
        parent[ap] = bp;
        return abs(parent[bp]);
    }
}

int main() {
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; //테스트 케이스 수
    cin >> t;

    while (t--) {
        map<string, int> people;
        int f, n = 0; //친구 관계의 수, 사람 수
        string a, b; //두 사용자의 아이디
        cin >> f;
        while (f--) { //친구 관계 생김
            cin >> a >> b;
            //아이디에 정수 맵핑
            if (!people.count(a)) {
                people[a] = n++;
                parent.push_back(-1);
            }
            if (!people.count(b)) {
                people[b] = n++;
                parent.push_back(-1);
            }

            //출력
            cout << unionInput(people[a], people[b]) << '\n';
        }
        parent.clear();
    }

    return 0;
}