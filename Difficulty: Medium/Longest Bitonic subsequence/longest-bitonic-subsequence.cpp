//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // Longest Increasing Subsequence
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        
        // Longest Decreasing Subsequence
        vector<int> dp2(n, 1);
        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j > i; j--) {
                if(nums[i] > nums[j] && dp2[j] + 1 > dp2[i]) {
                    dp2[i] = dp2[j] + 1;
                }
            }
        }
        
        // Combine to get Longest Bitonic Sequence
        /* Return the maximum value of lis[i] + lds[i] - 1*/
        int ans = 0; // initializing ans with length of longest bitonic sequence
        for (int i = 1; i < n - 1; i++)
            if (dp[i] > 1 && dp2[i] > 1) {
                ans = max(ans,
                          dp[i] + dp2[i] - 1); // updating ans if current index has
                                                // non-zero values for both LIS and LDS
            }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
    }
}

// } Driver Code Ends