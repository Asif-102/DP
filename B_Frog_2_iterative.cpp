// problem link -> https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 2e9;
/*
- state: stone(n) -> cost of reaching n-th stone from 1st stone
- recurrance: stone(n) = for i = 1 to k:
                            min(
                                stone(n-i) + abs( h[n] - h[n-i])
                            )
- base case: stone(1) = 0
*/

int h[N], dp[N];
int n, k;

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    for(int i = 1; i <= n; i++){
        dp[i] = -1;
    }
    
    // 1. base case
    dp[1] = 0;

    // 2. loop over the states
    for(int i = 2; i <= n; i++){
        dp[i] = INF;
        // 2.1. calculate answer from smaller sub-problems
        for(int j = 1; j <= k; j++){
            // handle corner case
            if(i - j <= 0){
                break;
            }
            int candidate_ans = dp[i - j] + abs(h[i] - h[i-j]);
            dp[i] = min(dp[i], candidate_ans);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}