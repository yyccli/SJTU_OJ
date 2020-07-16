#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

#define L 101

struct point {
	int x;
	int y;
	int loop;
};

int map[L][L];

int x[4] = { -1, 0, 1, 0 };
int y[4] = { 0, -1, 0, 1 };

queue<point> q;

int main() {

	int l;
	cin >> l;

	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= l; j++) {
			cin >> map[i][j];
			if (1 == map[i][j]) {
				point t = { i, j, 0 };
				q.push(t);
			}
		}
	}

	point p = {0,0,0}, next;
	
	while (!q.empty()) {
		p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			next.x = p.x + x[i];
			next.y = p.y + y[i];

			if (next.x >= 1 && next.x <= l && next.y >= 1 && next.y <= l && 0 == map[next.x][next.y]) {
				map[next.x][next.y] = 1;
				next.loop = p.loop + 1;
				q.push(next);
			}
		}
	}

	int ans = p.loop;

	cout << p.loop;

	return 0;
}