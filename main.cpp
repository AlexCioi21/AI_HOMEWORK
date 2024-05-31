#include <iostream>
#include <vector>

#include "dfs/DfsSolution.h"
#include "uniform_cost/UniformCost.h"
#include "a_Search/ASearch.h"

#include <chrono>
#include <climits>

using namespace std;

int calculateTotalCost(vector<int> route, vector<vector<int>> distances) {
    int totalCost = 0;
    for (size_t i = 0; i < route.size() - 1; ++i) {
        totalCost += distances[route[i]][route[i + 1]];
    }
    return totalCost;
}

int main() {
    int numCities = 4;
    vector<vector<int>> distances = {
            {0, 10, 15, 20},
            {10, 0, 35, 25},
            {15, 35, 0, 30},
            {20, 25, 30, 0}
    };

    cout << "\n***********************************************************************\n\n";
    cout << "DFS\n\n";

    DfsSolution dfs(numCities, distances);
    auto start = std::chrono::high_resolution_clock::now();
    dfs.solve();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time taken by solve method: " << duration.count() << " microseconds" << endl;
    cout << "Total cost: " << dfs.calculateTotalCost() << "\n";
    dfs.printSolution();

    cout << "\n***********************************************************************\n\n";
    cout << "UNIFORM COST\n\n";

    UniformCost uniformCost(numCities, distances);
    start = std::chrono::high_resolution_clock::now();
    uniformCost.solve();
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time taken by solve method: " << duration.count() << " microseconds" << endl;
    cout << "Total cost: " << uniformCost.calculateTotalCost() << "\n";
    uniformCost.printSolution();

    cout << "\n***********************************************************************\n\n";
    cout << "A* SEARCH\n\n";

    ASearch aSearch(numCities, distances);
    start = std::chrono::high_resolution_clock::now();
    aSearch.solve();
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time taken by solve method: " << duration.count() << " microseconds" << endl;
    cout << "Total cost: " << aSearch.calculateTotalCost() << "\n";
    aSearch.printSolution();

    return 0;
}