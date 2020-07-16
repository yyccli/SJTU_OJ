#include<iostream>

using namespace std;

int main() {
	int h, ch, n, t, ans = 0;

	cin >> h >> ch >> n;

	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t <= h + ch) {
			ans++;
		}
	}

	cout << ans;

	return 0;
}