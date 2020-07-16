#include<iostream>
#include<memory.h>

using namespace std;

#define MAX 1001

int arr[MAX][MAX];
int map[MAX][MAX];

int main() {
	
	int l, w;
	cin >> l >> w;

	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> arr[i][j];
		}
	}

	int a, b;
	cin >> a >> b;

	int m = 0;

	memset(map, 0, sizeof(map));

	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= w; j++) {
			map[i][j] = map[i - 1][j] + map[i][j - 1] - map[i - 1][j - 1] + arr[i][j];

			if (i >= a && j >= b) {
				m = m > map[i][j] - map[i - a][j] - map[i][j - b] + map[i - a][j - b] ? m : map[i][j] - map[i - a][j] - map[i][j - b] + map[i - a][j - b];
			}
		}
	}


	//int temp;

	//for (int p = 0; p < l - a + 1; p++) {
	//	for (int q = 0; q < w - b + 1; q++) {
	//		temp = 0;
	//		for (int x = 0; x < a; x++) {
	//			for (int y = 0; y < b; y++) {
	//				temp += arr[p + x][q + y];
	//			}
	//		}

	//		m = temp > m ? temp : m;
	//	}
	//}

	cout << m;

	return 0;
}