#include<queue>
#include<iostream>
using namespace std;

int lastStoneWeight(vector<int>& stones) {
	int n = stones.size();
	priority_queue<int> bag;
	
	for(int i : stones) bag.push(i);
	while(bag.size() >  1) {
		int stone1 = bag.top(); bag.pop();
		int stone2 = bag.top(); bag.pop();
		bag.push(stone1-stone2);
	}
	return bag.top();
}

int main() {
	int n;
	cin >> n;
	vector<int> stones(n);
	for(int i=0; i<n; i++) cin >> stones[i];
	
	int last_stone = lastStoneWeight(stones);
	cout << last_stone << endl;

	return 0;
}
