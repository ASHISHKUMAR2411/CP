#include <iostream>
#include <stack>
#include <vector>

struct Building {
    int pos;
    int height;
};

std::vector<int> find_rightmost_building(const std::vector<Building>& buildings) {
    std::vector<int> result(buildings.size(), 0);
    std::stack<int> visible_buildings;

    for (int i = buildings.size() - 1; i >= 0; i--) {
        while (!visible_buildings.empty() && buildings[i].height > buildings[visible_buildings.top()].height) {
            visible_buildings.pop();
        }

        if (visible_buildings.empty()) {
            result[i] = i;
        } else {
            result[i] = visible_buildings.top();
        }

        visible_buildings.push(i);
    }

    return result;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Building> buildings(n);
    for (int i = 0; i < n; i++) {
        std::cin >> buildings[i].pos >> buildings[i].height;
    }

    std::vector<int> result = find_rightmost_building(buildings);

    for (int i = 0; i < n; i++) {
        std::cout << result[i] + 1 << std::endl;
    }

    return 0;
}
