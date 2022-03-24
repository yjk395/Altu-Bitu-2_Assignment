//10757) 큰수 A+B

#include <iostream>
#include <algorithm>

using namespace std;

//10000자리의 string 자료형 정수 덧셈
//자릿수 a > b
string strSum(string a, string b) {
    //자릿수 맞추기, 더 적은 수의 앞에 0 추가
    b.insert(0, a.length() - b.length(), '0');
    int carry = 0;
    string answer;

    //두 수를 자릿수끼리 합산
    for (int i = a.length() - 1; i >= 0; i--) {
        int tmp = (a[i] - '0') + (b[i] - '0') + carry;
        answer.push_back(tmp % 10 + '0'); //1의 자리를 추가
        carry = tmp / 10; //남은 carry 저장
    }

    //남은 carry 있다면(!= 0) 덧붙임
    if(carry){
        answer.push_back(carry + '0');
    }

    reverse(answer.begin(), answer.end()); //뒤집힌 상태 바로하기
    return answer;
}

int main() {
    string a, b;
    //입력
    cin >> a >> b;

    //b의 자릿수가 더 크면 교환
    if (a.length() < b.length()) swap(a, b);

    //출력
    cout << strSum(a, b);
    return 0;
}