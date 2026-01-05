#include <iostream>
#include <queue>

using namespace std;

int solution(int N, int K);

int solution(int N, int K)
{
	queue<int> q;
	int answer = 0;

	for (int i = 0; i < N; ++i) {
		q.push(i + 1);
	}

	while (!q.empty()) {
		for (int i = 0; i < K; ++i) {
			if(i != K-1) q.push(q.front());
			answer = q.front();
			q.pop();
		}
	}

	return answer;
}

int main() {
	cout << solution(5, 3);
}
 
// 1. 입력 받은 N의 크기 만큼 큐의 크기를 정의하고 1~N까지의 값을 푸시해준다.
// 2. 반복문을 이용해 큐가 empty()가 될 때까지 기준 k-1번째 원소는 제거하고 나머지는 다시 큐에 푸시해준다.
// 3. 이를 원소가 하나 남을때까지 반복한다.