#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int activitySelection(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compare);

    int count = 1;
    int prevFinish = activities[0].finish;

    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= prevFinish) {
            count++;
            prevFinish = activities[i].finish;
        }
    }

    return count;
}

int main() {
    vector<Activity> activities = {{10, 20}, {12, 25}, {20, 30}};

    int maxActivities = activitySelection(activities);

    cout << "Maximum number of activities: " << maxActivities << endl;

    return 0;
}
