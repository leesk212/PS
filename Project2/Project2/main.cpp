#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;

int N, M;

int raw_map[101][101] = { 0, };
int visited_map[101][101] = { 0, };
int distance_map[101][101] = { 0, };

int ds[4] = { -1, 1, 0, 0 }; //상하
int dg[4] = { 0, 0, -1, 1 }; //좌우

#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)

void bfs(int start_s, int start_g) {
	queue<pair<int, int>> q;

	q.push(make_pair(start_s, start_g));
	visited_map[start_s][start_g] = true;
	distance_map[start_s][start_g] = 1;

	while (!q.empty()) {
		int s = q.front().first;
		int g = q.front().second;

		q.pop();

		// BFS 탐색 (map의 상하좌우 탐색 수행)
		for (int i = 0; i < 4; i++) {
			int next_s = s + ds[i];
			int next_g = g + dg[i];

			//이동할 곳이 MAP을 벗어난 경우 "이동 하지마!"
			if (next_s < 0 || next_g < 0 || next_s >= N || next_g >= M) {
				continue;
			}

			//이동할 곳이 갈 수 없는 곳이라면 "이동 하지마!"
			if (raw_map[next_s][next_g] == 0)
				continue;

			//이동할 곳이 갈 수 있고, 아직 방문을 안했다면 "이동해"
			if (raw_map[next_s][next_g] == 1 && visited_map[next_s][next_g] == 0) {
				visited_map[next_s][next_g] = true;
				distance_map[next_s][next_g] = distance_map[s][g] + 1;
				q.push(make_pair(next_s, next_g));
			}
		}
	}
}

int main(void) {
	freopen("텍스트.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++) {
			raw_map[i][j] = temp[j] - '0';
		}
	}

	bfs(0, 0);

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < M; j++) {
	//		cout << raw_map[i][j];
	//	}
	//	cout << endl;
	//}

	//cout << endl;

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << " "<<distance_map[i][j];
		}
		cout << endl;
	}*/

	cout << distance_map[N - 1][M - 1];
	return 0;

}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//#include <sstream>
//#include <cmath>
//#include <queue>
//
//using namespace std;
//
////int x, y;
//int M, N, K;
//int cnt = 0;
//int map[201][201] = { 0, };
//int IsCheck[201][201] = { 0, };
//int dist[201][201] = { 0, };
//int index_X[4] = { -1, 1, 0, 0 };
//int index_Y[4] = { 0, 0, -1, 1 };
//
//#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
//
//int bfs(int x, int y)
//{
//	queue<pair<int, int>> q;
//	q.push(make_pair(x, y));
//	IsCheck[x][y] = 1;
//	dist[x][y] = 1;
//
//	while (!q.empty())
//	{
//		int a = q.front().first;
//		int b = q.front().second;
//		//cnt++;
//		//cout << cnt << ": " << a << " " << b << "\n";
//		q.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = a + index_X[i];
//			int ny = b + index_Y[i];
//
//			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
//				continue;
//
//			if (map[nx][ny] == 0)
//				continue;
//
//			if (map[nx][ny] == 1 && IsCheck[nx][ny] == 0)
//			{
//				dist[nx][ny] = dist[a][b] + 1;
//				q.push(make_pair(nx, ny));
//				IsCheck[nx][ny] = 1;
//			}
//		}
//	}
//
//	return dist[N - 1][M - 1];
//}
//
//int main()
//{
//	freopen("텍스트.txt", "r", stdin);
//	cin >> N >> M;
//
//	for (int i = 0; i < N; i++)
//	{
//		string str;
//		cin >> str;
//		for (int j = 0; j < M; j++)
//		{
//			map[i][j] = str[j] - '0';
//		}
//	}
//
//	cout << bfs(0, 0);
//
//	return 0;
//}