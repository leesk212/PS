#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[100001] = { false, };
int next_step[2] = { -1,1 };
int count=0;
int N, K;

void bfs(int x) {
	queue<pair<int,int>> q;
	q.push(make_pair(x, 0));
	visited[x] = true;
	
	while (!q.empty()) {
		int x = q.front().first;
		int count = q.front().second;
		int next_x = 0;

		if (x == K) {
			
			cout << count;
			break;
		}

		q.pop();

		for (int i = 0; i < 3; i++) {
			if (i == 2) {
				next_x = x * 2;
			}
			else next_x = x + next_step[i];
			
			if (next_x >= 100001 || next_x < 0) {
				continue;
			}

			if (!visited[next_x]) {
				q.push(make_pair(next_x, count+1));
			}
		}
	}
}

int main(void) {
	freopen("ÅØ½ºÆ®.txt", "r", stdin);
	cin >> N >> K;
	bfs(N);
	return 0;
}