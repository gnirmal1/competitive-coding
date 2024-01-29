#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n);
	vector<int> outdegree(n);
	priority_queue<int> q;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
        a--; b--;
		graph[b].push_back(a);
		outdegree[a]++;
	}
	for (int i = 0; i < n; i++) {
		// locate the nodes with indegree 0 and push them into the queue
		if (outdegree[i] == 0) { q.push(i); }
	}
	vector<int> order(n);
    int l = n - 1;
	while (!q.empty()) {
		int curr = q.top();
		q.pop();
		// add the current node to the order
		order[l--] = curr + 1;
		for (int next : graph[curr]) {
			// remove the current node from the graph
			outdegree[next]--;
			// push any new nodes with indegree 0 into the queue
			if (outdegree[next] == 0) { q.push(next); }
		}
	}
	cout << order[0];
	for (int i = 1; i < n; i++) { cout << " " << order[i]; }
	cout << '\n';
	return 0;
}