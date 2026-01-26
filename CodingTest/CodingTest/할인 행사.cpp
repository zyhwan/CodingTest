#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    unordered_map<string, int> wantmp;

    for (int i = 0; i < want.size(); ++i) {
        wantmp[want[i]] = number[i];
    }

    for (int i = 0; i < discount.size() - 9; ++i) {
        unordered_map<string, int> discount_10d;

        for (int j = i; j < 10 + i; ++j) {
            discount_10d[discount[j]]++;
        }

        if (wantmp == discount_10d) ++answer;
    }


    return answer;
}

// 확인해야 하는것. 
// want의 원소들이 discount에 다 있는지.
// want의 필요한 원소들의 개수가 discount에 충분히 있는지.
// 이것들이 연속적으로 discount에 존재하는지.

// 반복문을 두개 돌려서 각각의 원소가 몇개 있는지 만족하는지 확인할려면 너무 시간복잡도가 올라감..
// 흠..

