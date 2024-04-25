#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Define the structure for an ambulance
struct Ambulance {
    int id;
    double x;
    double y;
    bool available;
    int urgency;
};

// Define the structure for an emergency call
struct EmergencyCall {
    int id;
    double x;
    double y;
    int urgency;
};

// Function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

// Function to find the optimal assignment of emergency calls to ambulances using dynamic programming
double optimalAssignment(struct Ambulance *ambulances, int numAmbulances, struct EmergencyCall *calls, int numCalls) {
    // Create a 2D table to store intermediate results
    double dp[numCalls + 1][numAmbulances + 1];

    // Initialize the table
    for (int i = 0; i <= numCalls; i++) {
        for (int j = 0; j <= numAmbulances; j++) {
            dp[i][j] = 0;
        }
    }

    // Fill in the table using dynamic programming
    for (int i = 1; i <= numCalls; i++) {
        for (int j = 1; j <= numAmbulances; j++) {
            double minResponseTime = INFINITY;

            for (int k = 1; k <= j; k++) {
                double responseTime = dp[i - 1][j - k] +
                    distance(ambulances[j - k].x, ambulances[j - k].y, calls[i - 1].x, calls[i - 1].y) /
                    calls[i - 1].urgency;

                if (responseTime < minResponseTime) {
                    minResponseTime = responseTime;
                }
            }

            dp[i][j] = minResponseTime;
        }
    }

    // The final result is in dp[numCalls][numAmbulances]
    return dp[numCalls][numAmbulances];
}

int main() {
    int numAmbulances = 3;
    struct Ambulance ambulances[numAmbulances];

    // Initialize ambulance locations, availability, and urgency
    // (as in the previous code)

    int numCalls = 5;
    struct EmergencyCall calls[numCalls];

    // Initialize emergency calls with urgency and locations
    // (as in the previous code)

    double totalResponseTime = optimalAssignment(ambulances, numAmbulances, calls, numCalls);

    printf("Total response time: %.2lf\n", totalResponseTime);

    return 0;
}