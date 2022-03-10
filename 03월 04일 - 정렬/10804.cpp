#include <iostream>
#include <vector>

using namespace std;

struct interval { //구간 나타내는 구조체
    int begin;
    int end;
};

vector<int> arr, inverted; //20장의 카드 벡터. 뒤집는 과정에서 새로운 벡터에 저장

//디버깅. 배열 출력 함수
void printArr() {
    for (int i = 0; i < 20; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

//주어진 구간의 카드 순서 뒤집기
void invert(int begin, int end) {
    int cnt = end - begin + 1; //구간의 크기 계산
    int p1 = begin - 1, p2 = end - 1; //인덱스
    for (int i = 0; i < cnt; i++) {
        inverted[i] = arr[p2 - i]; //구간의 뒤 카드부터 순서대로 저장
    }

    //원래 벡터에 값 복사
    for (int i = 0; i < cnt; i++) {
        arr[p1 + i] = inverted[i];
    }
}

int main() {
    int n = 10; //입력받는 구간의 개수
    //입력
    vector<interval> itvs(n, {0});
    for (int i = 0; i < n; i++) {
        cin >> itvs[i].begin >> itvs[i].end;
    }

    //20장의 숫자 카드 생성
    arr.assign(20, 0);
    inverted.assign(20, 0);
    for (int i = 0; i < 20; i++) {
        arr[i] = i + 1;
    }

    //연산
    for (int i = 0; i < n; i++) {
        invert(itvs[i].begin, itvs[i].end);
    }
    printArr();

    return 0;
}