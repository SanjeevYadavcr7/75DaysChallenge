#include<bits/stdc++.h>
using namespace std;

struct Item {
	int value;
	int weight;
	Item(int _value, int _weight) {
		value = _value;
		weight = _weight;
	}
};

bool sortByRatio(Item a, Item b) {
	double r1 = (double) a.value / (double) a.weight;
	double r2 = (double) b.value / (double) b.weight;
	return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n) {
	double max_value = 0;
	
	sort(arr, arr+n, sortByRatio);
	for(int i=0; i<n; i++) {
		int curr_weight = arr[i].weight;
		int curr_value = arr[i].value;
		
		if(curr_weight <= W) {
			max_value += curr_value;
			W -= curr_weight;
		}
		else {
			double last_value = ((double)W/(double)curr_weight) * curr_value; 
			max_value += last_value;
			break;
		}
	}
	return max_weight;
}

int main() {
	int n,w;
	cin >> n >> w;
	Item arr[n];
	for(int i=0; i<n; i++) {
		int val, weight;
		cin >> val >> weight;
		arr[i] = new Item(val,weight);
	}
	
	double max_weight = fractionalKnapsack(w,arr,n);
	cout << max_weight << endl;

	return 0;
}
