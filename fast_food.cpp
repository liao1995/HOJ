#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using std::cin;
using std::cout;

const int MAXN = 200+5;
const int MAXK = 30+5;
const int INF = 1000000000;

// min sum distance when deploy j depot in 0 - i
int dp[MAXN][MAXK];
// min sum distance when deploy 1 depot in i - j
int rest[MAXN][MAXN];
int dist[MAXN];
int N, K;

inline int min_(int a, int b) { return a < b ? a : b;}

// min sum distance when from i to j choose 1 depot (median)
int get_range(int i, int j) {
	if (i == j - 1) return 0;
	if (i + 2 == j) return dist[j - 1] - dist[i];
	int sum  = 0, mid = (i+j)>>1;
	for (int k = i; k < j; ++k) sum += abs(dist[mid] - dist[k]);
	return sum;
}

int get_rest(int i, int j){
	if (!rest[i][j]) rest[i][j] = get_range(i, j+1);
	return rest[i][j];
}


int main()
{
	int t = 0; 
//	freopen("data.in", "r", stdin);
	 while (cin >> N >> K) {
	 	if (!N && !K) break;
	 	for (int i = 1; i <= N; ++i) scanf("%d", dist + i);
		memset(rest, 0, sizeof(rest));
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= N; ++i) dp[i][1] = get_range(1, i+1);
		for (int k = 2; k <= K; ++k) {
			for (int n = k+1; n <= N; ++n) {
				dp[n][k] = INF;
				for (int d = 1; d <= n; ++d) 
					dp[n][k] = min_(dp[n][k], dp[d][k-1] + get_rest(d+1, n));
			}
		}
		printf("Chain %d\nTotal distance sum = %d\n\n", ++t, dp[N][K]); 
	}
	return 0;
}

