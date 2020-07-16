#include<iostream>
#include<memory.h>

using namespace std;

int main() {

	int M, T, U, F, D;
	while (cin >> M >> T >> U >> F >> D) {
		char c;
		int sum = 0;
		int ans = 0;
		for (int i = 1; i <= T; i++) {

			cin >> c;

			if ('f' == c) {
				sum += F * 2;
			}
			else {
				sum += U + D;
			}

			if (sum <= M) {
				ans++;
			}
		}

		cout << ans;
	}

	return 0;
}