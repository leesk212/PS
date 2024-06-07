#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int map[31][31];
bool visited[31][31] = { false, };

int n, m;
int ans = -1;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int cnt = 0;

void init() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char temp;
			cin >> temp;
			if (temp == '*') map[i][j] = 0;
			else map[i][j] = 1;
		}
	}
}


void dfs(int x, int y) {
	visited[x][y] = true;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m) {
			continue;
		}

		if (map[next_x][next_y] == 0) {
			continue;
		}

		if (visited[next_x][next_y] == 1) {
			continue;
		}
		dfs(next_x, next_y);
	}
}

void game() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				cnt = 0;
				dfs(i, j);
				if (ans < cnt) {
					ans = cnt;
				}
			}
		}
	}
}


int main(void) {
	freopen("ÅØ½ºÆ®.txt", "r", stdin);

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();
	game();

	cout << ans;

	return 0;

}