#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int N, M, K;

int sero[4] = { -1,1,0,0 }; //상하
int garo[4] = { 0,0,-1,1 }; //좌우

int map[501][501] = { 0, };
int visited[501][501] = { 0, };

int count;

void init() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int temp;
			cin >> temp;
			map[i][j] = temp;
		}
	}
}

void bfs(int x,int y) {
	queue<pair<int,int>> q;
	q.push({ x,y });
	visited[x][y] = 1;


	while (!q.empty()) {
		
		int cur_x = q.front().first;
		int cur_y = q.front().second;


		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + garo[i];
			int next_y = cur_y + sero[i];

			if (next_x <0 || next_y <0 || next_x >= N || next_y >= M) {
				continue;
			}

			if (visited[next_x][next_y] == 1) {
				continue;
			}

			int diff = abs(map[cur_x][cur_y] - map[next_x][next_y]);
			if (diff > K) {
				continue;
			}
			
			q.push({ next_x, next_y });
			visited[next_x][next_y] = 1;
		}

	}

}

int main(void) {
	freopen("텍스트.txt", "r", stdin);

	init();
	int turn_on_off = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j<M; j++) {

			if (!visited[i][j]) {
				turn_on_off++;
				bfs(i, j);
					
			}
		}
	}

	cout << turn_on_off;

	return 0;

}