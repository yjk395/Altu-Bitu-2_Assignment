//호텔 방 배정

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<long long> room_number;
unordered_map<long long, long long> sold_room; //아 parent배열에서 값을 다음으로 나올 빈 방으로

long long findNextRoom(long long n) {
    if (sold_room[n] == 0) { //방이 비어있으면
        sold_room[n] = n + 1; //value는 다음 방을 가리킴
        return n;
    }
    return sold_room[n] = findNextRoom(sold_room[n]); //다음 빈 방 찾아서 업데이트 후 반환
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    for (int i = 0; i < room_number.size(); i++) {
        answer.push_back(findNextRoom(room_number[i]));
    }

    return answer;
}

int main() {
    long long k; //전체 방 개수
    cin >> k;
    int num; //손님 수

    while (cin >> num) {
        room_number.push_back(num);
    }

    vector<long long> answer = solution(k, room_number);

    for (auto i: answer) {
        cout << i << ' ';
    }

    return 0;
}