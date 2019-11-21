#include <bits/stdc++.h>

int n, m;
char mapa[1001][1001];
bool visitado[1001][1001];

std::pair<int, int> vec[] = {
   { -1, 0 },
   { 1, 0 },
   { 0, -1 },
   { 0, 1 }
};

void dfs(int i, int j) {
   for (int k = 0; k < 4; ++k) {
      int dx = i + vec[k].first, dy = j + vec[k].second;
      if (dx >= 0 && dx < n && dy >= 0 && dy < m && mapa[dx][dy] == '.' && !visitado[dx][dy]) {
         visitado[dx][dy] = true;
         dfs(dx, dy);
      }
   }
}

int main( ) {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(nullptr), std::cout.tie(nullptr);

   std::cin >> n >> m;

   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         std::cin >> mapa[i][j];
      }
   }

   int cuartos = 0;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         if (mapa[i][j] == '.' && !visitado[i][j]) {
            dfs(i, j);
            cuartos += 1;
         }
      }
   }
   std::cout << cuartos << "\n";
}
