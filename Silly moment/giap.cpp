#include <iostream>
#include <vector>
#include <algorithm> 
#include <map>
#include <vector> 
#include <climits> 
using namespace std;

int main() {
    int n, s; 
    cin >> n >> s; 
    vector<int> A[2]; 
    A[0] = A[1] = vector<int> (n + 1, 0); 
    for(int i = 0; i < 1; i++) { 
        for(int j = 1; j <= n; j++) { 
            cin >> A[i][j]; 
        }
    }
    vector<long long> dp[105]; 
    for(int i = 0; i <= s; i++) { 
        dp[i] = vector<long long> (n + 1, LLONG_MAX / 2); 
    }
    for(int j = 0; j <= n; j++) { 
        if(!j) { 
            dp[0][j] = 0; 
            for(int i = 1; i <= s; i++) { 
                dp[i][j] = LLONG_MAX / 2; 
            }
        }
        else { 
            dp[0][j] = dp[0][j - 1] + A[0][j]; 
            for(int i = 1; i <= s; i++) { 
                dp[i][j] = min(dp[i][j - 1] + A[i & 1][j], dp[i - 1][j - 1] + A[i - 1 & 1][j]);
            }
        }
    }
    long long ans = LLONG_MAX / 2; 
    for(int i = 0; i <= s; i++) ans = min(ans, dp[i][n]);
    cout << ans;
}