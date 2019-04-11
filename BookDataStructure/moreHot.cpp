#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
	priority_queue< int, vector<int>, greater<int> > pq; // 원하는 자료형 및 클래스 T를 통해 생성. 여기서 Container는 vector와 같은 컨테이너이며 Compare는 비교함수 클래스이다.

	int smallest, n_smallest;
	int mix;
	int answer = 0;

	// 스코빌의 모든 값을 우선순위 queue에 push
	for (int i = 0; i < scoville.size(); i++)
	{
		pq.push(scoville[i]);
	}

	// top에 존재하는 값이 최소 수치 K보다 작은지 판별해 증가시키고 그 값을 힙에 삽입한다.
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
