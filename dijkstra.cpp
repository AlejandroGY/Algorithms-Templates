#include <bits/stdc++.h>

using ll = long long;
constexpr ll INF = std::numeric_limits<ll>::max( );

void dijkstra(ll s, std::vector<ll>& d, std::vector<ll>& p, std::vector<std::pair<ll, ll>> adj[], ll ns) {
   ll n = ns;
   d.assign(n, INF);
   p.assign(n, -1);

   d[s] = 0;
   using par = std::pair<ll, ll>;
   std::priority_queue<par, std::vector<par>, std::greater<par>> q;
   q.push({ 0, s });

   while (!q.empty( )) {
      ll v = q.top( ).second;
      ll d_v = q.top( ).first;
      q.pop( );

      if (d_v != d[v]) {
         continue;
      }

      for (auto edge : adj[v]) {
         ll to = edge.first;
         ll len = edge.second;

         if (d[v] + len < d[to]) {
            d[to] = d[v] + len;
            p[to] = v;
            q.push({ d[to], to });
         }
      }
   }
}

std::vector<ll> restore_path(ll s, ll t, const std::vector<ll>& p) {
   std::vector<ll> path;
   for (ll v = t; v != s; v = p[v]) {
      path.push_back(v);
   }
   path.push_back(s);

   std::reverse(path.begin( ), path.end( ));
   return path;
}

int main( ) {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);

   int n, m;
   std::cin >> n >> m;
   
   std::vector<ll> d, p;
   std::vector<std::pair<ll, ll>> adj[n];
   for (int i = 0; i < m; ++i) {
      int a, b, w;
      std::cin >> a >> b >> w;
      adj[a - 1].push_back({ b - 1, w });
      adj[b - 1].push_back({ a - 1, w });
   }
   dijkstra(0, d, p, adj, n);

   if (d[n - 1] != INF) {
      std::vector<ll> path = restore_path(0, n - 1, p);
      for (auto act : path) {
         std::cout << act + 1 << " ";
      }
      std::cout << "\n";
   } else {
      std::cout << "-1\n";
   }
}
