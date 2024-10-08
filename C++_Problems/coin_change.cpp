class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int table[amount+1];
        table[0]=0;
        for(int i=1; i<=amount; i++){
            table[i]=INT_MAX;
        }
        for(int i=1; i<=amount; i++){
            for(int j=0; j<coins.size(); j++){
                if(i>=coins[j]){
                    int res=table[i-coins[j]];
                    if(res!=INT_MAX && res+1<table[i]){
                        table[i]=res+1;
                    }
                }
            }
        }
        if(table[amount]==INT_MAX) return -1;
        return table[amount];
    }
};
