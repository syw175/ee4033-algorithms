#include <iostream>
#include <set>
#include <fstream>
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

    // Input file contains an integer 2n, followed by n lines, 
    // each containing 2 integers denoting two endpoints of an chord
    // A single '0' denotes the end of the input

    // Read in the number of chords
    int n;
    input >> n;
    vector<pair<int, int> > chords;

    // While there are still chords to read in
    for (int i = 0; i < n; i++)
    {
        int x, y;
        input >> x >> y;
        chords.push_back(make_pair(x, y));
    }

    // Print out the chords
    cout << "Chords:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << chords[i].first << " " << chords[i].second << endl;
    }

    // Assumption: No chords of C share an endpoint, let M(i,j) , i <= j denote the number of non-overlapped chords in the maximum planar
    // subset in the region formed by chord ij and the arc between endpoints i and j
    //
    // Compute M(0, 2n-1) and report the subset sorted by the first endpont in ascending order


    // Note to self: Selection of planar subset given by formula (nCk)/n!nCk
    // Ie we havethe rleation shi

    // Close the input file
    input.close();
    return 0;
}
