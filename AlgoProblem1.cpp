#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Function for calculating distance over point N to another point N
double calculate_distance(pair<int, int> x1, pair<int, int> x2) {
    double distance = sqrt(pow(x2.first - x1.first, 2) + pow(x2.second - x1.second, 2));
    return distance;
}

// Function for calculating the sum of the first N natural numbers
int sum_of_natural_numbers(int N) {
    return (N * (N + 1)) / 2;
}

int main() {
    int N;
    cout << "Enter the number of delivery points: ";
    cin >> N;

    vector<pair<int, int>> points;

    // User input for the coordinates of the delivery points
    cout << "Enter the coordinates of the delivery points: For example (32 38)." << endl;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }

    // Finding the total distance traveled between delivery points
    double total_distance = 0;
    for (int i = 0; i < N - 1; i++) {
        total_distance += calculate_distance(points[i], points[i + 1]);
    }

    // finding the sum of the first N natural numbers
    int sum_natural_numbers = sum_of_natural_numbers(N);

    // Print the total distance between delivery points and the sum of the first N natural numbers
    cout << "Total distance traveled: " << total_distance << endl;
    cout << "Sum of the first " << N << " natural numbers: " << sum_natural_numbers << endl;

    return 0;
}
