#include <bits/stdc++.h>

using ll = long long;
constexpr ll MAX = 100010;

ll a[MAX];
ll tree[4 * MAX];

void build(ll node, ll ini, ll fin) {
   if (ini == fin) {
      tree[node] = a[ini];
   } else {
      ll mid = ini + (fin - ini) / 2;
      ll izq = 2 * node;
      ll der = 2 * node + 1;

      build(izq, ini, mid);
      build(der, mid + 1, fin);
      tree[node] = std::min(tree[izq], tree[der]);
   }
}

void update(ll node, ll ini, ll fin, ll idx, ll val) {
   if (ini == fin) {
      //a[idx] += val;
      tree[node] = val;
   } else {
      ll mid = ini + (fin - ini) / 2;
      ll izq = 2 * node;
      ll der = 2 * node + 1;
      
      if (ini <= idx && idx <= mid) {
         update(izq, ini, mid, idx, val);
      } else {
         update(der, mid + 1, fin, idx, val);
      }
      tree[node] = std::min(tree[izq], tree[der]);
   }
}

ll query(ll node, ll ini, ll fin, ll left, ll right) {
   if (right < ini || fin < left) {
      return INT_MAX;
   }
   if (left <= ini && fin <= right) {
      return tree[node];
   }
   ll mid = ini + (fin - ini) / 2;
   ll izq = 2 * node;
   ll der = 2 * node + 1;
   ll p1 = query(izq, ini, mid, left, right);
   ll p2 = query(der, mid + 1, fin, left, right);
   return std::min(p1, p2);
}

int main( ) {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);

   ll n, q;
   std::cin >> n >> q;
   for (int i = 1; i <= n; ++i) {
      std::cin >> a[i];
   }

   build(1, 1, n);
   for (int i = 0; i < q; ++i) {
      char c;
      ll l, r;
      std::cin >> c >> l >> r;
      if (c == 'q') {
         std::cout << query(1, 1, n, l, r) << "\n";
      } else {
         update(1, 1, n, l, r);
      }
   }
}
