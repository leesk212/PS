#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

int M, N, H;

int map[100][100][100] = { 0, };
int dist[100][100][100] = { 0, };
int visited[100][100][100] = { 0, };

int dh[6] = { -1,1,0,0,0,0 };
int dx[6] = { 0,0,-1,1,0,0 };
int dy[6] = { 0,0,0,0,-1,1 };

int istherecandi = 0;

void init() {
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				cin >> map[i][j][k];
				dist[i][j][k] = map[i][j][k];
			}
		}
	}
}

void bfs(int x, int y, int h) {
	queue<pair<int,pair<int, int>>> q;
	q.push({ h,{x,y} });

	while (!q.empty()) {
		int cur_h = q.front().first;
		int cur_x = q.front().second.first;
		int cur_y = q.front().second.second;


		q.pop();

		for (int i = 0; i < 6; i++) {
			int nh = cur_h + dh[i];
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nx < 0 || ny < 0 || nh < 0 || nx > 100 || ny > 100 || nh > 100) {
				continue;
			}
			if (map[nh][nx][ny] == 1 || map[nh][nx][ny] == -1) {
				continue;
			}
			if (visited[nh][nx][ny] == 1) {
				continue;
			}
			
			dist[nh][nx][ny] = dist[cur_h][cur_x][cur_y] + 1;
			
			visited[nh][nx][ny] = 1;

			q.push({ nh,{nx,ny} });
		}

	}
}

void game() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (map[i][j][k] == 0 || map[i][j][k] == -1) {
					continue;
				}
				if (visited[i][j][k] == 1) {
					continue;
				}
				istherecandi = 1;
				bfs(i, j, k);
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
	
	//[After Game] Condition 1: Is there any candi ?
	if (istherecandi == 0) {
		cout << 0;
		return 0;
	}

	//[After Game] Condition 2: Is there any location that can't visit ?
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < H; k++) {
				if (dist[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}

	return 0;

}