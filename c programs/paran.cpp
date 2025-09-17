#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Recursive bucket sort function
// void bucketSortRecursive(vector<int>& arr, int left, int right) {
//     if (right <= left) return; // base case: if there's only one element or no elements

//     // Find the range (min and max)
//     int minValue = arr[left];
//     int maxValue = arr[left];
//     for (int i = left + 1; i <= right; ++i) {
//         minValue = min(minValue, arr[i]);
//         maxValue = max(maxValue, arr[i]);
//     }

//     // Number of buckets
//     int bucketCount = right - left + 1;
//     vector<vector<int>> buckets(bucketCount);

//     // Calculate the range for each bucket
//     float range = float(maxValue - minValue) / bucketCount;

//     // Distribute elements into buckets
//     for (int i = left; i <= right; ++i) {
//         int bucketIndex = (arr[i] - minValue) / range;
//         if (bucketIndex == bucketCount) bucketIndex--; // To avoid overflow
//         buckets[bucketIndex].push_back(arr[i]);
//     }

//     // Recursively sort each bucket and merge
//     for (int i = 0; i < bucketCount; ++i) {
//         if (!buckets[i].empty()) {
//             bucketSortRecursive(buckets[i], 0, buckets[i].size() - 1); // Recursively sort each bucket
//             // After sorting a bucket, place the elements back into the array
//             for (int j = 0; j < buckets[i].size(); ++j) {
//                 arr[left++] = buckets[i][j];
//             }
//         }
//     }
// }

// int main() {
//     vector<int> arr = {3, 5, 1, 9, 8, 6, 2, 7, 4};
//     int n = arr.size();

//     cout << "Original array: ";
//     for (int num : arr) cout << num << " ";
//     cout << endl;

//     // Perform recursive bucket sort
//     bucketSortRecursive(arr, 0, n - 1);

//     cout << "Sorted array: ";
//     for (int num : arr) cout << num << " ";
//     cout << endl;

//     return 0;
// }


// //////////BUCKET FOR STRINGS /////////
// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// using namespace std;

// // Function to sort strings using bucket sort
// void bucketSort(vector<string>& arr) {
//     // If the array is empty or contains only one string, return as it is already sorted
//     if (arr.size() <= 1) return;

//     // Find the maximum length of the strings to determine the number of "characters" to consider
//     int maxLength = 0;
//     for (const string& str : arr) {
//         maxLength = max(maxLength, (int)str.size());
//     }

//     // Bucket sort for each character from the end to the start (like a radix sort)
//     for (int digitPos = maxLength - 1; digitPos >= 0; --digitPos) {
//         vector<vector<string>> buckets(26); // 26 buckets for 26 lowercase characters

//         // Place each string into the correct bucket based on the current character
//         for (const string& str : arr) {
//             int bucketIndex = (digitPos < str.size()) ? (str[digitPos] - 'a') : 0; // Default to 0 for shorter strings
//             buckets[bucketIndex].push_back(str);
//         }

//         // Collect all the strings back into the array after sorting by the current character
//         arr.clear();
//         for (const auto& bucket : buckets) {
//             for (const string& str : bucket) {
//                 arr.push_back(str);
//             }
//         }
//     }
// }

// int main() {
//     // Example input: list of strings
//     vector<string> arr = {"apple", "banana", "grape", "kiwi", "cherry", "blueberry"};

//     // Print original array
//     cout << "Original array:" << endl;
//     for (const string& str : arr) {
//         cout << str << " ";
//     }
//     cout << endl;

//     // Sort the array using bucket sort
//     bucketSort(arr);

//     // Print the sorted array
//     cout << "Sorted array:" << endl;
//     for (const string& str : arr) {
//         cout << str << " ";
//     }
//     cout << endl;

//     return 0;
// }



// // Radix-sort///////////////////////
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cmath>
// using namespace std;

// // Function to perform counting sort based on the current digit place
// void countingSort(vector<int>& arr, int exp) {
//     vector<int> output(arr.size());
//     int count[10] = {0};

//     // Store count of occurrences in count[]
//     for (int i = 0; i < arr.size(); i++) {
//         count[(arr[i] / exp) % 10]++;
//     }

//     // Change count[i] so that count[i] now contains the actual position of this digit in output[]
//     for (int i = 1; i < 10; i++) {
//         count[i] += count[i - 1];
//     }

//     // Build the output array
//     for (int i = arr.size() - 1; i >= 0; i--) {
//         output[count[(arr[i] / exp) % 10] - 1] = arr[i];
//         count[(arr[i] / exp) % 10]--;
//     }

//     // Copy the sorted numbers into the original array
//     for (int i = 0; i < arr.size(); i++) {
//         arr[i] = output[i];
//     }
// }

// // Function to perform radix sort
// void radixSort(vector<int>& arr) {
//     // Find the maximum number to know the number of digits
//     int maxVal = *max_element(arr.begin(), arr.end());

//     // Apply counting sort for every digit
//     for (int exp = 1; maxVal / exp > 0; exp *= 10) {
//         countingSort(arr, exp);
//     }
// }

// int main() {
//     vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

//     cout << "Original array: ";
//     for (int num : arr) {
//         cout << num << " ";
//     }
//     cout << endl;

//     // Apply radix sort
//     radixSort(arr);

//     cout << "Sorted array: ";
//     for (int num : arr) {
//         cout << num << " ";
//     }
//     cout << endl;

//     return 0;
// }

// ///////////RADIX STRING//////////////
// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// using namespace std;

// // Function to perform counting sort on strings based on the current character place
// void countingSortStrings(vector<string>& arr, int charPos) {
//     vector<string> output(arr.size());
//     int count[256] = {0};

//     // Store count of occurrences of each character at the current position
//     for (int i = 0; i < arr.size(); i++) {
//         int charVal = charPos < arr[i].size() ? arr[i][charPos] : 0;  // Handle shorter strings
//         count[charVal]++;
//     }

//     // Change count[] so that it now contains actual positions of characters in output[]
//     for (int i = 1; i < 256; i++) {
//         count[i] += count[i - 1];
//     }

//     // Build the output array
//     for (int i = arr.size() - 1; i >= 0; i--) {
//         int charVal = charPos < arr[i].size() ? arr[i][charPos] : 0;
//         output[count[charVal] - 1] = arr[i];
//         count[charVal]--;
//     }

//     // Copy the output array to the original array
//     for (int i = 0; i < arr.size(); i++) {
//         arr[i] = output[i];
//     }
// }

// // Function to perform radix sort on strings
// void radixSortStrings(vector<string>& arr) {
//     // Find the longest string to determine the number of characters to process
//     int maxLen = 0;
//     for (const string& str : arr) {
//         maxLen = max(maxLen, (int)str.size());
//     }

//     // Apply counting sort for each character position, starting from the last character
//     for (int charPos = maxLen - 1; charPos >= 0; charPos--) {
//         countingSortStrings(arr, charPos);
//     }
// }

// int main() {
//     vector<string> arr = {"apple", "banana", "grape", "kiwi", "cherry", "blueberry"};

//     cout << "Original array: ";
//     for (const string& str : arr) {
//         cout << str << " ";
//     }
//     cout << endl;

//     // Apply radix sort on strings
//     radixSortStrings(arr);

//     cout << "Sorted array: ";
//     for (const string& str : arr) {
//         cout << str << " ";
//     }
//     cout << endl;

//     return 0;
// }




///////////////BUCKET-FOR-INTEGER///////////

void bucket_sort(vector<int>& arr , int begin , int end){
    if(begin>=end){return;}
    int min_,max_;
    min_ = arr[begin],max_=arr[begin];
    for(int i=begin ;i<=end;i++){
        min_ = min(min_ , arr[i]);
        max_ = max(max_ , arr[i]);
    }
    int bucket_count = 4;
    float bucket_range = (float)(max_-min_+1)/(4);
    vector<vector<int>> bucket(bucket_count);
    for(int i=begin;i<=end;i++){
        int index = (arr[i]-min_)/bucket_range;
        if(index==bucket_count){index--;}
        bucket[index].push_back(arr[i]);
    }
    for(int i=0;i<bucket_count;i++){
        if(!bucket[i].empty()){bucket_sort(bucket[i] , 0 , bucket[i].size()-1);}
        for(int j=0;j<bucket[i].size();j++){
            arr[begin++]= bucket[i][j];
        }
    }

}

// int main() {
//     vector<int> arr = {3, 5, 1, 9, 8, 6, 2, 7, 4};
//     int n = arr.size();

//     cout << "Original array: ";
//     for (int num : arr) cout << num << " ";
//     cout << endl;

//     // Perform recursive bucket sort
//     bucket_sort(arr, 0, n - 1);

//     cout << "Sorted array: ";
//     for (int num : arr) cout << num << " ";
//     cout << endl;

//     return 0;
// }



void bucket_string(vector<string>& v){
    size_t max_len=0;
    for(int i=0;i<v.size();i++){
        max_len = max( max_len , v[i].length());
    }
    for(int pos = max_len-1 ;pos>=0;pos--){
        vector<vector<string>> bucket(27);
        for(int i=0;i<v.size();i++){
            int index = ((pos<v[i].size())? v[i][pos]-'a'+1 : 0);
            bucket[index].push_back(v[i]);
        }
        int k=0;
        for(int i=0;i<27;i++){
            for(int j=0;j<bucket[i].size();j++){
                v[k++]=bucket[i][j];
            }
        }
    }
}


void counting_sort(vector<int>& arr , int pos){
    int count[10]={0};
    for(int i=0;i<arr.size();i++){
        int index = (arr[i]/pos)%10 ;
        count[index]++;
    }
    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    vector<int> result(arr.size());
    for(int i=arr.size()-1;i>=0;i--){
        result[count[(arr[i]/pos)%10]-1]= arr[i];
        count[(arr[i]/pos)%10]--;
    }
    for(int i=0;i<arr.size();i++){
        arr[i]= result[i];
    }
}

void radix_sort(vector<int>& arr){
    int max_element=0;
    for(int i=0;i<arr.size();i++){
        max_element = max(max_element, arr[i]);
        
    }
    for(int pos=1;max_element/pos>0;pos*=10){
        counting_sort(arr, pos);
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Apply radix sort
    radix_sort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}