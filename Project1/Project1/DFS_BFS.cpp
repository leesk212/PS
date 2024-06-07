#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> result_bfs;
vector<int> result_dfs;

vector<int> graph[10002];
bool visited[10001] = { 0, };
queue<int> q;

void dfs(int start) {
	visited[start] = true;

	result_dfs.push_back(start);

	for (int i = 0; i < graph[start].size(); i++) {
		if (!visited[graph[start][i]]) {
			dfs(graph[start][i]);
		}
	}
}

void bfs(int start) {
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		//cout << x;
		result_bfs.push_back(x);

		for (int i = 0; i < graph[x].size(); i++) {
			if (!visited[graph[x][i]]) {
				q.push(graph[x][i]);
				visited[graph[x][i]] = true;
			}
		}
	}
}

int main(void) {

//	freopen("input.txt", "r", stdin);

	int N, M, V;
	cin >> N >> M >> V;
//	cout << N << M << V;

	for (int i = 1; i <= M; i++) {
		int start;
		int end;
		cin >> start >> end;

		graph[start].push_back(end);
		graph[end].push_back(start);
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end()); // ³·Àº ¼ýÀÚºÎÅÍ Å½»ö.
	}


	dfs(V);
	//Re-initialize
//	fill(visited, visited + 1002, 0);
	memset(visited, false, sizeof(visited));
	bfs(V);


	for (int i = 0; i < result_dfs.size(); i++) {
		cout << result_dfs[i] << " ";
	}
	cout << '\n';
	for (int i = 0; i < result_bfs.size(); i++) {
		cout << result_bfs[i] << " ";
	}


	return 0;

}