#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;


int T;
int M, N, K;
int X, Y;

int map[51][51];
bool visited[51][51];
int ans;

void init() {
	cin >> M >> N >> K;

	for (int i = 0; i < K; i++) {
		int temp_x, temp_y;
		cin >> temp_x >> temp_y;
		map[temp_x][temp_y] = 1;
	}
}

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs(int x,int y) {
	queue<pair<int,int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];

			if (next_x < 0 || next_y < 0 || next_x > 50 || next_y > 50) {
				continue;
			}
			if (map[next_x][next_y] == 0) {
				continue;
			}
			if (visited[next_x][next_y] == 1) {
				continue;
			}
			visited[next_x][next_y] = true;
			q.push({ next_x,next_y });
		}
	}

}

void game() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 1) {
				continue;
			}
			if (map[i][j] == 0) {
				continue;
			}
			ans++;
			bfs(i, j);
		}
	}
}

int main(void) {
	freopen("ÅØ½ºÆ®.txt", "r", stdin);

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
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