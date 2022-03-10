#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct person {
    int paperScore;
    int interviewScore;
};

bool cmp(const person &a, const person &b) {
    return a.paperScore < b.paperScore;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n; //테스크 케이스의 개수, 지원자의 숫자
    cin >> t;
    vector<person> arr; //지원자 배열 선언

    for (int i = 0; i < t; i++) {
        cin >> n;
        arr.assign(n, {0});
        for (int j = 0; j < n; j++) {
            //지원자의 서류심사, 면접 성적 순위
            cin >> arr[j].paperScore >> arr[j].interviewScore;
        }

        sort(arr.begin(), arr.end(), cmp); //서류심사 성적 오름차순으로 정렬

        //서류심사 1등 지원자의 면접 점수보다 순위 낮으면 탈락
        int max = arr[0].interviewScore, hired = 1; //가장 낮은 면접 순위, 채용된 사람 수
        for(int j=0; j<n; j++){
            if(arr[j].interviewScore < max){ //면접 점수 순위 높은 사람
                hired++; //채용
                max = arr[j].interviewScore; //남은 사람들은 이 순위보다 높으면 채용될 수 있음
            }
        }

        //시간초과 나왔음
//        int fail = 0;
//        for (int j = 0; j < n - 1; j++) {
//            int s = arr[j].interviewScore;
//            for (int k = j + 1; k < n; k++) {
//                if (s > arr[k].interviewScore) {
//                    fail++;
//                    break;
//                }
//            }
//        }

        //cmp 없는 경우 에러 발생
//        sort(arr.begin(), arr.end())

        cout << hired << '\n';
    }

    return 0;
}