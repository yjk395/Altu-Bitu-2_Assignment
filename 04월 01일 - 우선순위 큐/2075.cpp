//N번째 큰 수

#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> numbers; //숫자 저장하는 우선순위 큐
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int num;
            cin>>num;
            numbers.push(num);
            if(numbers.size() > n){
                numbers.pop(); //가장 작은 수 필요없으니 삭제
            }
        }
    }

    cout<<numbers.top();

    return 0;
}