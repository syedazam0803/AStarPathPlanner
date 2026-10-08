
#ifndef ASTARPLANNER_H
#define ASTARPLANNER_H

#include <vector>
#include <cmath>

class AStarPlanner{
    private:
    int startX;
    int startY;
    int goalX;
    int goalY;
    std::vector<std::vector<int>> map;

     struct Node{
        int x;
        int y;
        int g;
        int h;
        int f;
        int parentX;
        int parentY;
    };
    struct Directions{
        int x;
        int y;
    };
    std::vector<Node> openList;
    std::vector<Node> closedList;
    std::vector<Directions> direction;


    int heuristicCalculator(
        int x,
        int y
    );

    public:
    AStarPlanner(
        int startX,
    int startY,
    int goalX,
    int goalY,
    const std::vector<std::vector<int>>& map
    );

    void findPath();
};


#endif
