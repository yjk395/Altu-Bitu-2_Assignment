#include <iostream>
#include <vector>

using namespace std;

//struct interval { //구간 나타내는 구조체
//    int begin;
//    int end;
//};

//vector<int> arr, inverted; //20장의 카드 벡터. 뒤집는 과정에서 새로운 벡터에 저장

//디버깅. 배열 출력 함수
//void printArr() {
//    for (int i = 0; i < 20; i++) {
//        cout << arr[i] << ' ';
//    }
//    cout << '\n';
//}

int main() {
    int n = 10, begin, end; //입력받는 구간의 개수, 구간 시작, 끝 변수

    //20장의 숫자 카드 생성
    vector<int> arr(20, 0); //20장의 카드 벡터
//    inverted.assign(20, 0);
    for (int i = 0; i < 20; i++) {
        arr[i] = i + 1;
    }

    //입력
    //[리뷰] 구간 정보 저장하지 않고 입력 받으면서 연산 수행
//    vector<interval> itvs(n, {0});
    for (int i = 0; i < n; i++) {
//        cin >> itvs[i].begin >> itvs[i].end;
        cin >> begin >> end; //구간 입력

        //연산
        //[리뷰]
        //swap 사용, 왼쪽과 오른쪽 카드 맞바꾸기
        //왼쪽 카드부터 가운데 카드까지, 구간 절반 크기만큼 반복
        for (int p1 = begin - 1, i = 0; i < (end - begin) / 2 + 1; p1++, i++) {
            swap(arr[p1], arr[end - 1 - i]);
        }
    }

    //출력
//    printArr();
    for (int i = 0; i < 20; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}