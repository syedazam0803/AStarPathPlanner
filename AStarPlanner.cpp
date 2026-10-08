#include "AStarPlanner.h"
#include <cmath>
AStarPlanner::AStarPlanner(
        int startX,
    int startY,
    int goalX,
    int goalY,
    const std::vector<std::vector<int>>& map
    ){
        this->startX = startX;
        this->startY =startY;
        this->goalX = goalX;
        this->goalY = goalY;
        this-> map = map;
    }

int AStarPlanner::heuristicCalculator(int x, int y){
    int h = std::abs(goalX - x) + std::abs(goalY - y);
    return h;
}
void AStarPlanner::findPath(){
    Node startNode;
    startNode.x = startX;
    startNode.y = startY;
    startNode.g = 0;
    startNode.h = heuristicCalculator(startNode.x,startNode.y);
    startNode.f = startNode.g + startNode.h;
    startNode.parentX = -1;
    startNode.parentY = -1;
}