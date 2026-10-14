#include "AStarPlanner.h"
#include <iostream>
#include <vector>

int main()
{
    // 0 = free space
    // 1 = obstacle
    std::vector<std::vector<int>> map =
    {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // Start position
    int startX = 0;
    int startY = 0;

    // Goal position
    int goalX = 4;
    int goalY = 4;

    // Create the A* planner
    AStarPlanner planner(startX, startY, goalX, goalY, map);

    // Run A*
    std::vector<std::vector<int>> path = planner.findPath();

    // Check whether a path was found
    if (path.empty())
    {
        std::cout << "No path found." << std::endl;
    }
    else
    {
        std::cout << "Path found:" << std::endl;

        for (int i = 0; i < path.size(); i++)
        {
            std::cout << "("
                      << path[i][0]
                      << ", "
                      << path[i][1]
                      << ")"
                      << std::endl;
        }
    }

    return 0;
}