//1918)후위 표기식

#include <iostream>
#include <stack>

using namespace std;

//수식에서 연산자를 스택에 저장, 우선 순위를 따져 삽입 및 삭제하며 출력
//(의 경우 상황 따라 다른 연산자와의 순위 다름, 수식에서 읽은 연산자가 들어갈 때의 우선순위와 스택에 저장된 원소의 우선순위를 비교
//isp가 크면 pop하여 출력, 읽은 연산자를 push

//연산자의 우선순위
int icp(char op) { //in-coming priority 스택 진입 우선순위
    switch (op) {
        case '(': //읽으면 무조건 push한다
            return 3;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
}

int isp(char op) { //in-stack priority 스택 내부 우선순위
    switch (op) {
        case '(': //읽은 연산자를 무조건 push하게 한다
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '#': //스택에 push되는 첫 연산자
            return 0;
    }
}

//연산자인지 아닌지 체크하는 함수
//문제에서 피연산자가 알파벳으로 주어짐(런타임에러 원인 여기였음)
bool isOperator(char c) {
    if (c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

//중위 표기식을 받아 후위 표기식으로 출력하는 함수
void printPostfix(string s) {
    stack<char> st; //연산자 저장할 스택
    st.push('#'); //가장 우선순위가 낮은 문자 삽입, 읽은 연산자를 무조건 push하며 스택이 비어있지 않게 함

    for (char ch: s) {
        if (!isOperator(ch)) { //피연산자는 바로 출력
            cout << ch;
        } else if (ch == ')') { //닫는 괄호면 여는 괄호 이후 읽은 연산자 모두 출력
            while (st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop(); //여는 괄호 삭제
        } else { //여는 괄호 및 연산자는 우선순위에 따라 삽입 및 출력
            while (isp(st.top()) >= icp(ch)) {
                cout << st.top();
                st.pop();
            }
            st.push(ch); //읽은 연산자를 스택에 삽입
        }
    }

    //스택에 남은 연산자 출력
    while (st.top() != '#') {
        cout << st.top();
        st.pop();
    }
}

int main() {
    string infix; //중위 표기식
    //입력
    cin >> infix;

    //연산 및 출력
    printPostfix(infix);
    return 0;
}