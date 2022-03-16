//2504)

//여는 괄호면 숫자 곱하기, 닫는 괄호면 더하기, 닫히지 않은 괄호(남아있는 여는 괄호)는 새로 여는 괄호들에 곱하기 영향 계속됨
//(()[[]])([]) -> 2(2+3*3)+2*3 -> 결과에는 2*2(*2남음), 2*3*3(남지x), 2*3(남지x)이 순서대로 더해짐
//([이면 곱하고, (), []단위일 때 계산 결과 더하고, )]이면 곱해지는 수에서 해당 괄호의 영향 제외하기

#include <iostream>
#include <stack>
#include <map>

using namespace std;

int resultCalc(string s) {
    int result = 0, mul_num = 1; //결과, 계산(곱셈) 중인 수

    stack<char> st; //여는 괄호 저장하는 스택
    //괄호 짝과 값 map에 저장
    map<char, pair<char, int>> m;
    m[')'] = {'(', 2};
    m['('] = {')', 2};
    m[']'] = {'[', 3};
    m['['] = {']', 3};

    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
            case '(':
            case '[': //여는 괄호
                st.push(s[i]);
                mul_num *= m[s[i]].second; //괄호값 곱하기
                break;
            case ')':
            case ']':
                //짝 확인
                if (st.empty() || st.top() != m[s[i]].first) {
                    return 0;
                }
                //괄호값 더하기
                if (s[i - 1] == m[s[i]].first) { //원래 문자열이랑 비교해야 함
                    result += mul_num;
                }
                //계산 중인 괄호값 업데이트
                mul_num /= m[s[i]].second;
                st.pop();
                break;
        }
    }
    if (!st.empty()) { //스택 비어있는지 확인
        return 0;
    }
    return result;
}

int main() {
    string str; //괄호열 문자열
    //입력
    cin >> str;

    //출력
    cout << resultCalc(str);
    return 0;
}