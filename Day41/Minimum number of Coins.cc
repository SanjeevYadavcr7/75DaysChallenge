#include<bits/stdc++.h>
using namespace std;
    
vector<int> coins = {1,2,5,10,20,50,100,200,500,2000};

vector<int> minPartition(int amount) {
	int n = coins.size();
	vector<int> min_coins;

	for(int i=n-1; i>=0; i--) {
		while(amount >= coins[i]) {
			amount -= coins[i];
			min_coins.push_back(coins[i]);
		}
	}
	
	return min_coins;
}


int main() {
	int tar;	
	cin >> tar;
	vector<int> coins = minPartition(tar);
	for(int coin : coins) cout << coin << " ";
	cout << endl;
	
	return 0;
}
