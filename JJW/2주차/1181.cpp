#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
//비교 기준 바꾸기 위해 사용 sort함수에서 3번째 인자로 비교 기준이 될 함수 구현
//bool 함수이름 (const 변수형& a, const 변수형& b){
      // return (a가 b보다 앞에 올 조건);

bool compare(const string &a, const string &b) {
    //길이가 같다면 사전 앞 순서대로
    if (a.length() == b.length())
        return (a < b);
    //길이가 같지 않다면 길이가 작은 
    else
        return a.length() < b.length();

}

int main() {
	ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    string str[20000];
    for (int i = 0; i < test; i++) {
        cin >> str[i];
    }

    //3번째 인자로 특정 비교 함수 
    sort(str, str+test, compare);
    
    for (int i = 0; i < test; i++) {
        if (i != 0 && str[i] == str[i - 1]) 
			continue; //앞에 중복인 단어가 있다면 continue로 빼준다 
        else
        cout << str[i] << endl;    
    }

    return 0;

}
