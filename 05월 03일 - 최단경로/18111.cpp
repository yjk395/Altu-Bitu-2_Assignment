//18111)마인크래프트

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MAX_TIME = 500 * 500 * 2 * 256;
const int MAX_HEIGHT = 256;

//최소 시간과 땅의 높이 구하기
tuple<int, int> solution(vector<int> &heights, int b) {
    int min_time = MAX_TIME, min_time_height = MAX_HEIGHT; //가능한 최댓값으로 초기화

    for (int i = heights[0]; i >= heights.back(); i--) { //i는 땅 높이 기준값
        int time = 0, inven = b; //땅 고르기 작업에 걸리는 시간, 인벤토리

        for (int j: heights) { //집터 전체 순회
            if (i < j) { //기준보다 땅 높이가 크면 블록 제거
                time += 2 * (j - i);
                inven += j - i; //제거한 블록 인벤토리에 넣기
            } else if (i > j) { //땅 높이가 작으면
                time += i - j;
                inven -= i - j; //놓은 블록 인벤토리에서 제거
                if (inven < 0) { //인벤토리에 블록 부족하면 불가능
                    time = MAX_TIME;
                    break;
                }
            }
        }

        if (min_time > time) { //최솟값 업데이트
            min_time = time;
            min_time_height = i;
        }
    }

    return tuple(min_time, min_time_height);
}

int main() {
    int n, m, b; //집터 세로, 가로, 처음 인벤토리의 블록 개수

    cin >> n >> m >> b;

    vector<int> heights(n * m); //땅의 높이 저장

    for (int i = 0; i < n * m; i++) {
        cin >> heights[i];
    }
    sort(heights.begin(), heights.end(), greater<>()); //내림차순 정렬, 블록 제거 작업 먼저 수행

    //연산
    auto[time, height] = solution(heights, b);

    //출력
    cout << time << ' ' << height;

    return 0;
}
