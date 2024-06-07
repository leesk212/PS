#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int F, S, G, U, D;
int moving_dir[2] = { 0, };
int visted_floor[1000001] = { 0, };
int ans = 0;

void init() {
	cin >> F // 전체 층수 
		>> S // 유저가 현재 있는 층수 (start 느낌)
		>> G // 목적지 (goal의 느낌)
		>> U // 위로 가는층 누르면 몇층 위로 올라가는지 계산 느낌
		>> D; // 아래 가는층 누르면 몇층 위로 내려가는지 계산 느낌
}


void dfs(int cnt,int cur) {
	
	if (cur == G) {
		ans = cnt;
		cout << ans;
		exit(1);
	}

	for (int i = 0; i < 2; i++) {
		int next = cur + moving_dir[i];
		
		//혹시라도 층수를 넘겼을 경우! 그냥 넘어가자!
		if (next > F || next < 0) continue; 
		
		//해당 층수를 방문했으면 굳이 또 방문해야할까? ㄴㄴ
		if (visted_floor[next] == 1) continue;

		visted_floor[next] = 1;
		dfs(cnt + 1, next);
		visted_floor[next] = 0;
	}

}


void game() {
	moving_dir[0] = U;
	moving_dir[1] = -1*D;
	int current_pos = S;

	dfs(0,current_pos);
}


int main() {
	freopen("텍스트.txt", "r", stdin);

	init();
	game();

	if (ans == 0) {
		cout << "use the stairs";
	}


}
