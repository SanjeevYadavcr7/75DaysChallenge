class Solution{
    public:
        long long required(long long arr[], long long n, long long k) {
            long long petrol = 0;
            priority_queue<int> Q;
            
            for(long long i=0; i<n; i++) Q.push(arr[i]);
            long long max_track = Q.top();
            
            return (max_track <= k) ? -1 : max_track - k;
        }
};
