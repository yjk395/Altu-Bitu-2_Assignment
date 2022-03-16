//2108)통계학

#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int num_size; //수의 개수(홀수)

vector<int> num_list;
map<int, int> num_cnt;

//산술평균
int meanCalc() {
    int result = 0;
    for (auto iter: num_cnt) {
        result += iter.first * iter.second; //숫자와 빈도수 곱하여 더함
    }
    return round(result / (float) num_size);
}

//중간값
int medianCalc() {
    int count = 0;
    for (auto iter: num_cnt) { //작은 수부터 빈도 수 더함
        count += iter.second;
        if (count >= num_size / 2 + 1) //중간 지점을 넘은 순간 해당 숫자 반환
            return iter.first;
    }
}

//최빈값 구하기 위한 비교함수
bool cmp(const int &a, const int &b) {
    if (num_cnt[a] != num_cnt[b]) {
        return num_cnt[a] < num_cnt[b]; //최빈값 오름차순
    }
    return a > b; //최빈값 같으면 숫자 내림차순
}

//최빈값
int modeCalc() {
    if(num_size == 1) //원소가 하나인 경우
        return num_list[0];

    sort(num_list.begin(), num_list.end(), cmp); //조건대로 정렬
    int last = num_list.size()-1; //중복 없이 리스트에 넣어뒀음->마지막 인덱스가 수의 개수가 아님
    int a = num_list[last], b = num_list[last-1]; //마지막과 그 앞 원소 가져오기
//    cout<<'{'<<a<<' '<<b<<'}'; //디버깅

    if (num_cnt[a] == num_cnt[b]) {
        return b; //마지막, 이전 원소 최빈값 같으면 이전 원소 반환
    }
    return a; //최빈값 가장 높은 원소 반환
}

//범위
int rangeCalc(){
//    cout<<'['<<(--num_cnt.end())->first<<' '<<num_cnt.begin()->first<<']'; //디버깅
    return (--num_cnt.end())->first - num_cnt.begin()->first; //end()는 마지막 원소 다음을 가리킴
}

int main() {
    int n, number; //입력받는 수
    //입력
    cin >> n;
    num_size = n;

    while (n--) {
        cin >> number;
        if (!num_cnt[number]) {
            num_list.push_back(number); //중복 없이 vector에 숫자 삽입
        }
        num_cnt[number]++; //map에서 빈도 카운트
    }

    //출력
    cout << meanCalc() << '\n' << medianCalc()<<'\n'<<modeCalc()<<'\n'<<rangeCalc();

    return 0;
}