#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;


int N, M;
int a, b;

vector<int> graph[2001];
bool visitied[2001];
int ans = 0;

void init() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a); //양방향
	}
}

void check_relation(int cur_people_number,int depth) {
	if (depth == 4) {
		ans = 1;
		cout << ans;
		exit(0);
	}
	visitied[cur_people_number] = true;
	for (int i = 0; i < graph[cur_people_number].size(); i++) {
		int next_people_number = graph[cur_people_number][i];
		if (!visitied[next_people_number]) {
			check_relation(next_people_number, depth+1);
			visitied[next_people_number] = false;
		}
	}
}

int main(void) {
	freopen("텍스트.txt", "r", stdin);

	init();

	for (int i = 0; i < M; i++) {
		memset(visitied, false, sizeof(visitied));
		check_relation(i,0);
	}

	cout << ans;

	return 0;

}