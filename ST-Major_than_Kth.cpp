//Regresa el numero de elementos mayores que 'K' in la subsecuencia a_i, a_i+1, ... a_j
#include <bits/stdc++.h>

using ll = long long;
constexpr ll MAX = 30030;

struct nodo {
   ll* arr;
   ll tam;
};

ll n, q, last;
ll i, j, k;
ll a, b, c;
ll v[MAX];
nodo tree[4 * MAX];

void build(ll node, ll ini, ll fin) {
   if (ini == fin) {
      tree[node].arr = new ll[0];
      tree[node].arr[0] = v[ini];
      tree[node].tam = 1;
      return;
   }
   ll mid = ini + (fin - ini) / 2;
   ll izq = 2 * node;
   ll der = 2 * node + 1;

   build(izq, ini, mid);
   build(der, mid + 1, fin);

   ll t_izq = tree[izq].tam;
   ll t_der = tree[der].tam;
   tree[node].tam = t_izq + t_der;
   tree[node].arr = new ll[tree[node].tam];
   std::merge(tree[izq].arr, tree[izq].arr + t_izq, tree[der].arr, tree[der].arr + t_der, tree[node].arr);
}

ll query(ll node, ll ini, ll fin, ll i, ll j, ll k) {
   if (j < ini || i > fin) {
      return 0;
   }
   if (i <= ini && fin <= j) {
      auto it = std::upper_bound(tree[node].arr, tree[node].arr + tree[node].tam, k);
      return (tree[node].arr + tree[node].tam - it);
   }

   ll mid = ini + (fin - ini) / 2;
   ll izq = 2 * node;
   ll der = 2 * node + 1;
   ll p1 = query(izq, ini, mid, i, j, k);
   ll p2 = query(der, mid + 1, fin, i, j, k);
   return p1 + p2;
}

int main( ) {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);

   std::cin >> n;
   for (int i = 1; i <= n; ++i) {
      std::cin >> v[i];
   }

   build(1, 1, n);

   std::cin >> q;
   while (q--) {
      std::cin >> a >> b >> c;

      i = a ^ last;
      j = b ^ last;
      k = c ^ last;

      //--i, --j;
      last = query(1, 1, n, i, j, k);
      std::cout << last << "\n";
   }
}
