//Numero de enteros distintos en un rango, q <= 200000
#include <bits/stdc++.h>
 
#define fi first
#define se second
using ll = long long;
 
constexpr int MAX = 300002;
constexpr int MAXN = 1000002;
 
ll n, q, idx;
ll v[MAX], res[MAX], BIT[MAX];
ll memo[MAXN];
std::pair<ll, std::pair<ll, ll>> p[MAX];
 
void update(ll i, ll x){
	while (i <= MAX) {
		BIT[i] += x;
		i += (i & -i);
	}
}
 
ll query(ll i){
	ll res = 0;
	while (i > 0) {
		res += BIT[i];
		i -= (i & -i);
	}
	return res;
}
 
int main( ) {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> v[i];
	}
	
	std::cin >> q;
	for (int i = 0; i < q; ++i) {
		std::cin >> p[i].se.fi >> p[i].fi;
		p[i].se.se = i;
	}
	std::sort(p, p + q);
	std::fill(memo, memo + MAXN, -1);
	
	for (int i = 1; i <= n; ++i) {
		if (memo[v[i]] != -1) {
			update(memo[v[i]], -1);
		}
		memo[v[i]] = i;
		update(i, 1);
		
		while (p[idx].fi == i && idx < q) {
			res[p[idx].se.se] = query(i) - query(p[idx].se.fi - 1);
			++idx;
		}
	}
	
	for (int i = 0; i < q; ++i) {
		std::cout << res[i] << "\n";
	}
}
