class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        // we're simulating tx-=ty or ty-=tx until one of them gets to source
        // we use modulo to make either ty or tx smaller than the other (then we use the opposite on the next iteration)
        while(sx < tx && sy < ty) {
            if(tx < ty) ty %= tx;
            else tx %= ty;
        }
        //if either ty or tx is divisible by the source and the reamining ssource is < target then return true (assuming the opposite sourse is actually equal to its target)
        return (!((ty-sy)%sx) && sy <= ty && sx == tx) || 
               (!((tx-sx)%sy) && sx <= tx && sy == ty);
    }
};