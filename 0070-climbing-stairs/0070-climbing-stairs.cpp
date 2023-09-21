class Solution {
public:
    int climbStairs(int n){
        unordered_map<int,int> table;
        return climbStairs(n, table);
    }
    int climbStairs(int n, unordered_map <int,int>& table) {
        if (n == 0 || n == 1)
            return 1;

        if(table.find(n) == table.end())
            table[n] = climbStairs(n - 1, table) + climbStairs(n - 2, table);

        return table[n];

    }
};