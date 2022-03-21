//10610) 30

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string n; //입력받는 수
    //입력
    cin >> n;

    //n을 내림차순 정렬 -> 가장 큰 수가 됨
    //30의 배수이려면 마지막 자리는 0
    //자릿수 합이 3의 배수인지 확인
    sort(n.begin(), n.end(), greater<>()); //내림차순 정렬

    //출력
    if(n.back() != '0') cout<<-1;
    else{
        int sum = 0;
        for(char ch:n){ //모든 자릿수 더함
            sum += (ch-'0');
        }
        if(sum%3 == 0) cout<<n;
        else cout<<-1;
    }
    return 0;
}