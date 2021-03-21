// This is the simple c++ program for following problem.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x = -1; // for handing the exception
    ofstream fout; // creation of ofstream class object for opening the file
    fout.open("DieRolls.txt"); // it will open out text file 'DieRolls.txt'
    // before going to program make sure there is a text file name 'DieRolls.txt' in you current directory.
    try
    {
        // if block will check whether file exist or not
        if(!fout){
            throw x; // if file is not there it will throw a exception
        }
    }
    catch(int x)
    {
        cout<<"File not there";
        return 0;
    }
    int RollingOne = 0; // for counting ones
    int RollingTwo = 0; // for counting twos
    int RollingThree = 0; // for counting threes
    int RollingFour = 0; // for counting fours
    int RollingFive = 0; // for counting fives
    int RollingSix = 0;  // for counting sixes

    // the srand() function creates new and different sequence of the random number every time
    // whenever you run the program
    srand(time(0));
    for(int i=1; i<=10000; i++)
    {
        int DieNumber = rand()%6 +1; // it will generate random number between 1 to 6
        switch(DieNumber)
        {
        case 1:
            RollingOne++;
            break;
        case 2:
            RollingTwo++;
            break;
        case 3:
            RollingThree++;
            break;
        case 4:
            RollingFour++;
            break;
        case 5:
            RollingFive++;
            break;
        case 6:
            RollingSix++;
            break;
        }
    }
    double onePercent = (RollingOne/100.0); // calculate ones percentage
    double twoPercent = (RollingTwo/100.0);  // calculate twos percentage
    double trheePercent = (RollingThree/100.0);  // calculate threes percentage
    double fourPercent = (RollingFour/100.0);  // calculate fours percentage
    double fivePercent = (RollingFive/100.0);  // calculate fives percentage
    double sixPercent = (RollingSix/100.0);  // calculate sixes percentage

    fout<<"The number of ones rolled was "<<RollingOne<<". The percentage of ones rolled was "<<onePercent<<"%.\n";
    fout<<"The number of twos rolled was "<<RollingTwo<<". The percentage of ones rolled was "<<twoPercent<<"%.\n";
    fout<<"The number of threes rolled was "<<RollingThree<<". The percentage of ones rolled was "<<trheePercent<<"%.\n";
    fout<<"The number of fours rolled was "<<RollingFour<<". The percentage of ones rolled was "<<fourPercent<<"%.\n";
    fout<<"The number of fives rolled was "<<RollingFive<<". The percentage of ones rolled was "<<fivePercent<<"%.\n";
    fout<<"The number of sixes rolled was "<<RollingSix<<". The percentage of ones rolled was "<<sixPercent<<"%.\n";


    fout.close(); // for closing the file
    return 0;
}
