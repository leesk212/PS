#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

int N;
int ans = 0;
vector<pair<int,int>> graph[11];
bool visited[11] = { false, };

void dfs(int x) {
	visited[x] = true;
	for (int i = 0; i < graph[x].size(); i++) {
		int next_x = graph[x][i].first;

		if (graph[x][i].second == 0) {
			continue;
		}

		if (!visited[next_x]) {
			ans = ans + graph[x][i].second;
			dfs(next_x);
		}
	}
}

int main() {
	
	// ��ȸ�� �ѹ��� ���ƾ���..(�̰� ����Ʈ �ε�)

	freopen("�ؽ�Ʈ.txt", "r", stdin);
	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			
			if (i == j) continue;
			graph[i + 1].push_back(make_pair(j+1,temp));
		}
	}




}