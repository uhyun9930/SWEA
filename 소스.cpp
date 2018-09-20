#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <algorithm>

#include <memory.h>

using namespace std;



int result, r;

int arr[100][102], a, b;

bool visited[100][102];



void cal(int ii, int jj, int cnt)

{

	if (ii == 0)

	{

		if (result >= cnt) { result = cnt; r = jj - 1; }

		return;

	}

	visited[ii][jj] = true; cnt++;

	if (arr[ii][jj + 1] && !visited[ii][jj + 1]) cal(ii, jj + 1, cnt);
	else if (arr[ii][jj - 1] && !visited[ii][jj - 1]) cal(ii, jj - 1, cnt);
	else if (arr[ii - 1][jj] && !visited[ii - 1][jj]) cal(ii - 1, jj, cnt);



}



int main()

{
	std::ios::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);

	int T; int t;

	T = 10;

	while (T--)

	{

		cin >> t; 
		result = 9999999;
		
		memset(arr, 0, sizeof(arr));

		for (int i = 0; i < 100; i++)
			for (int j = 1; j <= 100; j++)

			{

				cin >> arr[i][j];

				if (i == 99)

				{

					memset(visited, false, sizeof(visited));

					cal(i, j, 0);

				}

			}



		cout << "#" << t << " " << r << endl;
	}



	return 0;

}