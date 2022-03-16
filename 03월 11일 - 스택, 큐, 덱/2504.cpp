//2504)괄호의 값

#include <iostream>
#include <stack>
#include <map>

using namespace std;

//문자열이 정수인지 확인하는 함수
//또는 atoi(문자열.c_str()) (스택에 0 삽입하지 않으니)
bool isdigitStr(string s) {
    for (char c: s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

//여는 괄호면 push //닫는 괄호면 top 확인
//top이 숫자면 n으로 저장하고 pop, 그 다음 top 확인
//또 숫자면 n += top 으로 저장하고 pop, 그 다음 top 확인..? //반복, while(top이 숫자가 아닐 때까지)
//여는 괄호면 pop하고 괄호 짝 확인 후 n * 괄호 종류 따라 2or3을 push
//이런 이상한..? 방법으로 풀고 깃허브에 힌트 보니 여닫는 괄호랑 연산 종류 짝지을 수도 있겠네요... -> 2524_2.cpp

//괄호열 string 받아 값 계산하는 함수
int resultCalc(string s) {
    stack<string> st; //스택에 같이 저장할 괄호값은 한자리 수가 아님->char 쓰면 안 됨
    //괄호 짝과 값 map에 저장
    map<char, pair<string, int>> m;
    m[')'] = {"(", 2};
    m[']'] = {"[", 3};

    for (char ch: s) {
//        cout << '*' << ch; //디버깅
        switch (ch) {
            case '(':
            case '[': { //여는 괄호
                string str; //스택에는 string 삽입해야 함, char to string 위해 변수 선언
                str += ch;
                st.push(str);
//                cout << st.top(); //디버깅
                break;
            }
            case ')':
            case ']': //닫는 괄호
                //1. 내부 괄호값 계산
                int n = 0;
                while (!st.empty() && isdigitStr(st.top())) { //마지막 원소가 숫자이면, 스택 비는 경우도 체크
                    n += stoi(st.top()); //괄호열 결합 xy 계산
                    st.pop(); //마지막 숫자 삭제
                }
                //2. 괄호 짝 확인
                if (st.empty() || st.top().compare(m[ch].first)) { //스택이 비었거나 종류 안 맞으면, string 비교는 compare
                    return 0;
                }
                //3. 괄호값 계산
                st.pop(); //여는 괄호 삭제
                if (!n) { //n이 0, 즉 내부값이 존재하지 않으면 곱셈을 위해 1로 만듦
                    n = 1;
                }
                st.push(to_string(m[ch].second * n)); //괄호값 (x), [x] 계산하여 스택에 삽입
//                cout << st.top() << ' '; //디버깅
                break;
        }
    }
    //남은 괄호값 계산하여 반환
    int result = 0;
    while (!st.empty() && isdigitStr(st.top())) { //스택 비어있지 않고 마지막 원소가 숫자이면
        result += stoi(st.top()); //괄호열 결합 xy 계산
        st.pop(); //마지막 숫자 삭제
    }
    if (!st.empty()) { //여는 괄호 남아있으면
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