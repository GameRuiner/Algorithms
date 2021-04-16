// C++ Program 
// 
#include <bits/stdc++.h>
#include <algorithm> 
using namespace std;

bool setCoverset(set<int> I, set<int> U) {
    for(auto num : U) {
        if (I.find(num) == I.end()) {
            return false;
        }
    }
    return true;
}

set<int> setUnion(set<int> S1, set<int> S2) {
    set <int> res;
    for(auto num : S1) {
        res.insert(num);
    }
    for(auto num : S2) {
        res.insert(num);
    }
    return res;
}

set<int> setInersection(set<int> S1, set<int> S2) {
    set <int> res;
    for(auto num : S1) {
        res.insert(num);
    }
    for(auto num : S2) {
        res.erase(num);
    }
    return res;
}

void printSet(set<int> S) {
    cout << "\n";
    for(auto num : S) {
        cout << num << " ";
    }
    cout << "\n";
}

int setCover(set<int> U, vector<set<int>*> S, vector<int> costs)
{
    set<int> I;
    int sumCost = 0;
    cout << "Set cover is {";
    while (!setCoverset(I,U)) {
        float minCost = INT_MAX;
        int minI = 0;
        int i = 0;
        for(auto cost : costs) {
            float interSecSize = (float)(setInersection(*S[i], I).size());
            float effectiveness = cost / interSecSize;
            if (effectiveness < minCost) {
                minCost = effectiveness;
                minI = i;
            }
            i++;
        }
        sumCost+=costs[minI];
        I = setUnion(I, *S[minI]);
        cout << " S" << minI; 
        S.erase(S.begin()+minI);
        costs.erase(costs.begin()+minI);
    }
    cout << " } \nMinimum cost of set cover " << sumCost << "\n";
    return 0;
}

int main()
{
    set<int> U = {1,2,3,4,5};
    set<int> S1 = {4,1,3};
    set<int> S2 = {2,5};
    set<int> S3 = {1,4,3,2};
    vector<int> costs = {5,10,3};
    vector<set<int>*> S = {&S1,&S2,&S3};
    setCover(U,S,costs);
    return 0;
}