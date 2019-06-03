#include <bits/stdc++.h>

constexpr int MAX = 101;

int n, m;
bool graph[MAX][MAX];
int boys[MAX], girls[MAX];

bool bpm(int u, bool seen[], int match[]) {
   for (int v = 0; v < n; ++v) {
      if (graph[u][v] && !seen[v]) {
         seen[v] = true;
         if (match[v] < 0 || bpm(match[v], seen, match)) {
            match[v] = u;
            return true;
         }
      }
   }
   return false;
}

int matching( ) {
   int match[MAX];
   std::fill(match, match + MAX, -1);

   int res = 0;
   for (int u = 0; u < m; ++u) {
      bool seen[MAX] = { };
      if (bpm(u, seen, match)) {
         res += 1;
      }
   }
   return res;
}

int main( ) {
   std::cin >> n;
   for (int i = 0; i < n; ++i) {
      std::cin >> boys[i];
   }

   std::cin >> m;
   for (int i = 0; i < m; ++i) {
      std::cin >> girls[i];
   }

   std::sort(boys, boys + n);
   std::sort(girls, girls + m);

   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         int dif = std::abs(boys[i] - girls[j]);
         if (dif <= 1) {
            graph[j][i] = true;
         }
      }
   }

   std::cout << matching( ) << "\n";
}
