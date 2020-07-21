#include<iostream>

using namespace std;

/*
	这题用“最大连续子序列”来做会差一点点。因为“最大连续子序列”得到的结果可能只有一个数
	但是这道题要求必须要取到“两个键”，也就是至少要两个数参与运算
*/

int main() {

	int n;
	cin >> n;

	int* arr = new int[n];
	// arr[0] = 0;

	//int t;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		// arr[i] = arr[i - 1] + t;
	}

	/*
		不然就先写个bf的让他超时 时间复杂度应该是n立方
		(果然超时了 70分)
	*/

	//int ans = -101, t = 0;

	//for (int i = 0; i < n - 1; i++) {
	//	for (int j = i + 1; j < n; j++) {
	//		for (int k = i; k <= j; k++) {
	//			t += arr[k];
	//		}
	//		ans = t > ans ? t : ans;
	//		t = 0;
	//	}
	//}

	/*
		尝试下用前缀和 时间复杂度应该降到了n平方
		(又超时了... 还是70分)
	*/

	//int ans = -101;
	//t = 0;

	//for (int i = 1; i < n; i++) {
	//	for (int j = i + 1; j <= n; j++) {
	//		t = arr[j] - arr[i - 1];

	//		ans = t > ans ? t : ans;
	//		t = 0;
	//	}
	//	
	//}

	int ans = -101, dp = 0, predp = 0;

	for (int i = 0; i < n; i++) {
		predp = dp;

		if (dp > 0) {
			dp += arr[i];
			ans = dp > ans ? dp : ans;
		}
		else {
			dp = arr[i];
			if (dp > 0) {
				ans = (dp + predp) > ans ? (dp + predp) : ans;
			}
		}
	}

	if (ans > 0) {
		cout << ans;
	}
	else {
		cout << "Game Over";
	}

	return 0;
}