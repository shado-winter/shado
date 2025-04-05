#include <iostream>      
#include <fstream>      
#include <vector>       
#include <iomanip>       
#include <algorithm>     

using namespace std;     

int main() {
    
    ifstream inFile("numdata.txt");  // create an input file stream to read from "numdata.txt"
    if (!inFile) {                   // check if the file couldn't be opened
        cerr << "Error opening input file.\n"; 
        return 1;                   
    }

    vector<double> data;  // declare a vector to store all the double values from the file
    double value;         

    // Read all values from the file into the vector
    while (inFile >> value) {  
        data.push_back(value);
    }
    inFile.close();  

    // Sort the values in ascending order (smallest to largest)
    sort(data.begin(), data.end()); 

    // Open the output file to write the sorted values
    ofstream sortedFile("sorted.txt"); 
    if (!sortedFile) {                 
        cerr << "Error opening sorted output file.\n";
        return 1;                    
    }

    // Write each sorted value to the file with 2 decimal places
    for (double num : data) {                        
        sortedFile << fixed << setprecision(2) << num << endl;
    }
    sortedFile.close(); 

    // Create a histogram: 10 bins for ranges 0-10, 10-20, ..., 90-100
    const int BIN_COUNT = 10;   
    int histogram[BIN_COUNT] = { 0 };

    // Count how many numbers fall into each bin
    for (double num : data) {            
        if (num >= 0.0 && num < 100.0) { 
            int binIndex = static_cast<int>(num) / 10; 
            histogram[binIndex]++;       // increase the count for the correct bin
        }
    }

    // Open the histogram output file
    ofstream histFile("histogram.txt"); 
    if (!histFile) {                 
        cerr << "Error opening histogram output file.\n";
        return 1;                        
    }

    // Write the histogram header
    histFile << "Bin       Number of Values\n"; 

    // Write each bin range and the number of values in that range
    for (int i = 0; i < BIN_COUNT; ++i) {      // loop from bin 0 to 9
        int lower = i * 10;                   
        int upper = lower + 10;                
        histFile << setw(2) << lower << "-" << setw(3) << upper  // print bin label
            << "     " << histogram[i] << endl;             // print count for that bin
    }

    histFile.close();  // close the histogram output file

    cout << "Program completed. Output written to 'sorted.txt' and 'histogram.txt'.\n";

    return 0; 
}
