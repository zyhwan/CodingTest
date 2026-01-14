#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;

long long poltnomial_hash(const string& str) {
	const int p = 31; //소수
	const long long m = 1000000007; //버킷 크기

	long long hash_value = 0;

	for (char c : str) {
		hash_value = (hash_value * p + c) % m;
	}

	return hash_value;
}

vector<bool> solution(vector<string> string_List, vector<string> query_List) {
	unordered_set<long long> hash_set;

	for (const string& str : string_List) {
		long long hash = poltnomial_hash(str);
		hash_set.insert(hash);
	}

	vector<bool> result;

	for (const string& query : query_List) {
		long long query_hash = poltnomial_hash(query);
		bool found = (hash_set.find(query_hash) != hash_set.end());
		result.push_back(found);
	}

	return result;

}