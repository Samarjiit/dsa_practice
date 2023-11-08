class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int xdiff=abs(sx-fx);
        int ydiff=abs(sy-fy);
        
        if(xdiff ==0 && ydiff==0 && t==1)return false;
        if(xdiff==0 && ydiff==0 && t==1)return false;

        int min_t=max(xdiff,ydiff);
        if(t<min_t)return false;

        return true;
    }
};