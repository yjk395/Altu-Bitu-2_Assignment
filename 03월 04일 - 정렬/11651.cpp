#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct dot { //좌표평면 위의 점의 정보를 나타내는 구조체
    int x;
    int y;
};

//비교 함수
bool cmp(const dot &a, const dot &b) {
    if (a.y != b.y) { //y좌표가 다르면 y좌표가 증가하는 순서로
        return a.y < b.y;
    } else { //y좌표가 같으면 x좌표가 증가하는 순서로
        return a.x < b.x;
    }
}

int main() {
    int n; //점의 개수
    //입력
    cin >> n;
    vector<dot> arr(n, {0});
    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }

    //연산
    sort(arr.begin(), arr.end(), cmp);

    //출력
    for (int i = 0; i < n; i++) {
        cout << arr[i].x << ' ' << arr[i].y << '\n';
    }

    return 0;
}
