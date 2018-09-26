#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
int Nums[6];

bool solve(int arr[], int pos, int used) {
	
	if (pos == 6) {
		int tri = 0, run = 0;
		for (int i = 0; i < 2; ++i) {
			if (arr[i * 3 + 1] == arr[i * 3] + 1 && arr[i * 3 + 2] == arr[i * 3 + 1] + 1)
				++run;
			else if (arr[i * 3 + 1] == arr[i * 3] && arr[i * 3 + 2] == arr[i * 3 + 1])
				++tri;
		}
		if (run + tri == 2)
			return 1;
		return 0;
	}

	for (int i = 0; i < 6; ++i)
	{
		if (used & (1 << i)) continue;
		
		arr[pos] = Nums[i];
		if (solve(arr, pos + 1, used | (1 << i)))
			return 1;
	}
	return 0;

}
int main()
{
	
	std::ios::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	

	for (int t = 1; t <= 3; t++) {

		for (int i = 0; i < 6; i++) {
			cin >> Nums[i];
		}
		
		int arr[6];
		int ans = solve(arr, 0, 0);
		cout << "#" << t << " " << ans << endl;
	}

	
}