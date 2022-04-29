// Taken from GFG practise section

#include<iostream>
using namespace std;

// TC: O(NlogN) | SC: O(N)
long long required(long long arr[], long long n, long long k) {
            long long petrol = 0;
            priority_queue<int> Q;
            
            for(long long i=0; i<n; i++) Q.push(arr[i]);
            long long max_track = Q.top();
            
            return (max_track <= k) ? -1 : max_track - k;
}

/* TC: O(N) | SC: O(1)
long long required(long long arr[], long long n, long long k) {
            long long petrol = 0;
            for(long long i=0; i<n; i++){
                if(arr[i] > k){
                    petrol += (arr[i]-k);
                    k = arr[i];
                }
            }
            return (petrol == 0) ? -1 : petrol;
}
*/

int main() {
	long long n,k;
	cin >> n >> k;
	vector<long long> arr(n);
	
	long long petrol = required(arr,n,k);	
	
	return 0;
}
