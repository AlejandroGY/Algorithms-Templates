#include <bits/stdc++.h>

std::vector<int> p;

int find(int a) {
   return (p[a] == a ? a : p[a] = find(p[a]));
}

void Union(int a, int b) {
   p[find(a)] = find(b);
}

bool sameSet(int a, int b) {
   return (find(a) == find(b));
}

int main( ) {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);

   int n, m;
   std::cin >> n >> m;

   p.resize(n);
   std::iota(p.begin( ), p.end( ), 0);

   for (int i = 0; i < m; ++i) {
      char c;
      int x, y;
      std::cin >> c >> x >> y;

      if (c == 'P') {
         std::cout << sameSet(x, y) << "\n";
      } else {
         Union(x, y);
      }
   }
}
