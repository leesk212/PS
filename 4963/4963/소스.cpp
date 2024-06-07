#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

int w, h;
int map[51][51] = { 0, };
bool visited[51][51] = { 0, };
int ans = 0;

int dx[8] = { -1,1, 0, 0, -1, -1,1,1 };
int dy[8] = { 0, 0,-1, 1, 1, -1,1,-1 };


void init() {
	cin >> w >> h;
	if (w == 0 && h == 0) {
		exit(0);
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
		}
	}
}

void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 8; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		//if (0 <= next_x && 0 <= next_y && next_x < w && next_y < h) {
		//	if (map[next_x][next_y] && !visited[next_x][next_y]) {
		//		visited[next_x][next_y] = true;
		//		dfs(next_x, next_y);
		//	}
		//}

		if (next_x < 0 || next_y < 0 || next_x > w || next_y > h) {
			continue;
		}
		if (map[next_x][next_y] == 0) {
			continue;
		}
		if (visited[next_x][next_y] == 1) {
			continue;
		}
		visited[next_x][next_y] = true;
		dfs(next_x, next_y);

	}
}

void game() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (visited[i][j] == 0 && map[i][j]==1) {
				dfs(i, j);
				ans = ans + 1;
			}
		}
	}
}

int main(void) {
	freopen("ÅØ½ºÆ®.txt", "r", stdin);

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		init();
		game();

		cout << ans << endl;

		//Let's new game
		ans = 0;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));


	}
	return 0;
}