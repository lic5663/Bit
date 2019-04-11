#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs)
{
	int time = 0;						// ����Ÿ��
	int result_time[500];				// �� �۾��� ���ð�+ �۾��ð�
	int idx = 0;
	int sum = 0;

	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;

	vector<vector<int>> r_jobs;
	// r_jobs : <�۾��ð�, ���Խð�> ���·� ���� jobs�� ������ �ݴ�� �� vector

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
			// ���Խð� - ����ð��� �����ϰ�� ť�� �����Ѵ�
			if ((r_jobs[i][1] - time) <= 0)
			{
				pq.push(r_jobs[i]);
				r_jobs[i][1] = INT_MAX;
			}
		}

		if (!pq.empty())
		{
			time += pq.top()[0];					// ���� �ð��� �۾��ð���ŭ ���Ѵ�.
			result_time[idx] = (time - pq.top()[1]);
			idx++;
			pq.pop();
		}
		else
			time++;				// ���ԵǴ� �۾��� ���� ��� �ð� ���
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