#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cfloat>
using namespace std;

struct Point {
    int x, y;
};

bool compareX(const Point& a, const Point& b) {
    return a.x < b.x;
}

bool compareY(const Point& a, const Point& b) {
    return a.y < b.y;
}

float dist(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float bruteForce(const vector<Point>& points, int n) {
    float minDist = FLT_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            minDist = min(minDist, dist(points[i], points[j]));
        }
    }
    return minDist;
}

float closestUtil(vector<Point>& strip, float d) {
    float minDist = d;
    sort(strip.begin(), strip.end(), compareY);
    for (size_t i = 0; i < strip.size(); ++i) {
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; ++j) {
            minDist = min(minDist, dist(strip[i], strip[j]));
        }
    }
    return minDist;
}

float closestPairUtil(vector<Point>& points, int n) {
    if (n <= 3) {
        return bruteForce(points, n);
    }

    int mid = n / 2;
    Point midPoint = points[mid];

    vector<Point> left(points.begin(), points.begin() + mid);
    vector<Point> right(points.begin() + mid, points.end());

    float dl = closestPairUtil(left, mid);
    float dr = closestPairUtil(right, n - mid);

    float d = min(dl, dr);

    vector<Point> strip;
    for (int i = 0; i < n; ++i) {
        if (abs(points[i].x - midPoint.x) < d) {
            strip.push_back(points[i]);
        }
    }

    return min(d, closestUtil(strip, d));
}

float closestPair(vector<Point>& points) {
    sort(points.begin(), points.end(), compareX);
    return closestPairUtil(points, points.size());
}

int main() {
    vector<Point> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    float closestDistance = closestPair(points);
    cout << "The smallest distance is: " << closestDistance << endl;

    return 0;
}
