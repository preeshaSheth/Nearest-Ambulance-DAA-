# Nearest-Ambulance-DAA
Scenario:
Imagine a city with a fleet of ambulances stationed at various locations.
Emergency calls are received from different locations within the city.
Objective:
The main goal is to assign these emergency calls to available ambulances in a way that minimizes the total time it takes for ambulances to reach their respective destinations.
This involves considering both the urgency of each emergency call and the distance between the ambulance and the call location.
Key Components:
Ambulances: Each ambulance has:
An ID to identify it uniquely.
Current coordinates (x, y) representing its location within the city.
Availability status indicating whether it is free or currently attending to another call.
Urgency level representing its response priority.
Emergency Calls: Each emergency call has:
An ID to identify it uniquely.
Coordinates (x, y) representing the location from which the call originated.
Urgency level indicating the severity of the situation.
Approach:
The code employs dynamic programming to find the optimal assignment of emergency calls to available ambulances.
It calculates the response time for each possible assignment, considering the distance between the ambulance and the call location, as well as the urgency of the call.
The objective is to minimize the total response time across all assignments.
The algorithm ensures that each ambulance can handle multiple calls if needed, but it also considers the availability of ambulances when making assignments.
Output:
The program outputs the total response time, which represents the sum of response times for all emergency calls assigned to the available ambulances in the optimal manner.
