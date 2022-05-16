//Java vs C++

#include <iostream>

using namespace std;

const int DIFF = 'a'-'A'; //소문자와 대문자 아스키코드 차이, 32

//C++ to Java
string cToJava(string name) {
    for (int i = 0; i < name.length(); i++) {
        if (name[i] == '_') { //'_' 나오면
            name.erase(i, 1); //삭제
            name[i] -= DIFF; //소문자를 대문자로
        }
    }
    return name;
}

//Java to C++
string javaToC(string name) {
    for (int i = 0; i < name.length(); i++) {
        if (name[i] - 'A' >= 0 && name[i] - 'A' <= 25) { //대문자 나오면
            name[i] += DIFF; //대문자를 소문자로
            name.insert(i, "_"); //'_' 추가
            i++; //'_'추가했으니 i증가
        }
    }
    return name;
}

//형식 파악하기, 0은 에러, 1은 C++, 2는 Java
int whatForm(string name) {
    //첫 문자는 무조건 소문자, 마지막 문자에 언더바 올 수 없음
    if (name[0] - 'a' < 0 || name[0] - 'a' > 25 || name[name.length() - 1] == '_') {
        return 0;
    }

    bool is_underbar = false, is_upper = false;
    for (int i = 0; i < name.length(); i++) {
        if (name[i] == '_') {
            //언더바 연속으로 오면 안 됨
            if (i < name.length() - 1 && name[i + 1] == '_') return 0;
            is_underbar = true;
        } else if (name[i] - 'A' >= 0 && name[i] - 'A' <= 25) is_upper = true;
        else if (name[i] - 'a' < 0 || name[i] - 'a' > 25) { //소문자 아닌 다른 입력 들어옴
            return 0;
        }
    }

    if (is_upper && is_underbar) return 0; //둘 모두 있으면 안 됨
    if (is_underbar) return 1; //c++
    if (is_upper) return 2; //java
    return 3; //두 형식 모두 가능(소문자만 존재)
}

int main() {
    string var_name; //변수명
    getline(cin, var_name); //공백 포함 입력받기

    int form = whatForm(var_name);

    //출력
    if (form == 0) {
        cout << "Error!";
    } else if (form == 1) {
        cout << cToJava(var_name);
    } else if (form == 2) {
        cout << javaToC(var_name);
    } else {
        cout << var_name;
    }

    return 0;
}