#include<bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n) {
	int i,j;
	int cnt, platforms;
	
	sort(arr,arr+n);
	sort(dep,dep+n);
	
	i = 1, j = 0;
	cnt = platforms = 1;
	while(i<n && j<n) {
		if(arr[i] > dep[j]){
			cnt--;
			j++;
		}
		else {
			cnt++;
			i++;
		}
		platforms = max(platforms,cnt);
	}
	return platforms;
}


/* Appraoch: Sorting+Priority Queue | TC: O(NLogN) | SC: O(N)

struct Train {
    	int arr;
    	int dep;
    	Train(int _arr, int _dep){
    		arr = _arr;
    		dep = _dep;
    	}
    };
    
    int findPlatform(int arr[], int dep[], int n) {
    	int platforms;
    	vector<Train*> trains;
    	priority_queue<int,vector<int>,greater<>> Q;
    	
    	for(int i=0; i<n; i++) trains.push_back(new Train(arr[i],dep[i]));
    	sort(trains.begin(), trains.end(), [](Train* a, Train* b){return a->arr < b->arr;});
    	
    	Q.push(trains[0]->dep);
    	platforms = 1;
    	
    	for(int i=0; i<n; i++) cout << trains[i]->arr << " | " << trains[i]->dep << endl;
    	
    	for(int i=1; i<n; i++) { 
    		int dep_time = Q.top();
    		if(dep_time >= trains[i]->arr) platforms++;
    		else Q.pop();
    		Q.push(trains[i]->dep);
    	}
    	return platforms;
    }
*/

int main() {
	int n;
	cin >> n;
	int arr[n], dep[n];
	for(int i=0; i<n; i++) cin >> arr[i];
	for(int i=0; i<n; i++) cin >> dep[i];
	
	int platforms = findPlatform(arr,dep,n);
	cout << platforms << endl;

	return 0;
}
