#include <iostream>
using namespace std;

signed main() {
	int N, best = 0, best_x = -1; 
	cin >> N; 
	for (int x = 1; x * x <= N; x++) {
		if (N % x) continue; 
		int y = N / x; 
		int horizontal = max(x * (y - 2), 0); 
		int vertical = max(y * (x - 2), 0);  
		int diagonal = max((y - 2), 0) * max(x - 2, 0) * 2; 
		if (best_x == -1 || best < horizontal + vertical + diagonal) {
			best_x = x; 
			best = horizontal + vertical + diagonal; 
		}
	}
	cout << best_x << ' ' << N / best_x << ' ' << best; 
}

/*
3 -> 1
12 -> 14
8 -> 6
*/
