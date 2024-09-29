//
// Created by Stowe Danger on 9/30/24.
//
#include <iostream>
#include <string>
#include <regex>  // For regular expressions
using namespace std;
struct AccelerationInfo {
    double acceleration;
    bool isConstant;
};

// Function to extract acceleration value and check if it's constant
AccelerationInfo extractAcceleration(const string& problem) {
    // Regex to find the term "acceleration" or "constant acceleration" followed by a number
    regex accelerationRegex(R"(\b(constant\s)?acceleration\b.*?(\d+\.?\d*)\s*(m/s\^2|mi/h\^2))");
    smatch match;
    AccelerationInfo accelInfo = {0.0, false};// Initialize with default values

    if (regex_search(problem, match, accelerationRegex)) {
        // Extract the number as a double
        accelInfo.acceleration = stod(match[2].str());

        // Check if "constant" is in the match (first capture group)
        accelInfo.isConstant = (match[1].matched);
    } else {
        cout << "Acceleration not found in the problem." << endl;
    }

    return accelInfo;
}

double extractIntialVelocity(const string& problem) {
    // Regex to find the term "initial velocity" followed by a number
    regex initialVelocityRegex(R"(\binitial velocity\b.*?(\d+\.?\d*)\s*(mi/h|m/s|m/s\^2|mi))");
    smatch match;

    if (regex_search(problem, match, initialVelocityRegex)) {
        // Extract the number as a double
        double initialVelocity = stod(match[1].str());
        //cout << "Initial Velocity: " << initialVelocity << " " << match[2].str() << endl;
        return initialVelocity;
    }else {

        return 0.0;
    }

}

void lookthrough( const string & problem) {
    double distance = 0.0, vi = 0.0, vf = 0.0;

    // Extract acceleration outside the loop
    AccelerationInfo acceleration = extractAcceleration(problem);  // Initialize acceleration struct

    regex number_with_unit(R"((\d+\.?\d*)\s*(mi/h|m/s|m/s\^2|mi))");
    smatch match;
    string::const_iterator search_start(problem.cbegin());
    while (regex_search(search_start, problem.cend(), match, number_with_unit)) {
        double value = stod(match[1]);  // Convert the captured number to double
        string unit = match[2];// Extract the unit

        if (unit == "m"||unit == "ft"||unit == "yd" || unit == "mi") {
            distance = value;
        }else if (vi == 0.0){
            vi = extractIntialVelocity(problem);
        } else if (unit == "mi/h" || unit =="m/s") {
                vf = value;
        }

        search_start = match.suffix().first;  // Move past the last match
    }
    // Output the extracted values
    cout << "Distance: " << distance << " mi" << endl;
    cout << "Initial Velocity (vi): " << vi << " mi/h" << endl;
    cout << "Final Velocity (vf): " << vf << " mi/h" << endl;
    cout << "Acceleration: " << acceleration.acceleration << " m/s^2" << endl;
    cout << "Is acceleration constant? " << (acceleration.isConstant ? "Yes" : "No") << endl;
}

int main() {
    string physicsProblem = "A car travels a distance of 100 mi with an initial velocity of 20 mi/h and accelerates to a final velocity of 60 mi/h The acceleration was 2.5 m/s^2.";
    lookthrough(physicsProblem);
    return 0;
}


