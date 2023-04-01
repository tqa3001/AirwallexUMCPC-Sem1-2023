#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 3005; 
int N, ans; 
int A[MAX_N][MAX_N]; 
int dx[] = {1, 0, -1, 0}; 
int dy[] = {0, -1, 0, 1}; 

signed main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	cin >> N; 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j]; 
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int dir_1 = 0; dir_1 < 4; dir_1++) {
				for (int dir_2 = dir_1 + 1; dir_2 < 4; dir_2++) {
					int i_1 = i + dx[dir_1], j_1 = j + dy[dir_1]; 
					int i_2 = i + dx[dir_2], j_2 = j + dy[dir_2]; 
					if (min({i_1, i_2, j_1, j_2}) < 1 || max({i_1, i_2, j_1, j_2}) > N) 
						continue;
					if (A[i][j] > A[i_1][j_1] + A[i_2][j_2]) 
						ans++; 
				}
			}
		}
	}
	cout << ans; 
}
