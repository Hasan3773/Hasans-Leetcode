class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        // memory1 and memory2 are the sizes of available memory on two disks
        // memory is allocated to the disk with mmore space at every second 1 - ith
        // return [iCrash, mem1Crash, mem2Crash]
        // one more bit of memeory is added each timestep
        int i = 0;
        // cout << "starting Mem1 & Mem2: " << memory1 << "," << memory2 << endl;
        while(memory1 - i >= 0 || memory2 - i >= 0){
            if (memory1 >= memory2){
                memory1 -= i;
            }
            else{
                memory2 -= i;
            }
            // cout << "Current Mem1 & Mem2: " << memory1 << "," << memory2 << endl;
            i++;
        }
        vector<int> answer = {i, memory1, memory2};
        return answer;
    }
};