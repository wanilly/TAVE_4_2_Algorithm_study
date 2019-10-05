#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	int n;

	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];


}

/*
4
1ÀÇ ÇÕ
(1 + 1 + 2) * 3
(1 + 3) * 2
(2 + 2)
ÃÑ 7

5
1ÀÇ ÇÕ
(1 + 1 + 1 + 2) * 4
(1 + 1 + 3) * 3
(1 + 2 + 2) * 3
(2 + 3) * 2
ÃÑ 10

6
1ÀÇ ÇÕ
(1 + 1 + 1 + 1 + 2) * 5
(1 + 1 + 2 + 2) * 6
(2 + 2 + 2)
(1 + 2 + 3) * 6
(1 + 1 + 1 + 3) * 4
(3 + 3)
ÃÑ 24

7 = 7 + 10 + 24




*/
