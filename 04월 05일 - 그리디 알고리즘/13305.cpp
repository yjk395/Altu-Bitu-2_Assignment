//주유소

//다음 도시 갈 만큼의 기름은 반드시 필요, 가장 가격 낮은 곳에서 전부 충전하기
//일단 다음 도시 거리만큼 주유받아서 출발하고
//다음 도시에서 앞 도시들 + 현재 도시 중 가장 낮은 곳에서 추가 주유해 다음 도시로
//방문한 도시는 우선순위 큐에 삽입

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//최소 비용을 찾아서 반환
//리터당 가격*전체 도로의 길이가 int 범위 넘으므로 비용은 long long 타입으로 지정
long long findPrice(int n, vector<int> &distance, vector<int> &price) {
    long long total = 0; //필요한 총 비용
    priority_queue<int, vector<int>, greater<>> visited; //방문한 도시의 리터당 기름 가격을 최소 힙에 저장

    for (int i = 0; i < n - 1; i++) { //도시 순서대로 방문, 마지막 도시는 연산 불필요
        visited.push(price[i]); //방문한 도시의 가격 큐에 삽입
        total += (long long)visited.top() * (long long)distance[i]; //가장 싼 곳에서 기름 더 넣기, 형변환 필요
    }

    return total;
}

int main() {
    int n; //도시의 개수
    cin >> n;

    vector<int> distance(n - 1, 0); //각 도로의 길이
    vector<int> price(n, 0); //각 주유소의 리터당 가격
    //n-1개의 도로의 길이 입력
    for (int i = 0; i < n - 1; i++) cin >> distance[i];
    //n개의 각 도시 별 주유소의 리터당 가격 입력
    for (int i = 0; i < n; i++) cin >> price[i];

    //출력
    cout<<findPrice(n, distance, price);

    return 0;
}