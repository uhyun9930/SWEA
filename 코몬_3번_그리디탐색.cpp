#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<int> solution(vector<int> healths, vector<vector<int>> items) {
	vector<int> answer; 
	vector<bool> isUsed(items.size(), false);
	
	sort(healths.begin(), healths.end());
	//작은 순으로 정렬 
	

	for (int i = 0; i < healths.size(); i++) {
		int no = -1; // 아이템 번호 
		int power = 0; // 공격력 

		for (int j = 0; j < items.size(); j++) {
			if (!isUsed[j] && 100 <= healths[i] - items[j][1]) {
				
				if (power < items[j][0]) {
					no = j;
					power = items[j][0];
				}
			}
		}
		
		if (no != -1) {
			isUsed[no] = true;
			answer.push_back(no + 1);
		}
	
	}
	

	sort(answer.begin(), answer.end());
	return answer;

}

int main() 
{
	vector<int> healths = { 300,200,500 };
	vector<vector <int>> items = { {1000,600},{400,500}, {300,100} };

	vector<int> answer;
	answer = solution(healths, items);


	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
}