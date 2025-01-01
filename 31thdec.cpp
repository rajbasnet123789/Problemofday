/*m
Topics
Companies
You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.

 */
 class Solution {
public:
    int t[366];
    int memoized(vector<int>& days, vector<int>& costs, int& n, int idx) {
        if(idx >= n)
            return 0; //you can't travel, so no cost
                
        if(t[idx] != -1)
            return t[idx];
        
        //if i take 1-day pass at idx
        int cost_1 = costs[0] + memoized(days, costs, n, idx+1);
        
        
        //if i take 7-day pass at idx
        int i = idx;
        while(i < n && days[i] < days[idx]+7) {
            i++;
        }
        int cost_7 = costs[1] + memoized(days, costs, n, i);
        
        
        //if i take 30-day pass at idx
        int j= idx;
        while(j < n && days[j] < days[idx]+30) {
            j++;
        }
        int cost_30 = costs[2] + memoized(days, costs, n, j);
        
        
        return t[idx] = min({cost_1, cost_7, cost_30});
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(t, -1, sizeof(t));
        int n = days.size();
        return memoized(days, costs, n, 0);
    }
};