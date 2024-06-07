#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;


int N;
int M;
int x, y;

int answ = -1;

vector<int> graph[101];
int visited[101];

void check_relation_count(int current,int count) {
	if (current == y) {
		//How?
		answ = count;
		return;
	}

	visited[current] = true;

	for (int i = 0; i < graph[current].size(); i++) {
		int next_step = graph[current][i];

		if (visited[next_step] == 0) {
			check_relation_count(next_step, count + 1);
		}

	}

}

void init() {
	cin >> N;
	cin >> x >> y;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int temp_x, temp_y;
		cin >> temp_x >> temp_y;

		graph[temp_x].push_back(temp_y);
		graph[temp_y].push_back(temp_x);   

	}
}

int main(void) {
	freopen("≈ÿΩ∫∆Æ.txt", "r", stdin);

	init();
	int count = 0;
	check_relation_count(x,count);
	cout << answ;
	return 0;

}