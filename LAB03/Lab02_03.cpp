#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findPlatforms(vector<float>& arrival, vector<float>& departure) {
    int n = arrival.size();
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int platforms = 1, count = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arrival[i] <= departure[j]) {
            count++;
            i++;
        } else {
            count--;
            j++;
        }

        if (count > platforms) {
            platforms = count;
        }
    }

    return platforms;
}

int main() {
    int n;
    cout << "Enter the number of train schedules: ";
    cin >> n;

    vector<float> arrival(n), departure(n);

    cout << "Enter the arrival times:\n";
    for (int i = 0; i < n; i++) {
        cin >> arrival[i];
    }

    cout << "Enter the departure times:\n";
    for (int i = 0; i < n; i++) {
        cin >> departure[i];
    }

    int minPlatforms = findPlatforms(arrival, departure);

    cout << "Minimum number of platforms needed: " << minPlatforms << endl;

    return 0;
}
