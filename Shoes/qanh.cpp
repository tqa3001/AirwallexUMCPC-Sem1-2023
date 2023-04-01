#include <iostream>
#include <queue> 
#define MAX_N 100005
using namespace std;
 
int N; 
string s;
 
signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  cin >> N >> s;
  int64_t ans = LLONG_MAX; 
  for (int reversed = 0; reversed < 2; reversed++) {
    char type_of_unmatched; 
    queue<int> unmatched; 
    int64_t res = 0; 
    int offset = 0;
    for (int i = 1; i <= N * 2; i++) {
      char c = s[reversed ? 2 * N - i : i - 1];
      if (unmatched.empty()) {
        type_of_unmatched = c; 
        unmatched.push(i - offset); 
      } else if (c != type_of_unmatched) {
        int v = unmatched.front(); 
        unmatched.pop(); 
        res += i - (v + offset) - (c == 'G'); 
        offset++; 
      } else {
        unmatched.push(i - offset); 
      }
    }
    ans = min(ans, res); 
  }
  cout << ans; 
}