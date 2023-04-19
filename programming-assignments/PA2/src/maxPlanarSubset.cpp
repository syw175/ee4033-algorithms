#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    // Ensure that the correct number of arguments are given
    if (argc != 3)
    {
        cout << "Usage: ./mps <input_filename> <output_filename>" << endl;
        return 1;
    }

    // Open the input file and check that it opened correctly
    ifstream input(argv[1]);
    if (!input.is_open())
    {
        cout << "Error: Could not open input file" << endl;
        return 1;
    }

    // Declare our variables for calculating the maximal planar set
    int vecticeCount = 0;
    vector<int> chords;
    vector<vector<int> > matrices;
    vector<bool> maxChords;

    // Input file contains an integer 2n, followed by n lines, 
    // each containing 2 integers denoting two endpoints of an chord
    // A single '0' denotes the end of the input




    // Close the input file
    input.close();
    return 0;
}
