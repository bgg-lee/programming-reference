#include <iostream>
#include <vector>
#include <queue>
#include "functions.hpp"

using namespace std;
// sssp, single source shorest path, dijkstra, bellmanford --> 넘 어렵다 이것들아..
const int MOD = 2'147'483'647;  // INT_MAX (문제 요구 사항)
void flightRoute(const int n, const int m, const vector<vector<int>> & route_info)
{
    vector<vector<pair<int, int>>> adj_list(n + 1);
    for (const auto& route : route_info) {
        int a = route[0], b = route[1], c = route[2];
        adj_list[a].emplace_back(b, c);
    }

    vector<long long> prices(n + 1, LLONG_MAX); // 최소 비용
    vector<long long> num_routes(n + 1, 0); // 최소 비용 만족 경로 개수
    vector<int> min_flights(n + 1, INT_MAX); // 최소 경유
    vector<int> max_flights(n + 1, 0); // 최대 경유

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    // 출발 전 초기화
    pq.push({0, 1}); // (비용,노드)
    prices[1] = 0;
    num_routes[1] = 1;
    min_flights[1] = 0;
    max_flights[1] = 0;

    while (!pq.empty()) {
        long long curr_price = pq.top().first;
        int curr_city = pq.top().second;
        pq.pop();

        if (curr_price > prices[curr_city]) continue;

        for (const auto& neighbor : adj_list[curr_city]) {
            int next_city = neighbor.first;
            long long next_price = curr_price + neighbor.second;

            if (next_price < prices[next_city]) {
                prices[next_city] = next_price;
                num_routes[next_city] = num_routes[curr_city] % MOD;
                min_flights[next_city] = min_flights[curr_city] + 1;
                max_flights[next_city] = max_flights[curr_city] + 1;
                pq.push({next_price, next_city});
            } else if (next_price == prices[next_city]) {
                num_routes[next_city] = (num_routes[next_city] + num_routes[curr_city]) % MOD;
                min_flights[next_city] = min(min_flights[next_city], min_flights[curr_city] + 1);
                max_flights[next_city] = max(max_flights[next_city], max_flights[curr_city] + 1);
            }
        }
    }

    long long min_price = (prices[n] == LLONG_MAX) ? -1 : prices[n];
    int min_routes = static_cast<int>(num_routes[n] % MOD);
    int min_flights_count = (min_flights[n] == INT_MAX) ? -1 : min_flights[n];
    int max_flights_count = max_flights[n];

    // Ensure the min_price does not exceed INT_MAX
    // if (min_price > INT_MAX) min_price = INT_MAX;

    cout << min_price << " " << min_routes << " " << min_flights_count << " " << max_flights_count;
}