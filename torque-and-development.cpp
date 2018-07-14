#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

void create_set(int element, vector<int> &parent) {
  parent[element] = element;
}

int find_parent(int element, vector<int> &parent) {
  if (element != parent[element]) {
    parent[element] = find_parent(parent[element], parent);
  }
  return parent[element];
}

void merge_sets(int elem1, int elem2, vector<int> &parent, int &set_count) {
  int parent1 = find_parent(elem1, parent);
  int parent2 = find_parent(elem2, parent);

  if (parent1 != parent2) {
    set_count--;
    parent[parent1] = parent[parent2];
  }
}

void find_disjoints(vector<int> &parent, vector<vector<int>> graph, int &set_count) {
  for (int i = 0; i < graph.size(); ++i) {
    for (int j = 0; j < graph[i].size(); ++j) {
      merge_sets(i, graph[i][j], parent, set_count);
    }
  }
}

int main() {
  int q; cin >> q;

  while (q-- > 0) {
    int roads, c1, c2, cities, cost_lib, cost_road;
    scanf("%d %d %d %d", &cities, &roads, &cost_lib, &cost_road);

    if (cost_road >= cost_lib || roads == 0) {
      printf("%lld\n", (long long int ) cost_lib*cities);
      while (roads-- > 0) scanf("%d %d", &c1, &c2);
      continue;
    }

    vector<vector<int>> city_map(cities);
    for (int i = 0; i < roads; i++) {
      scanf(" %d %d ", &c1, &c2);
      city_map[c1 - 1].push_back(c2 - 1);
      city_map[c2 - 1].push_back(c1 - 1);
    }

    vector<int> parent(cities);
    for (int i = 0; i < cities; ++i) {
      create_set(i, parent);
    }

    int set_count = cities;
    find_disjoints(parent, city_map, set_count);

    vector<int> set_lengths(cities);
    for_each(parent.begin(), parent.end(), [&](int val){
      set_lengths[find_parent(val, parent)]++;
    });

    long int cost = 0;
    for_each(set_lengths.begin(), set_lengths.end(), [&](int length){
      if (length == 0) return;
      cost += cost_road * (length-1) + cost_lib;
    });

    cout << cost << endl;
  }
}