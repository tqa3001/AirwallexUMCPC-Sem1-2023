#include <iostream>
#include <set>
using namespace std;
typedef multiset<int>::iterator Iter; 

multiset<int> collection; 

void printMaxDiff() {
  if (collection.empty()) {
    cout << -1 << '\n'; 
  } else {
    Iter iterator_min = collection.begin(); 
    Iter iterator_max = prev(collection.end()); 
    cout << (*iterator_max) - (*iterator_min) << '\n'; 
  }
}

signed main() {
  ios_base::sync_with_stdio(0); 
  cin.tie(0);
  int N, Q;  
  cin >> N >> Q; 
  for (int i = 1, val; i <= N; i++) {
    cin >> val; 
    collection.insert(val); 
  }
  printMaxDiff(); 
  for (int i = 1; i <= Q; i++) {
    int type, amount; 
    cin >> type >> amount;  
    if (!type) {
      Iter it = collection.find(amount); 
      collection.erase(it); 
    } else {
      collection.insert(amount); 
    }
    printMaxDiff(); 
  }
  return 0; 
}