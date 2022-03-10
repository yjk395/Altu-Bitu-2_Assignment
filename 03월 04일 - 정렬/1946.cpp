#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//[리뷰] pair<int, int> 사용 -> 비교함수 필요 x
//struct person {
//    int paperScore;
//    int interviewScore;
//};

//bool cmp(const person &a, const person &b) {
//    return a.paperScore < b.paperScore;
//}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n; //테스크 케이스의 개수, 지원자의 숫자
    cin >> t;
//    vector<person> arr; //지원자 배열 선언
    vector<pair<int, int>> arr; //지원자 배열 선언, 서류심사와 면접 성적 pair로

    //테스크 케이스 개수만큼 반복
    //[리뷰] t 사용 x -> while문 사용
//    for (int i = 0; i < t; i++) {}
    while (t > 0) {
        cin >> n;
//        arr.assign(n, {0});
        arr.assign(n, {0, 0});
        for (int j = 0; j < n; j++) {
            cin >> arr[j].first >> arr[j].second; //지원자의 서류심사, 면접 성적 순위 저장
        }

        //정렬
//        sort(arr.begin(), arr.end(), cmp); //서류심사 성적 오름차순으로 정렬
        sort(arr.begin(), arr.end()); //서류심사 성적 오름차순으로 정렬, pair는 first로 1차, second로 2차 정렬

        //서류심사 1등 지원자의 면접 점수보다 순위 낮으면 탈락
        int max = arr[0].second, hired = 1; //가장 낮은 면접 순위, 채용된 사람 수
        for (int j = 0; j < n; j++) {
            if (arr[j].second < max) { //면접 점수 순위가 더 높은 사람
                hired++; //채용
                max = arr[j].second; //서류심사 순위 더 낮은 남은 사람들은 이 순위보다 높으면 채용될 수 있음
            }
        }

        //출력
        cout << hired << '\n';

        t--; //1개의 테스크 케이스 처리 완료
    }

    return 0;
}