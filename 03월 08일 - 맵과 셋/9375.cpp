//9375)패션왕 신해빈

#include <iostream>
#include <map>

using namespace std;

int main() {
    int t; //테스크 케이스 개수
    cin >> t;

    while (t--) { //테스크 케이스 개수만큼 반복
        int n; //의상의 수
        map<string, int> clothes; //의상의 종류를 key, 종류별 개수를 value로 저장
        cin >> n;
        while (n--) { //의상 수만큼 반복해서 입력
            string name, type; //의상의 이름, 종류
            cin >> name >> type;

//            //개수 세기(20291 문제와 동일)
//            auto iter = clothes.find(type);
//            if (iter == clothes.end()) { //새로운 의상 종류이면
//                clothes[type] = 1; //map에 삽입, 의상 개수는 1
//            } else { //이미 map에 저장된 의상 종류이면
//                (iter->second)++; //의상 개수 1 증가
//            }
            //[리뷰]
            clothes[type]++;
        }

        //연산
        //경우의 수는 종류별 개수 + 1(해당 종류를 입지 않음) 모두 곱하고 -1(알몸)
        int result = 1;
        for (auto iter = clothes.begin(); iter != clothes.end(); iter++) {
            result *= (iter->second) + 1;
        }
        result--; //알몸인 경우 제외

        //출력
        cout << result << '\n';
    }
    return 0;
}