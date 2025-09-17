#ALGORITHYMS 

1) Kadane's algorithym -- to find the maximum sum of any subarray :-

    int kadane(vector<int>& arr) {
    int max_so_far = INT_MIN;
    int max_ending_here = 0;

    for (int x : arr) {
        max_ending_here = max(x, max_ending_here + x);
        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

2)
