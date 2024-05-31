//
// Created by pro on 5/31/2024.
//

#ifndef AI_HOMEWORK_DFSSOLUTION_H
#define AI_HOMEWORK_DFSSOLUTION_H

#include "../includer.h"

class DfsSolution {
public:
    DfsSolution(int numCities, const vector<vector<int>>& distances) : numCities(numCities), distances(distances), minLongestDistance(INT_MAX) {
        visited.resize(numCities, false);
    }

    void solve() {
        visited[0] = true;
        currentRoute.push_back(0);
        dfs(0, 0);
    }

    void printSolution() const {
        cout << "Minimum longest distance: " << minLongestDistance << endl;
        cout << "Best route: ";
        for (int city : bestRoute) {
            cout << city << " ";
        }
        cout << endl;
    }

    int calculateTotalCost() {
        int totalCost = 0;
        for (size_t i = 0; i < bestRoute.size() - 1; ++i) {
            totalCost += distances[bestRoute[i]][bestRoute[i + 1]];
        }
        return totalCost;
    }

private:
    int numCities;

    vector<vector<int>> distances;

    vector<bool> visited;

    vector<int> currentRoute;

    int minLongestDistance;

    vector<int> bestRoute;

    void dfs(int node, int currentLongest) {
        if (currentRoute.size() == numCities) {
            currentLongest = max(currentLongest, distances[node][0]);
            if (currentLongest < minLongestDistance) {
                minLongestDistance = currentLongest;
                bestRoute = currentRoute;
                bestRoute.push_back(0);
            }

            return;
        }

        for (int i = 0; i < numCities; i++) {
            if (!visited[i]) {
                visited[i] = true;
                currentRoute.push_back(i);
                int newLongest = max(currentLongest, distances[node][i]);
                dfs(i, newLongest);
                currentRoute.pop_back();
                visited[i] = false;
            }
        }
    }
};


#endif //AI_HOMEWORK_DFSSOLUTION_H
