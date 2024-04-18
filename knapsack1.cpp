#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution{
public:
    int max_val = 100;
    int n = 50; // Number of items
    vector<float> profit = vector<float>(n,0.0);
    vector<float> weights = vector<float>(n,0.0);
    vector<float> pw = vector<float>(n,0.0);

    void Generate(vector<float>& arr){
        int m = arr.size();
        for(int j = 0; j < m; j++){
            arr[j] = rand() % max_val;
        }
    }

    vector<float> profit_weight(vector<float> a, vector<float> b){
        vector<float> c = vector<float>(a.size(),0.0);
        for(int j = 0; j < a.size(); j++){
            c[j] = a[j] / b[j];
        }
        return c;
    }

    vector<float> KnapSack(vector<float>& weight, vector<float>& profit, int max)  {
        int n = weight.size();
        vector<float> result = vector<float>(n, 0.0);
        vector<pair<float, int>> profit_weight_ratio;

        for(int i = 0; i < n; i++) {
            profit_weight_ratio.push_back({profit[i] / weight[i], i});
        }

        sort(profit_weight_ratio.begin(), profit_weight_ratio.end());

        for(int i = 0; i < n; i++) {
            int idx = profit_weight_ratio[i].second;
            if(weight[idx] <= max){
                result[idx] = 1;
                max -= weight[idx];
            }
            else{
                result[idx] = max / weight[idx];
                break;
            }
        }
        return result;
    }

    void PrintMatrix() {
        cout << "Profit: ";
        for(int i = 0; i < profit.size(); i++) {
            cout << profit[i] << " ";
        }
        cout << endl;

        cout << "Weights: ";
        for(int i = 0; i < weights.size(); i++) {
            cout << weights[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Solution S;
    int max_val = 100;

    S.Generate(S.profit);
    S.Generate(S.weights);
    S.PrintMatrix();

    vector<float> outputs = S.KnapSack(S.weights, S.profit, max_val);

    cout << "Result vector: ";
    for(int k = 0; k < outputs.size(); k++){
        cout << outputs[k] << " ";
    }

    cout << endl;

    return 0;
}
