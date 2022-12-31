#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Solution {
public:
    long long div = 1e9 +7;
    int countPaths(int n, vector<vector<int>>& roads) {
        // Initialize source and destination nodes
        int target = roads.size()-1;
        int source = 0;
        //create adjacency list representation 
        vector <vector<pair<int, int>>> graph(n);
        for(auto& road: roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});   
        }
        return dijkstra(source, n, graph, roads);
    }
    
    int dijkstra (int& source, int& dest, vector <vector<pair<int, int>>>& graph, vector<vector<int>>& roads){
        // initialize data structures
        vector<long long> number_of_shortest_path(graph.size());
        vector<long long> minimum_distance(graph.size(), LONG_LONG_MAX);
        
        int target = dest-1;
        minimum_distance[source] = 0;
        number_of_shortest_path[source]=1;
        
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
                    number_of_shortest_path[neighbor.first] = number_of_shortest_path [curr_node];
                    pq.push({minimum_distance[neighbor.first], neighbor.first});
                }
                else if(minimum_distance[neighbor.first]==distance+neighbor.second){
                    number_of_shortest_path[neighbor.first] = (number_of_shortest_path[neighbor.first]   
                                                + number_of_shortest_path [curr_node]) % div;
                }
            }  
        }
        return number_of_shortest_path[target];
    }
};