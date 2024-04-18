#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

class obj
{
public:
    float profit;
    float weight;
    float profitByWeight;

    obj(float profit, float weight)
    {
        this->profit = profit;
        this->weight = weight;
        this->profitByWeight = (profit / weight);
    }
};

bool cmpProfit(obj a, obj b)
{
    return b.profit < a.profit;
}

bool cmpWeight(obj a, obj b)
{
    return b.weight > a.weight;
}

bool cmpProfitbyWeight(obj a, obj b)
{
    return b.profitByWeight < a.profitByWeight;
}

void greedyKnapsack(vector<obj> &objList, int maxWeight)
{
    sort(objList.begin(), objList.end(), cmpProfitbyWeight);
    float profit = 0;

    for (int i = 0; i < objList.size(); i++)
    {
        if (maxWeight >= objList[i].weight)
        {
            profit += objList[i].profit;
            maxWeight -= objList[i].weight;
        }
        else
        {
            profit += (maxWeight / objList[i].weight) * objList[i].profit;
            break;
        }
    }
    cout << "Maximum profit earned is " << setprecision(3) << fixed << profit << endl;
}

int main()
{
    vector<obj> objList = {obj(10, 2), obj(5, 3), obj(15, 5), obj(7, 7), obj(6, 1), obj(18, 4), obj(3, 1)};
    int maxWeight = 15;

    greedyKnapsack(objList, maxWeight);

    return 0;
}