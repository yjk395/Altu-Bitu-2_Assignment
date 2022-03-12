//20291)파일 정리

#include <iostream>
#include <map>

using namespace std;

int main() {
    int n; //바탕화면에 있는 파일의 개수
    string file_name; //파일의 이름
    map<string, int> extension; //확장자 이름을 key, 그 확장자 파일의 개수를 value로 저장
    //입력
    cin >> n;
    while (n--) {
        cin >> file_name;

        //.은 반드시 한 번 등장, 위치 찾아서 그 뒤에 나오는 부분 문자열 구하면 확장자가 됨
        string ext = file_name.substr(file_name.find('.') + 1); //파일 확장자
        //개수 세기
        auto iter = extension.find(ext);
        if (iter == extension.end()) { //새로 발견한 확장자이면
            extension[ext] = 1; //map에 삽입, 파일 개수는 1
        } else { //이미 map에 저장된 확장자이면
            (iter->second)++; //파일 개수 1 증가
        }
    }

    //출력
    for (auto iter = extension.begin(); iter != extension.end(); iter++) {
        cout << iter->first << ' ' << iter->second << '\n';
    }

    return 0;
}