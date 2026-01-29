class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int first = 0;
        int last = numbers.size() - 1;
        vector<int> sol;
        while(first < last){
            cout << "first: " << first << "last: " << last << "\n"; 
            if ((numbers[last] + numbers[first]) == target){
                sol.push_back(first + 1);
                sol.push_back(last + 1);
                cout << "enterred answer:" << first + 1 << " and " << last + 1 << "\n";
                return sol;
            }
            if (numbers[last] + numbers[first] > target){
                last--;            
            }
            else{
                first++;
            }
        }
        return sol;
    }
};