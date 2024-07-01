/*
- Type : BFS(����)
- INDEX : BJ-GOLD4-2573
- NAME : ����
*/

#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

int N, M;
int candi_melt_map[301][301] = { 0, };
int melt_map[301][301] = { 0, };
int visited_map[301][301] = { 0, };
int melting_time = 0;



void init() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> melt_map[i][j];
		}
	}

}


int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs(int start_x, int start_y) {
	queue<pair<int,int>> q;
	q.push({ start_x ,start_y });
	
	visited_map[start_x][start_y] = true;
	
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			
			if (melt_map[next_x][next_y] == 0) continue;

			if (next_x < 0 || next_y < 0 || next_x >= M || next_y >= N) continue;
			
			if (visited_map[next_x][next_y] == 1) continue;

			visited_map[next_x][next_y] = 1;
			q.push({ next_x ,next_y });
		}
	}
}

int check_ice_count() { //�������� ��̵����� Ȯ��
	memset(visited_map, false, sizeof(visited_map));


	int ice_count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited_map[i][j] == 1) continue; //������ �湮������ �湮�������� (����������� �̾���������)
			
			if (melt_map[i][j] != 0) { //0�� �ƴѰ��� Ȯ���ϸ�, �ش� ��ġ���� BFS ������ �� ���� Ȯ���ϱ�
				ice_count++;
				if (ice_count == 2) {
					return 1; //find 2 ice, Let program finish
				}
				bfs(i, j);
			}
		}
	}
	return 0;
}

void melting_ice(int melting) { // �������� ���̱�

	memset(candi_melt_map, 0, sizeof(candi_melt_map));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (melt_map[i][j] != 0) {
				int near_count = 0;
				if (i - 1 >= 0) if (melt_map[i - 1][j] == 0) near_count++;
				if (i + 1 <= M) if (melt_map[i + 1][j] == 0) near_count++;
				if (j - 1 >= 0) if (melt_map[i][j - 1] == 0) near_count++;
				if (j + 1 <= N) if (melt_map[i][j + 1] == 0) near_count++;

				int candi = melt_map[i][j] - near_count;
				if (candi < 0)	candi_melt_map[i][j] = -1;
				else candi_melt_map[i][j] = candi;

			}
		}
	}

	//update
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (candi_melt_map[i][j] != -1)	melt_map[i][j] = candi_melt_map[i][j];
			else {
				melt_map[i][j] = 0;
			}
		}
	}
}


void game() { 
	
	while (1) {
		if (check_ice_count() == 1) {
			cout << melting_time;
			break;
		}
		else {
			melting_time++;
			melting_ice(melting_time);
		}
	
		int isthere_any_ice = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (melt_map[i][j] != 0) {
					isthere_any_ice = 1;
					break;
				}
			}
		}
		if (isthere_any_ice == 0) {
			cout << 0;
			break;
		}
	}
}


int main(void) {
	freopen("�ؽ�Ʈ.txt", "r", stdin);

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();
	game();

	return 0;
}