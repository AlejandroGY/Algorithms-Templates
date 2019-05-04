//Factoriza n <= 10^7 en log(n)
#include <bits/stdc++.h>

using ll = long long;
constexpr ll MAX = 10000000;

bool v[MAX];
ll len, sp[MAX];

void criba( ) {
   for (ll i = 2; i < MAX; i += 2) sp[i] = 2;
   for (ll i = 3; i < MAX; i += 2) {
      if (!v[i]) {
         sp[i] = i;
         for (ll j = i; (i * j) < MAX; j += 2) {
            if (!v[i * j]) {
               v[i * j] = true, sp[i * j] = i;
            }
         }
      }
   }
}

std::vector <ll> factoriza(ll k) {
	std::vector <ll> res;
	while (k > 1) {
		res.push_back(sp[k]);
		k /= sp[k];
	}
	return res;
}

int main( ) {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);

   criba( );
   std::vector<ll> factores = factoriza(1000);
   for (auto f : factores) {
      std::cout << f << " ";
   }
}
