#include <stdio.h>

#define INF 1000000
#define MAX_N 10

int n, w[MAX_N][MAX_N], visited[MAX_N];
int best[MAX_N], min_dist = INF;

void tsp(int i, int dist) {
  if (dist >= min_dist) return;
  if (i == n) {
    if (dist + w[best[n-1]][0] < min_dist) {
      min_dist = dist + w[best[n-1]][0];
      for (int j = 0; j < n; j++) best[j] = visited[j];
    }
    return;
  }
  for (int j = 0; j < n; j++) {
    if (visited[j]) continue;
    visited[j] = 1;
    tsp(i+1, dist + w[best[i-1]][j]);
    visited[j] = 0;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &w[i][j]);
  visited[0] = 1;
  best[0] = 0;
  tsp(1, 0);
  printf("%d\n", min_dist);
  for (int i = 0; i < n; i++) printf("%d ", best[i]);
  printf("\n");
  return 0;
}
