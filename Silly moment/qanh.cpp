#include <iostream>
#define MAX_N 50000
#define MAX_S 105 
using namespace std;

int N, S; 
int pizza[MAX_N][2]; 
int64_t dp[MAX_N][MAX_S][2]; 

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  cin >> N >> S; 
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < N; i++) {
      cin >> pizza[i][j]; 
    }
  }
  for (int wam = 0; wam <= S; wam++) {
    dp[0][wam][0] = pizza[0][0]; 
    dp[0][wam][1] = pizza[0][1]; 
  }
  dp[0][0][1] = INT64_MAX / 2; 
  for (int rail = 1; rail < N; rail++) {
    for (int track = 0; track < 2; track++) {
      dp[rail][0][track] = dp[rail - 1][0][track] + pizza[rail][track]; 
    }
    for (int wam = 1; wam <= S; wam++) {
      for (int track = 0; track < 2; track++) {
        dp[rail][wam][track] = 
          min(dp[rail - 1][wam][track], 
              dp[rail - 1][wam - 1][track ^ 1]) 
              + pizza[rail][track]; 
      }
    }
  }
  cout << min(dp[N - 1][S][0], dp[N - 1][S][1]); 
}