/*1475. Final Prices With a Special Discount in a Shop
Solved
Easy
Topics
Companies
Hint
You are given an integer array prices where prices[i] is the price of the ith item in a shop.

There is a special discount for items in the shop. If you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i]. Otherwise, you will not receive any discount at all.

Return an integer array answer where answer[i] is the final price you will pay for the ith item of the shop, considering the special discount.*/
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
            stack<int>st;
            int n=prices.size();
              vector<int>result(n);
            for(int i=n-1;i>=0;i--){
                  while(!st.empty() && st.top()>prices[i]){
                    st.pop();
                  }
                  result[i]=prices[i]-(st.empty() ? 0 : st.top());
                  st.push(prices[i]);
            }
            return result;

    }
};