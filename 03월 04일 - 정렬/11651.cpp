#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//[리뷰] 구조체 x, pair<자료형, 자료형> 사용
//struct dot { //좌표평면 위의 점의 정보를 나타내는 구조체
//    int x;
//    int y;
//};

//비교 함수
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    //[리뷰] 함수 return하면 이후 실행 x -> else문 필요 x
    if (a.second != b.second) { //y좌표가 다르면 y좌표가 증가하는 순서로
        return a.second < b.second;
    }
    return a.first < b.first; //y좌표가 같으면 x좌표가 증가하는 순서로
}

int main() {
    int n; //점의 개수

    //입력
    cin >> n;
    vector<pair<int, int>> arr(n, {0, 0}); //점 정보 저장하는 벡터, 점은 xy좌표 묶은 pair
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    //연산
    sort(arr.begin(), arr.end(), cmp);

    //출력
    for (int i = 0; i < n; i++) {
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }

    return 0;
}
