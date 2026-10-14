#include "AStarPlanner.h"
#include <cmath>
#include <algorithm>
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
std::vector<std::vector<int>> AStarPlanner::findPath(){
    std::vector<std::vector<int>> path;
    Node startNode;
    startNode.x = startX;
    startNode.y = startY;
    startNode.g = 0;
    startNode.h = heuristicCalculator(startNode.x,startNode.y);
    startNode.f = startNode.g + startNode.h;
    startNode.parentX = -1;
    startNode.parentY = -1;
    Node currentNode;
   Directions right;
   right.x = 1;
   right.y = 0;
   direction.push_back(right);
   Directions left;
   left.x = -1;
   left.y = 0;
   direction.push_back(left);
   Directions top;
   top.x = 0;
   top.y = 1;
   direction.push_back(top);
   Directions down;
   down.x = 0;
   down.y = -1;
   direction.push_back(down);


    openList.push_back(startNode);
    while(!openList.empty()){
        int lowestIndex = 0;
        for(int i = 1 ; i < openList.size() ; i++){
            if(openList[i].f < openList[lowestIndex].f){
                lowestIndex = i;
            }
        }
        currentNode = openList[lowestIndex];
        openList.erase(openList.begin() + lowestIndex);
        closedList.push_back(currentNode);
        if (currentNode.x == goalX && currentNode.y == goalY){
            path.push_back({currentNode.x,currentNode.y});

           while (currentNode.x != startX || currentNode.y != startY){
            for (int l = 0; l < closedList.size(); l++)
                {
                if (closedList[l].x == currentNode.parentX &&
                closedList[l].y == currentNode.parentY)
                    {
                        path.push_back({closedList[l].x, closedList[l].y});
                        currentNode = closedList[l];
                        break;
                }
            }
        }
        std::reverse(path.begin(),path.end());
        return path;
           
        }
        else{
            for(int i =0; i < direction.size() ; i++ ){
                int neighborX = currentNode.x + direction[i].x;
                int neighborY = currentNode.y +direction [i].y;
                if( neighborX >= 0 && neighborX <map[0].size() && neighborY >= 0 && neighborY < map.size()){
                    if (map[neighborY][neighborX] == 0){
                        bool alreadyClosed = false;
                        for(int j = 0; j < closedList.size();j++){
                            if(closedList[j].x == neighborX && closedList[j].y == neighborY){
                                alreadyClosed = true;
                            }
                        }
                    if(alreadyClosed != true){
                        Node neighborNode;
                        neighborNode.x = neighborX;
                        neighborNode.y = neighborY;
                        neighborNode.g = currentNode.g + 1;
                        neighborNode.h = heuristicCalculator(neighborNode.x, neighborNode.y);
                        neighborNode.f = neighborNode.g + neighborNode.h;
                        neighborNode.parentX = currentNode.x;
                        neighborNode.parentY = currentNode.y;
                        bool alreadyInOpenList = false;

                        for (int k =0; k < openList.size(); k++){
                            if (openList[k].x == neighborNode.x && openList[k].y == neighborNode.y){
                                alreadyInOpenList = true;
                                if(neighborNode.g < openList[k].g){
                                    openList[k] = neighborNode;
                                }
                            }
                        }

                        if (alreadyInOpenList == false){
                            openList.push_back(neighborNode);
                        }
                        


                                    
                                }
                        

                    }

                }
                

            }
            
        }
        
    }
    return path;
   
    
}