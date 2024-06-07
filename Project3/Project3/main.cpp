#define _CRT_SECURE_NO_WARNINGS
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int visited_map[16][16] = { 0, };
int ans = 0;

int N;

int ds[8] = { -2,2,-1,1,-2,2,-1,1 };
int dg[8] = { -1,1,-2,2,1,-1,2,-2 };


//int ds[4] = {-1,1,0,0}; //����
//int dg[4] = {0,0,-1,1}; //�¿�
int cnt = 0;


bool check(int start_x, int start_y) {
	vector<pair<int, int>> targets_candi;
	int check_start_x = start_x - 2;
	int check_end_x = start_x + 2;
	int check_start_y = start_y - 2;
	int check_end_y = start_y + 2;
	
	//Target�� �ɸ��� �ĺ����� ã�Ҿ�
	for (int i = check_start_x; i < check_end_x; i++) {
		for (int j = check_start_y; j < check_end_y; j++) {
			if (i || j < 0) {
				continue;
			}
			if (visited_map[i][j] == 1) {
				targets_candi.push_back(make_pair(i, j));
			}
		}
	}

	int need_count = targets_candi.size();
	int right=0;

	// Candi�� �´��� Ȯ��, ����� ��� candi �� �� �¾ƾ� ����
	for (int i = 0; i < targets_candi.size(); i++) {
		int target_x = targets_candi[i].first;
		int target_y = targets_candi[i].second;
		int yes = 0;
		for (int j = 0; j < 8; j++) {
			if (start_x - target_x == ds[i] && start_y - target_y == dg[i]) {
				yes = 1;
			}
		}
		if (yes == 1) {
			right++;
		}
	
	}
	if (need_count == right) {
		return true;
	}
	return false;
}


// Try 1
// �� ������ ���� ������ �ڷ� ��� üũ��, check �� �ʿ��ϴ�. 
// check��� ���� ������ ����ִ� queens�� ���ؼ� �´��� Ȯ��
void dfs(int start_x, int start_y) {

	cnt = cnt + 1;
	visited_map[start_x][start_y] = 1;

	for (int i = 0; i < 8; i++) {
		int next_x = start_x + ds[i];
		int next_y = start_x + dg[i];

		// �湮 ���� ���� Ȯ��
		// �̵��� ��ġ�� MAP �ȿ� �湮 ���� 
		if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= N) {
			continue;
		}
		// �̹� �湮�� ���̶�� �湮 ����
		if (visited_map[next_x][next_y] == 1) {
			continue;
		}
		if (check(next_x, next_y) == 0) {
			continue;
		}

		dfs(next_x, next_y);
	}
}

void print_map() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout<<visited_map[i][j];
		}
		cout << endl;
	}
}

int main() {
	freopen("�ؽ�Ʈ.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fill(visited_map[0], visited_map[0] + N*N+1, 0);
			print_map();
			cnt = 0;
			dfs(i, j);
			//print_map();
			cout << endl;

			if (cnt == N) {
				//print_map();
				ans++;
			}
		}
	}
	cout << ans;

	return 0;
}