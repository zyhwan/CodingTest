#include<iostream>
#include<queue>
#include<vector>
#include<string>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int days = 0;
    int counts = 0;
    for (int i = 0; i < progresses.size(); ++i) {
        if ((100 - progresses[i]) % speeds[i] != 0) {
            days = ((100 - progresses[i]) / speeds[i]) + 1;
        }
        else if ((100 - progresses[i]) % speeds[i] == 0) {
            days = (100 - progresses[i]) / speeds[i];
        }
        q.push(days);
    }

    days = q.front();

    while (!q.empty()) {
        if (q.front() > days) {
            answer.push_back(counts);
            days = q.front();
            counts = 0;//초기화
        }
        if (q.front() <= days) {
            ++counts;
        }
        if (q.size() == 1) { //하나 남을 경우
            answer.push_back(counts);
            break;
        }
        q.pop();
    }


    return answer;
}


// 필요한 변수 : 남은 진행도를 담을 변수, 작업이 끝나기까지 남은 일수를 저장할 변수
// 1. 작업이 끝나기까지 남은 일수를 저장할 변수를 큐에 넣고 큐가 empty가 될때까지 반복문을 돌린다.
// 2. 큐에서 pop한 날짜보다 크다면 거기까지의 count를 vector에 저장한다.
// 3. 반복문이 종료되고 결과 vector를 리턴한다.

int main() {
    vector<int> progresses = { 93, 30, 55 };
    vector<int> speeds = { 1, 30, 5 };
    vector<int> a = solution(progresses, speeds);

    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << endl;
    }
}