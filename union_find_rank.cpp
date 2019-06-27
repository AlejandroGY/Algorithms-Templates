#include <bits/stdc++.h>

class UnionFind {
private:
   int sets;
   std::vector<int> p, rank;
public:
   UnionFind(int N) {
      sets = N;
      rank.assign(N, 0);
      p.assign(N, 0);
      std::iota(p.begin( ), p.end( ), 0);
   }

   int find_set(int i) {
      return (p[i] == i ? i : (p[i] = find_set(p[i])));
   }

   bool same_set(int i, int j) {
      return find_set(i) == find_set(j);
   }

   void union_set(int i, int j) {
      int x = find_set(i), y = find_set(j);
      if (rank[x] > rank[y]) {
         p[y] = x;
      } else {
         p[x] = y;
         if (rank[x] == rank[y]) rank[y] += 1;
      }
      sets -= 1;
   }

   int num_sets( ) {
      return sets;
   }
};

int main( ) {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0), std::cout.tie(0);

   UnionFind(5);
}
