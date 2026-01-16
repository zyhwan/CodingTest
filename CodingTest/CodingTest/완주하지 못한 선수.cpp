#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> hs;

    for (int i = 0; i < participant.size(); ++i) {
        hs[participant[i]]++;
    }

    for (int i = 0; i < completion.size(); ++i) {
        hs[completion[i]]--;
        if (hs[completion[i]] == 0) {
            hs.erase(hs.find(completion[i]));
        }
    }
    return hs.begin()->first;
}