#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, eachTip; //대기하는 사람의 수, 받을 수 있는 팁의 최댓값, 각 사람에게 실제로 받는 팁
    //입력
    cin >> n;
    vector<int> tip(n, 0); //각 사람이 주려고 하는 팁
    for (int i = 0; i < n; i++) {
        cin >> tip[i];
    }

    //내림차순 정렬해야 팁이 최대
    sort(tip.begin(), tip.end(), greater<>());

    long long total = 0; //100,000명의 사람이 각각 100,000원의 팁을 준다 -> int 범위 벗어남
    for (int i = 0; i < n; i++) {
        eachTip = tip[i] - i; //(받은 등수 - 1)은 인덱스 값과 동일
        if (eachTip >= 0){
            total += eachTip;
        }else
            break;
    }

    //출력
    cout << total;
    return 0;
}