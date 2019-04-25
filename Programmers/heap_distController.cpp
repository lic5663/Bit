#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs)
{
	int time = 0;						// 리얼타임
	int result_time[500];				// 각 작업별 대기시간+ 작업시간
	int idx = 0;
	int sum = 0;

	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;

	vector<vector<int>> r_jobs;
	// r_jobs : <작업시간, 진입시간> 형태로 기존 jobs의 순서를 반대로 한 vector

	vector<int> tmp;
	for (size_t i = 0; i < jobs.size(); i++)
	{
		tmp.clear();
		tmp.push_back(jobs[i][1]);
		tmp.push_back(jobs[i][0]);
		r_jobs.push_back(tmp);
	}

	while (idx != r_jobs.size())
	{
		for (int i = 0; i < r_jobs.size(); i++)
		{
			// 진입시간 - 현재시간이 음수일경우 큐에 삽입한다
			if ((r_jobs[i][1] - time) <= 0)
			{
				pq.push(r_jobs[i]);
				r_jobs[i][1] = INT_MAX;
			}
		}

		if (!pq.empty())
		{
			time += pq.top()[0];					// 현재 시간에 작업시간만큼 더한다.
			result_time[idx] = (time - pq.top()[1]);
			idx++;
			pq.pop();
		}
		else
			time++;				// 진입되는 작업이 없을 경우 시간 경과
	}

	for (int i = 0; i < idx; i++)
	{
		sum += result_time[i];
	}

	int answer = sum / jobs.size();
	return answer;
}

int main(void)
{
	vector<vector<int>> v;
	vector<int> temp;
	temp.push_back(0);
	temp.push_back(3);
	v.push_back(temp);

	temp.clear();
	temp.push_back(1);
	temp.push_back(9);
	v.push_back(temp);

	temp.clear();
	temp.push_back(2);
	temp.push_back(6);
	v.push_back(temp);

	cout << solution(v) << endl;


	return 0;
}