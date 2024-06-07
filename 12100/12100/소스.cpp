#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int map[21][21] = { 0, };
int N;

queue<int,queue<int,int>> after_move_and_return(queue<int,int> moving_position, queue<int,int> changed_value) {
	//value, pos_x, pos_y



}

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
}

void game() {

}

int main(void) {
	freopen("≈ÿΩ∫∆Æ.txt", "r", stdin);

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();


	return 0;

}