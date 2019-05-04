//Calcula en numero de factores primos de un numero, durante la criba.
#include <bits/stdc++.h>

using ll = long long;
constexpr ll MAX = 5000010;

ll sp[MAX];
ll factores[MAX];

void criba( ) {
   for (ll i = 2; i < MAX; ++i) {
      if (sp[i] == 0) {
         for (ll j = 1; j * i < MAX; ++j) {
            sp[i * j] = i;
         }
      }
   }
   for (ll i = 2; i < MAX; ++i) {
      factores[i] = factores[i / sp[i]] + 1;
   }
   for (ll i = 2; i < MAX; ++i) {
      factores[i] += factores[i - 1];
   }
}


int main( ) {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);

   int n;
   std::cin >> n;

   criba( );
   for (int t = 0; t < n; ++t) {
      ll a, b;
      std::cin >> a >> b;
      std::cout << factores[a] - factores[b] << "\n";
   }
}
