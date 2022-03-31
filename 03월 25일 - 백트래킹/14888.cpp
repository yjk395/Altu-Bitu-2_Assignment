//

#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 11; //n 최댓값
int n, sum, sub, mul, divs; //수의 개수, 각 연산자 개수
vector<int> num(SIZE, 0); //입력받은 숫자 순서대로 저장
vector<char> op(SIZE - 1); //연산자 선택

void func(){

}

int main() {
    //입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    cin >> sum >> sub >> mul >> divs;



    return 0;
}