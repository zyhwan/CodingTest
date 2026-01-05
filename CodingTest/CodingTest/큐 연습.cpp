#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<int> q; //큐 생성

	//푸시 연산
	q.push(10);
	q.push(20);
	q.push(30);

	//큐의 맨 앞 요소 출력
	cout << "Front: " << q.front() << endl;

	//반복문을 사용하여 큐가 빌 때까지 팝
	while (!q.empty()) {
		cout << q.front() << "을 큐에서 삭제했습니다." << endl;
		q.pop();
	}

	//큐가 비어 있는지 확인
	cout << "큐가 비어있나요? " << (q.empty() ? "Yes" : "No") << endl;

	return 0;
}