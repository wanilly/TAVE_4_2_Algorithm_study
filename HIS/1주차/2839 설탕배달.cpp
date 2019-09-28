#include<iostream>
using namespace std;

int main() {
	int N = 0, three_cnt = 0;
	cin >> N;
	while (1) {
		// 범위를 벗어난 경우 종료
		if (N < 0) {
			cout << "-1" << endl;
			break;
		}
		// 5의 배수로 나뉘어지는 경우 결과 출력 후 종료
		else if (N % 5 == 0) {
			cout << (N / 5) + three_cnt << endl;
			break;
		}
		// 5의 배수로 나뉘어지지 않는 경우 3 빼보기
		else {
			N -= 3;
			three_cnt++;
		}
	}
}