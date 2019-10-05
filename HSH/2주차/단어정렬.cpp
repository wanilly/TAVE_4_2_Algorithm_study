#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 비교 함수 -> 문자열 길이를 비교한다. 같으면
bool compare(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;	// 아스키 값이 크면 z에 가깝다
	}
	else {
		return a.size() < b.size();
	}
}
int main() {

	vector <string> a;
	string temp;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		a.push_back(word);
	}

	sort(a.begin(), a.end(), compare);

	for (int i = 0; i < n; i++) {

		if (temp == a[i])
			continue;

		cout << a[i] << '\n';
		temp = a[i];
	}
	return 0;
}
/*
string으로 단어를 받고 sort 함수를 이용해 정렬을 하는데 compare 함수를 따로 길이순으로 반환을 한 후에

길이가 같다면 알바벳순으로 오름차순 정렬을 하는 형식이다.

string size 함수를 이용해 길이를 파악하고 길이가 같다면 단순 비교를 통해 함수
*/