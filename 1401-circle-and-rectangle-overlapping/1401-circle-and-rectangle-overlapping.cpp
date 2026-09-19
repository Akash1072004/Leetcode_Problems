class Solution { 
public: 
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) { 
        
        if((xCenter + radius) < x1 || (yCenter + radius) < y1) return false;
        if((xCenter - radius) > x2 || (yCenter - radius) > y2) return false;

        // for the diagonals

        if(xCenter < x1 && yCenter < y1) {
            return (x1-xCenter)*(x1-xCenter) + (y1-yCenter)*(y1-yCenter) <= radius*radius;
        }

        if(xCenter < x1 && yCenter > y2) {
            return (x1-xCenter)*(x1-xCenter) + (y2-yCenter)*(y2-yCenter) <= radius*radius;
        }

        if(xCenter > x2 && yCenter < y1) {
            return (x2-xCenter)*(x2-xCenter) + (y1-yCenter)*(y1-yCenter) <= radius*radius;
        }

        if(xCenter > x2 && yCenter > y2) {
            return (x2-xCenter)*(x2-xCenter) + (y2-yCenter)*(y2-yCenter) <= radius*radius;
        }

        return true;
    } 
};