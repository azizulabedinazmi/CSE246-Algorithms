#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int profit;
    int weight;
};

bool compare(Item a, Item b) {
    double ratio1 = (double)a.profit / a.weight;
    double ratio2 = (double)b.profit / b.weight;
    return ratio1 > ratio2;
}

double fractionalKnapsack(vector<Item>& items, int W) {
    sort(items.begin(), items.end(), compare);

    double totalProfit = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < items.size(); i++) {
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            totalProfit += items[i].profit;
        } else {
            int remainingWeight = W - currentWeight;
            totalProfit += items[i].profit * ((double)remainingWeight / items[i].weight);
            break;
        }
    }

    return totalProfit;
}

int main() {
    vector<Item> items;
    int numItems;
    int W;

    cout << "Enter the number of items: ";
    cin >> numItems;

    cout << "Enter the profit and weight for each item:" << endl;
    for (int i = 0; i < numItems; i++) {
        Item item;
        cout << "Item " << i + 1 << ":" << endl;
        cout << "Profit: ";
        cin >> item.profit;
        cout << "Weight: ";
        cin >> item.weight;
        items.push_back(item);
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    double maxProfit = fractionalKnapsack(items, W);

    cout << "Maximum total profit in the knapsack: " << maxProfit << endl;

    return 0;
}
