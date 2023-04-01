#include <iostream>
signed main() {
  int cnt_o = 0, cnt_re = 0; 
  char c; 
  while ((c = getchar()) != EOF && (c == 'o' ? ++cnt_o : ++cnt_re)); 
  printf("%d", std::max(cnt_re / 2, (cnt_o + 1) / 2)); 
}