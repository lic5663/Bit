#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
	priority_queue< int, vector<int>, greater<int> > pq; // ���ϴ� �ڷ��� �� Ŭ���� T�� ���� ����. ���⼭ Container�� vector�� ���� �����̳��̸� Compare�� ���Լ� Ŭ�����̴�.

	int smallest, n_smallest;
	int mix;
	int answer = 0;

	// ���ں��� ��� ���� �켱���� queue�� push
	for (int i = 0; i < scoville.size(); i++)
	{
		pq.push(scoville[i]);
	}

	// top�� �����ϴ� ���� �ּ� ��ġ K���� ������ �Ǻ��� ������Ű�� �� ���� ���� �����Ѵ�.
	while (pq.top() < K)
	{
		if (pq.size() < 2)
			return -1;

		smallest = pq.top();
		pq.pop();
		n_smallest = pq.top();
		pq.pop();

		mix = smallest + (n_smallest * 2);
		pq.push(mix);

		answer++;
	}

	
	return answer;
}
