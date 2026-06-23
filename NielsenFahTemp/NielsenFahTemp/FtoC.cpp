/*
    Developer: Michael Nielsen
    Date: May 2026

    Purpose: Read a list of cities and their average yearly temps in Fahrenheit,
             convert them to Celsius, and write the results to a new file.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    // File names
    string inputFileName = "FahrenheitTemperature.txt";
    string outputFileName = "CelsiusTemperature.txt";

    // Open the input file
    ifstream inputFile(inputFileName);

    if (!inputFile.is_open()) {
        cout << "file didn't open. Check the name or location." << endl;
        return 1;
    }

    // Converted temps will go.
    ofstream outputFile(outputFileName);

    if (!outputFile.is_open()) {
        cout << "Output file refused to open." << endl;
        return 1;
    }

    string city;
    int tempF;

    // Read each city + F temp
    while (inputFile >> city >> tempF) {

        // Convert F to C
        double tempC = (tempF - 32) * 5.0 / 9.0;

        // City and its C temp to the new file
        outputFile << city << " " << tempC << endl;
    }

    // Close both files
    inputFile.close();
    outputFile.close();

    cout << "Conversion complete" << outputFileName
        << " to see the Celsius results." << endl;

    return 0;
}
