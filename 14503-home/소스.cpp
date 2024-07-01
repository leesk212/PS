/*
- Type : DFS
- INDEX : 14503
- NAME : 로봇청소기
*/

#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

#define MAX 50

int N, M;
int r, c;
int d; // 0->북쪽 , 1-> 오른쪽, 2-> 남쪽, 3->왼쪽
int map[MAX][MAX] = { 0, };
int visited[MAX][MAX] = { 0, };
int visited_count = 0;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void init() {
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	visited[r][c] = 1;
	visited_count++;

}

void dfs() {
	
	for (int i = 0; i < 4; i++) {

		int next_d = (d + 3 -i) % 4; // 0->3, 1->0, 2->1, 3->2 // (왼쪽)

		int next_r = r + dx[next_d];
		int next_c = c + dy[next_d];

		if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= M || map[next_r][next_c] == 1)
		{
			continue;
		}

		if (map[next_r][next_c] == 0 && visited[next_r][next_c] == 0)
		{
			visited[next_r][next_c] = 1;
			r = next_r;
			c = next_c;
			d = next_d;
			visited_count++;
			dfs();
		}
	}
	int back_idx = d > 1 ? d - 2 : d + 2; // 0->2, 1->3, 2->0, 3->1 (후진)
	int back_r = r + dx[back_idx];
	int back_c = c + dy[back_idx];

	if (back_r >= 0 && back_r <= N || back_c >= 0 || back_c <= M)
	{
		if (map[back_r][back_c] == 0)
		{
			r = back_r;
			c = back_c;
			dfs();
		}
		else
		{
			cout << visited_count << endl;
			exit(0);
		}
	}

}

void game(){
	dfs();
}

int main(void) {
	freopen("텍스트.txt", "r", stdin);

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();
	game();

	return 0;
}