#include <string>
#include <vector>
#include <unordered_map>
#include< iostream>
#include<algorithm>
using namespace std;

typedef struct my {
	int plays_sum;
	vector<pair<int, int>> list;
}my;

bool sortbysec(const pair<int, int> &a,
	const pair<int, int> &b)
{
	return (a.second > b.second);
}
bool sortinrev(const pair<int, string> &a,
	const pair<int, string> &b)
{
	return (a.first > b.first);
}


vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	vector<pair<int,string>> plays_sum_vec;
	unordered_map<string, my> music_map;
	int index = 0;
	for (auto a : genres)
	{
		music_map[a].list.push_back(make_pair(index, plays[index]));
		index++;
	}
	for (auto a : genres)
	{
		sort(music_map[a].list.begin(), music_map[a].list.end(), sortbysec);

	}
	for (auto a : music_map)
	{
		for (auto inner_a : a.second.list)
		{
			a.second.plays_sum += inner_a.second;
		}

		plays_sum_vec.emplace_back(make_pair( a.second.plays_sum,a.first));
	
	}
	sort(plays_sum_vec.begin(), plays_sum_vec.end(), sortinrev);
	for (auto a : plays_sum_vec)
	{
		int j;
		for (j = 0; j < 2; j++)
		{
			answer.emplace_back( music_map.find(a.second)->second.list[j].first );
		}
	}
	return answer;

}

int main()
{
	vector<string> genres = { "classic","pop","classic","classic","pop" };
	vector<int> plays = { 500,600,150,800,2500 };
	vector <int > answer = solution(genres, plays);
	for (auto a : answer)
	{
		cout << a << endl;
	}

}
