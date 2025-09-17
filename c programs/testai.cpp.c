#include <bits/stdc++.h>
using namespace std;

int main() {
    int cases;
    cin >> cases;  // Use cin for cleaner input
    while (cases--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> answer(n);
        
        // Track the smallest missing non-negative integer
        int min_missing = 0;
        vector<int> present(n + 1, 0);  // Array to mark numbers from 0 to n
        
        // Read the input and process
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            if (arr[i] < 0) {
                answer[i] = min_missing - arr[i];  // If negative, adjust answer
            } else {
                answer[i] = min_missing;  // For non-negative values
                present[arr[i]] = 1;  // Mark this number as present
            }
        }
// Finding the smallest missing positive integer
        for (int i = 0; i <= n; ++i) {
            if (!present[i]) {
                min_missing = i;
                break;
            }
        }

        // Print the answers
        for (int i = 0; i < n; ++i) {
            cout << answer[i] << " ";
        }
        cout << "\n";
    }
return 0;
}