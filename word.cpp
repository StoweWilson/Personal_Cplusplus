#include <iostream>
#include <string>
#include <regex>  // For regular expressions
using namespace std;

struct AccelerationInfo {
    double acceleration;
    bool isConstant;
    string unit;
};

// Function to extract acceleration value and check if it's constant
AccelerationInfo extractAcceleration(const string& problem) {
    // Regex to find "constant acceleration" or "acceleration" followed by a number
    regex accelerationRegex(R"(\b(?:constant\s)?acceleration\b.*?(\d+\.?\d*)\s*(m/s\^2|mi/h))");
    regex gravityRegex(R"(\b(gravitational acceleration|gravity)\b.*?(\d+\.?\d*)\s*(m/s\^2))");

    smatch match;
    AccelerationInfo accelInfo = {0, false,""}; // Initialize with default values

    // Check for gravitational acceleration
    if (regex_search(problem, match, gravityRegex)) {
        accelInfo.acceleration = stod(match[2].str());
        accelInfo.unit = match[3].str();  // Store the unit (e.g., m/s²)
        accelInfo.isConstant = true;
    }
    // Check if "gravitational acceleration" is present
    else if (regex_search(problem, match, accelerationRegex)) {
        accelInfo.acceleration = stod(match[1].str());
        accelInfo.unit = match[2].str();
        accelInfo.isConstant = match[1].matched;  // Check if it's constant
    } else {
        cout << "Acceleration not found in the problem." << endl;
    }

    return accelInfo;
}

struct ExtractedValue {
    double value;
    string unit;
};

struct DistanceInfo {
    double distance;
    string unit;
};

DistanceInfo extractDistance(const string& problem) {
    regex distanceRegex(R"(\b(distance|displacement|height|falls from a height of|falls)\b.*?(\d+\.?\d*)\s*(m|meters|ft|yd|mi))");
    smatch match;
    DistanceInfo distanceInfo = {0.0,""};

    if (regex_search(problem, match, distanceRegex)) {
        distanceInfo.distance = stod(match[2].str());
        distanceInfo.unit = match[3].str();  // Store unit (e.g., mi)
    }
    return distanceInfo;
}

ExtractedValue extractFinalVelocity(const string& problem) {
    regex finalVelocityRegex(R"(\b(final velocity|final)\b.*?(\d+\.?\d*)\s*(mi/h|m/s|km/h))");
    smatch match;
    ExtractedValue finalVelocity = {0.0, ""};

    if (regex_search(problem, match, finalVelocityRegex)) {
        finalVelocity.value = stod(match[2].str());
        finalVelocity.unit = match[3].str();
    }
    return finalVelocity;
}

ExtractedValue extractInitialVelocity(const string& problem) {
    regex initialVelocityRegex(R"(\binitial velocity\b.*?(\d+\.?\d*)\s*(mi/h|m/s|km/h))");
    smatch match;
    ExtractedValue initialVelocity = {0.0, ""};

    if (regex_search(problem, match, initialVelocityRegex)) {
        initialVelocity.value = stod(match[1].str());
        initialVelocity.unit = match[2].str();  // Store unit (e.g., mi/h)
    }

    return initialVelocity;
}

ExtractedValue extractGravity(const string& problem) {
    regex gravityRegex(R"(\b(gravitational acceleration|gravity)\b.*?(\d+\.?\d*)\s*(m/s\^2))");
    smatch match;
    ExtractedValue gravity = {0.0, ""};

    if (regex_search(problem, match, gravityRegex)) {
        gravity.value = stod(match[2].str());
        gravity.unit = match[3].str();
    } else {
        gravity.value = 9.8;  // Default gravitational acceleration
        gravity.unit = "m/s^2";
    }
    return gravity;
}

void lookthrough(const string & problem) {
    DistanceInfo distance = extractDistance(problem);
    ExtractedValue vi = extractInitialVelocity(problem);
    ExtractedValue vf = extractFinalVelocity(problem);
    ExtractedValue gravity = extractGravity(problem);

    AccelerationInfo acceleration = extractAcceleration(problem);

    // Output the extracted values with units
    cout << "Distance: " << distance.distance << " " << distance.unit << endl;
    cout << "Initial Velocity (vi): " << vi.value << " " << vi.unit << endl;
    cout << "Final Velocity (vf): " << vf.value << " " << vf.unit << endl;
    cout << "Acceleration: " << acceleration.acceleration << " " << acceleration.unit << endl;
    cout << "Is acceleration constant? " << (acceleration.isConstant ? "Yes" : "No") << endl;
    cout << "Gravitational Acceleration: " << gravity.value << " " << gravity.unit << endl;
}

int main() {
    string physicsProblem;
    cout << "Please enter your physics problem: ";
    getline(cin, physicsProblem);
    lookthrough(physicsProblem);
    return 0;
}