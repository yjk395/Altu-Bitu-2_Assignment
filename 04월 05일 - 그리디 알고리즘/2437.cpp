//저울

//1 잴 수 있음, 1 더 있으니 2도 잴 수 있음
//2 있으니 3, 4까지 잴 수 있음
//3 있으니 앞선 1, 2, 3, 4를 더한 7까지도 잴 수 있음. 현재 1 2 3 4 5 6 7순으로 이어짐
//6 있으니 6에 +7 한 13까지 연속으로 잴 수 있음
//7 있으니 20까지 잴 수 있음
//30이 나옴. 21 잴 수 없음
//작은 순으로 정렬 후 하나씩 뽑고 연속 이어지는지 확인

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//측정할 수 없는 무게 최솟값 반환
int impossibleWeight(vector<int> &weight) {
    int max_possible_weight = 0; //연속으로 측정할 수 있는 양의 정수 무게 중 최댓값
    for (int i: weight) {
        if (i <= max_possible_weight + 1) { //최댓값보다 1 큰 수까지는 연속으로 이어짐
            max_possible_weight += i; //측정 가능한 값 업데이트
        } else { //연속 끊어지면
            return max_possible_weight + 1; //측정 가능 값 +1을 반환
        }
    }
    return max_possible_weight + 1; //반복문 통과하면 측정 가능 값 +1 반환
}

int main() {
    int n; //저울추의 개수
    //입력
    cin >> n;
    vector<int> weight(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    sort(weight.begin(), weight.end()); //오름차순으로 추 정렬

    //출력
    cout << impossibleWeight(weight);

    return 0;
}