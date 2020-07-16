#include<iostream>
#include<cstdio>

using namespace std;

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {

		int h_r[9][9] = { 0 };
		int h_c[9][9] = { 0 };
		int h_sub[9][9] = { 0 };

		int t;

		for (int x = 0; x < 9; x++) {
			for (int y = 0; y < 9; y++) {
				cin >> t;

				h_r[x][t - 1] = 1;
				h_c[y][t - 1] = 1;
				h_sub[(x / 3) * 3 + y / 3][t - 1] = 1;

			}
		}

		bool isWrong = false;

		for (int x = 0; x < 9; x++) {
			for (int y = 0; y < 9; y++) {
				if (0 == h_r[x][y] || 0 == h_c[x][y] || 0 == h_sub[x][y]) {
					isWrong = true;
					break;
				}
			}
		}

		if (isWrong) {
			cout << "Wrong" << endl;
		}
		else {
			cout << "Right" << endl;
		}

		getchar();

	}

	return 0;
}