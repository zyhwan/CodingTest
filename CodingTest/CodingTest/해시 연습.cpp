#include<iostream>
#include<vector>

using namespace std;

void mapping(vector<int>& hash, const vector<int>& arr, int target);
bool solution(vector<int> arr, int target);

int main() {


	return 0;
}

void mapping(vector<int>& hash, const vector<int>& arr, int target)
{
	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i] > target) {
			continue; // target보다 큰 값은 담지 않음(답이 될 가능성 없음)
		}
		hash[arr[i]] = 1; //현재 원소 값을 hash 인덱스로 활용, 해당 위치의 값을 1로 설정.
	}
}

bool solution(vector<int> arr, int target)
{
	vector<int> hash(target + 1, 0); //target+1개의 공간이 있는 hash 벡터 선언
	mapping(hash, arr, target);

	for (int i = 0; i < arr.size(); ++i) {
		int num = target - arr[i]; //target에서 arr[i]를 뺀 값이 있는지 확인하기 위해 num 선언
		if (num == arr[i]) { //제약 조건에 중복 숫자는 없음
			continue;
		}
		if (num < 0) { //음수는 없음.
			continue;
		}
		if (hash[num]) { //num이 있다면 합이 target이 되는 변수를 찾았으므로 true 반환
			return true;
		}
	}

	return false;
}

// 1. arr에서 임의의 원소 x에 대해 x + k = target이 되는 원소 k가 arr에 있는지 확인하기
// 