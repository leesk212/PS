#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int F, S, G, U, D;
int moving_dir[2] = { 0, };
int visted_floor[1000001] = { 0, };
int distance_[1000001] = { 0, }; // �ش� ��ġ�� ���µ� ���� �ɸ��� �ð� (�ش繮���� Key Point)

void init() {
	cin >> F // ��ü ���� 
		>> S // ������ ���� �ִ� ���� (start ����)
		>> G // ������ (goal�� ����)
		>> U // ���� ������ ������ ���� ���� �ö󰡴��� ��� ����
		>> D; // �Ʒ� ������ ������ ���� ���� ���������� ��� ����
}


//void dfs(int cnt,int cur) {
//	
//	if (cur == G) {
//		ans = cnt;
//		cout << ans;
//		exit(1);
//	}
//
//	for (int i = 0; i < 2; i++) {
//		int next = cur + moving_dir[i];
//		
//		//Ȥ�ö� ������ �Ѱ��� ���! �׳� �Ѿ��!
//		if (next > F || next < 0) continue; 
//		
//		//�ش� ������ �湮������ ���� �� �湮�ؾ��ұ�? ����
//		if (visted_floor[next] == 1) continue;
//
//		visted_floor[next] = 1;
//		dfs(cnt + 1, next);
//		visted_floor[next] = 0;
//	}
//
//}

void bfs(int cur) {
	queue<int> q;
	q.push(cur);
	visted_floor[cur] = true;

	while (!q.empty()) {
		int current_floor = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			int next_floor = current_floor + moving_dir[i];

			if (next_floor<=0 || next_floor> F) continue;

			if (visted_floor[next_floor] == 1) continue;

			visted_floor[next_floor] = true;
			q.push(next_floor);
			distance_[next_floor] = distance_[current_floor] + 1; //�� ������ keypoint �Ÿ����� �����Ǵ� ���� �÷��ִ� ��!

		}

	}
	

}


void game() {
	moving_dir[0] = U;
	moving_dir[1] = -1*D;
	int current_pos = S;

	//dfs(0,current_pos);
	bfs(current_pos);
}


int main() {
	freopen("�ؽ�Ʈ.txt", "r", stdin);

	init();
	game();
	
	if (visted_floor[G]) {
		cout << distance_[G];
	}
	else {
		cout << "use the stairs";
	}
}
