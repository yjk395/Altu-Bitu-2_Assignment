//나무 자르기
//[추가제출]

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

//해당 height로 자를 때 가져갈 수 있는 나무의 높이의 합 계산
//나무 1000000개, 길이 2000000000 -> int 범위 넘으니 long long타입 반환
ll cntTree(int height, vector<int> &tree) {
    ll sum = 0; //길이 총합
    for (int i = 0; i < tree.size(); i++) { //모든 나무 순회
        if (height >= tree[i]) { //내림차순 정렬->받은 중간값보다 같거나 작아지면 리턴
            return sum; //총합 반환
        }
        sum += (tree[i] - height); //자를 수 있는 나무의 길이 더함
    }
    return sum; //반복문 빠져나오면 총합 반환
}

//높이의 최댓값 반환
int upperSearch(int left, int right, int target, vector<int> &tree) {
    while (left <= right) { //left(0에서 시작)와 right(가장 긴 나무의 길이에서 시작)가 같아질 때까지
        int mid = (left + right) / 2; //중간값
        ll tree_cnt = cntTree(mid, tree); //가져갈 수 있는 나무의 높이

        if (tree_cnt >= target) { //필요한 길이보다 같거나 크면 최댓값x -> 오른쪽 부분 탐색
            left = mid + 1; //오른쪽 부분
        } else { //목표치 충족x -> 더 높이 잘라야 함, 왼쪽 부분 탐색
            right = mid - 1; //왼쪽 부분
        }
    }
    return left - 1; //반환
}

/**
 * [나무 자르기]
 *
 * 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값은?
 * -> 절단기의 높이가 k(임의의 값)일 때, M미터의 나무를 집에 가져갈 수 있는가?
 *
 * left: 절단기의 최소 높이 -> 0
 * right: 절단기의 최대 높이 -> 주어진 나무 중 가장 높은 나무 높이
 *
 * !주의! int 자료형 범위를 넘어가므로 long long써야 함
 */

int main() {
    int n, m; //나무의 수, 필요한 나무의 길이

    //입력
    cin >> n >> m;
    vector<int> tree(n, 0); //나무의 높이 저장, n개의 값 0으로 초기화
    for (int i = 0; i < n; i++) { //나무 n개만큼 반복
        cin >> tree[i]; //높이 입력
    }

    sort(tree.begin(), tree.end(), greater<>()); //내림차순 정렬

    //연산 & 출력
    cout << upperSearch(0, tree[0], m, tree);
    return 0;
}