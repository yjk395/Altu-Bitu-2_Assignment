//수 묶기

/*
 * 음수는 음수, 양수는 양수와 절댓값 큰 수끼리 묶기
 * 짝 없는 음수와 0 묶기
 * 1은 묶지 않음
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int ans = 0, n, m; //수열의 합, 수열의 크기, 입력받은 수
    cin >> n;

    vector<int> neg_nums; //음수와 0 저장
    vector<int> pos_nums; //1보다 큰 양수 저장

    for (int i = 0; i < n; i++) {
        cin >> m;
        if (m == 1) ans++; //1은 곱하면 손해, 그냥 더함
        else if (m > 1) pos_nums.push_back(m); //1을 제외한 양수
        else neg_nums.push_back(m); //음수, 0
    }

    //절댓값이 큰 순으로 정렬
    sort(neg_nums.begin(), neg_nums.end()); //오름차순 정렬
    sort(pos_nums.begin(), pos_nums.end(), greater<>()); //내림차순 정렬

    //음수 연산
    for (int i = 0; i < neg_nums.size(); i++) {
        if (neg_nums[i] == 0) break; //이후 남은 수도 0, 반복 종료(0은 더해도 영향x 무시)

        if (i == neg_nums.size() - 1) { //짝이 없는 마지막 수는 그냥 더함
            ans += neg_nums[i];
            break;
        }

        //마지막 수가 아니면 다음 수와 곱하여 더함
        ans += neg_nums[i] * neg_nums[i + 1];
        i++; //다다음 수 탐색
    }

    //양수 연산
    for (int i = 0; i < pos_nums.size(); i++) {
        if (i == pos_nums.size() - 1) { //마지막 수인 경우
            ans += pos_nums[i];
            break;
        }

        //마지막 수가 아니면 다음 수와 곱하여 더함
        ans += pos_nums[i] * pos_nums[i + 1];
        i++; //다다음 수 탐색
    }

    //출력
    cout << ans;

    return 0;
}
