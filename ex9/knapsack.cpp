#include <iostream>
using namespace std;

struct Item {
    int id; // To track original position after sorting
    int weight;
    int value;
};

int n, capacity, maxProfit = 0;
Item items[100];
bool currentSelected[100], bestSelected[100];

// Bounding function
float getBound(int i, int currentWeight, int currentProfit) {
    if (currentWeight >= capacity) return 0;
    float bound = (float)currentProfit;
    int totalWeight = currentWeight;
    while (i < n && totalWeight + items[i].weight <= capacity) {
        totalWeight += items[i].weight;
        bound += items[i].value;
        i++;
    }
    if (i < n)
        bound += (float)(capacity - totalWeight) * items[i].value / items[i].weight;
    return bound;
}

void solve(int i, int currentWeight, int currentProfit) {
    // Update global maximum and save the state of items
    if (currentWeight <= capacity && currentProfit > maxProfit) {
        maxProfit = currentProfit;
        for (int k = 0; k < n; k++) bestSelected[k] = currentSelected[k];
    }

    if (i == n) return;

    // Pruning check
    if (getBound(i, currentWeight, currentProfit) > maxProfit) {
        // 1. Include current item
        if (currentWeight + items[i].weight <= capacity) {
            currentSelected[i] = true;
            solve(i + 1, currentWeight + items[i].weight, currentProfit + items[i].value);
            currentSelected[i] = false; // Backtrack
        }

        // 2. Exclude current item
        solve(i + 1, currentWeight, currentProfit);
    }
}

int main() {
    cout << "Enter number of items and capacity: ";
    cin >> n >> capacity;

    for (int i = 0; i < n; i++) {
        items[i].id = i + 1; // Item label 1, 2, 3...
        cout << "Item " << i + 1 << " (Value Weight): ";
        cin >> items[i].value >> items[i].weight;
    }

    // Sort items by value/weight ratio (Simple Bubble Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((double)items[j].value / items[j].weight < (double)items[j + 1].value / items[j + 1].weight) {
                swap(items[j], items[j + 1]);
            }
        }
    }

    solve(0, 0, 0);

    cout << "\nMaximum Profit: " << maxProfit << endl;
    cout << "Items Selected (IDs): ";
    for (int i = 0; i < n; i++) {
        if (bestSelected[i]) cout << items[i].id << " ";
    }
    cout << endl;

    return 0;
}
