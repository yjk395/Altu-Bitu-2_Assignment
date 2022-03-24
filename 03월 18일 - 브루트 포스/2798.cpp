//2798) 블랙잭

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> card; //숫자 카드

//임시배열 이용해서 카드 세 장의 합 구하기
int calcSum(int n, vector<bool> &tmp) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (tmp[i]) {
            sum += card[i];
//            cout<<card[i]<<' '; //디버깅
        }
    }
    return sum;
}

//m을 넘지 않는 최댓값을 찾는 함수
int findMaxSum(int n, int m) {
    int answer = 0;
    //조합 구하기 위한 임시배열
    vector<bool> tmp(n, false);
    for (int i = 0; i < 3; i++) //세 장을 뽑음
        tmp[i] = true;

    //조합 구하기
    do {
        int sum = calcSum(n, tmp); //뽑은 세 카드의 합
        if (sum <= m) { //m보다 크지 않으면
            answer = max(answer, sum); //기존 합과 새로 구한 합 중 큰 수로 업데이트
        }
    } while (prev_permutation(tmp.begin(), tmp.end())); //임시배열 다음 순열

    return answer;
}

int main() {
    int n, m; //카드의 개수, 합을 가깝게 만들 수 M
    //입력
    cin >> n >> m;
    card.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> card[i];
    }

    //출력
    cout << findMaxSum(n, m);

    return 0;
}