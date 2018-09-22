
#define _CRT_SECURE_NO_WARNINGS


#include <string>
#include <vector>
#include <iostream>

using namespace std;
int cnt = 0;

void search(int N, int s, int d, vector<vector<int>> arr, int depth)
{
	if (s == d) {
		cnt = depth;
		return;
	}
	for (int i = 0; i<N; i++) {
		if (arr[s][i] == 1 && arr[i][s] == 1) {
			arr[s][i] = 2;
			search(N, i, d, arr, depth + 1);
		}
	}

}
vector<int> solution(int N, vector<vector<int>> directory, vector<vector<int>> query) {

	vector<int> answer;
	vector <vector<int>> arr;

	for (int i = 0; i<N; i++) {
		vector<int> a(N);
		arr.push_back(a);
	}

	for (int i = 0; i<directory.size(); i++) {
		int a = directory[i][0] - 1;
		int b = directory[i][1] - 1;
		arr[a][b] = 1;
		arr[b][a] = 1;

	}

	for (int i = 0; i<query.size(); i++) {
		int s = query[i][0] - 1;
		int d = query[i][1] - 1;
		cnt = 0;
		search(N, s, d, arr, 0);
		answer.push_back(cnt + 1);
	}


	return answer;
}