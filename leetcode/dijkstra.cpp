#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> dijkstra (int& source, int n, vector<vector<int>>& data){
    // Create a graph from data : [[source, dest, weight]]
    vector <vector<pair<int, int>>> graph(n);
    for(auto& points: data) {
        graph[points[0]].push_back({points[1], points[2]});
        graph[points[1]].push_back({points[0], points[2]});   
    }
    // initialize data structures
    vector<long long> minimum_distance(graph.size(), LONG_LONG_MAX);
    minimum_distance[source] = 0;
    // initialize a priority queue and push the first element as pair {distance, node}
    priority_queue <pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0,0});
    // check uptill priority queue gets empty
    while(!pq.empty()){
        auto distance = pq.top().first;
        auto curr_node = pq.top().second;
        pq.pop();         
        // optimization for less comparisons
        if (distance>minimum_distance[curr_node]){ continue;}
        // for each vertex in adj[node], perform relax operation
        for (auto neighbor : graph[curr_node]){
            // Perform relax operation ..
            if (minimum_distance[neighbor.first]>distance+neighbor.second){
                minimum_distance[neighbor.first]=distance+neighbor.second;
                pq.push({minimum_distance[neighbor.first], neighbor.first});
            }
        }  
    }
    return (minimum_distance);
}