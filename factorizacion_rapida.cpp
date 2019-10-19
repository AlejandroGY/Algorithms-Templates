#include <bits/stdc++.h>

using ull = unsigned long long;
using ll = long long;
constexpr int rounds = 10;

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

ll mod_mul(ull a, ull b, ull mod) {
	ull ret = 0;
	for (a %= mod, b %= mod; b != 0; b >>= 1, a <<= 1, a = (a >= mod ? a - mod : a)) {
		if (b & 1) {
			ret += a;
			if (ret >= mod) {
				ret -= mod;
			}
		}
	}
	return ret;
}

ll mod_pow(ll a, ll exp, ll mod) {
	ll ans = 1;
	while (exp > 0) {
		if(exp & 1)
			ans = mod_mul(ans,a,mod);
		a = mod_mul(a,a,mod);
		exp >>= 1;
	}
	return ans;
}

bool witness(ll a, ll n) {
	ll u = n - 1;
	ll t = 0;
	if(n == a) return true;
	while (u % 2 == 0) {
		t++;
		u >>= 1;
	}

	ll next = mod_pow(a, u, n);
	if (next == 1) return false;
	ll last;
	for (int i = 0; i < t; ++i) {
		last = next;
		next = mod_mul(last, last, n);
		if (next == 1) {
            return (last != n - 1);
        	}
    	}
	return (next != 1);
}

bool miller_rabin(ull n, int it = rounds) {
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;

	for (int i = 0; i < it; ++i) {
		ll a = std::rand( ) % (n-1) + 1;
		if (witness(a, n)) {
			return false;
		}
	}
	return true;
}

long long pollard_rho(ll n) {
	ll x, y, i = 1, k = 2, d;
	x = y = std::rand( ) % n;

	while (1) {
		++i;
		x = mod_mul(x, x, n);
		x += 2;
		
		if (x >= n) x -= n;
		if (x == y) return 1;

		d = gcd(abs(x - y), n);
		if (d != 1) return d;
		if (i == k) {
			y = x;
			k *= 2;
		}
	}
	return 1;
}

std::vector<ll> factorize(ll n) {
	std::vector<ll> ans;
	if (n == 1) {
		return ans;
	}
	if (miller_rabin(n)) {
		ans.push_back(n);
	} else {
		ull d = 1ull;
		while(d == 1) {
			d = pollard_rho(n);
		}
		std::vector<ll> dd = factorize(d);
		ans = factorize(n / d);
		for(int i = 0; i < dd.size( ); i++) {
         ans.push_back(dd[i]);
      }
	}
	return ans;
}


int main( ) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int t;
	std::cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		ll n;
		std::cin >> n;
      std::map<ll, ll> memo;
		std::vector<ll> facts = factorize(n);
		std::sort(facts.begin( ), facts.end( ));

      for (ll i = 0; i < facts.size( ); ++i) {
			memo[facts[i]] += 1;
		}

      int res = 1;
      for (auto it : memo) {
         res *= (it.second + 1);
      }
      std::cout << (res == 3 ? "YES\n" : "NO\n");
	}
}
