#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

int N, M;
vector<int> code;

void init() {
	cin >> N >> M;
	int lets = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			int int_c = c - '0'; //char를 int로 변환 Simple
			
			if (int_c == 1) {
				lets = j;
			}

			if (lets != 0 && j<=lets+56) {
				code.push_back(int_c);
			}

		}
	}

}


int main(void) {
	freopen("텍스트.txt", "r", stdin);

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++) {

		init();



	}


	return 0;

}