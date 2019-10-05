#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

int main(void) {

	int res = 0;
	string str;
	stack<int> mystack;

	getline(cin, str);

	for (int i = 0; i < str.size(); i++) {

		if (str[i] == '(')	// 여는 괄호이면 스택에 저장
			mystack.push(1);
		else if (str[i] == ')') {	// 닫는 괄호이면 여는 괄호 하나를 스택에서 삭제
			mystack.pop();

			if (str[i - 1] == '(')	// 만약, 레이저라면 레이저 전에 저장된 막대들이 한 번 잘리므로 총 갯수 여는 괄호 수만큼 추가
				res += mystack.size();
			else					// 만약, 막대의 끝이라면 기존 막대 수 1 추가
				res++;
		}
	}

	printf("%d", res);
	return 0;
}