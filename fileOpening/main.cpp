#include<bits/stdc++.h>
using namespace std;
int main()
{
    fstream fout;
    fout.open("fullnames.txt", ios::out); // // open a file to perform write operation using file object

    if (newfile.is_open())   //if statement will check whether file is open or not
    {
        // inserting the text into the file

        fout<<"Marlon Brando\n"<<"Clark Gable\n"<<"Jack Nicholson\n"<<"Humphrey Bogart\n"<<"Sidney Poitier\n";
        fout<<"Gregory Smith Peck\n"<<"Cary Grant\n"<<"Viola Ann Davis\n"<<"Forest Whitaker";

        fout.close(); // closing the file
    }


    fstream readOnly;
    readOnly.open("fullnames.txt", ios::in);  //open a file to perform read operation using file object

    string line; // it will store the each line of the file during particular iteration of loop
    int count = 0; // it will store the number of words in the file


    if (readOnly.is_open()){      // if statement will check whether file is open or not
        while(getline(readOnly, line)){

            stringstream iss(line); // for extracting the words from each line of the files

            string word; // it will store the each word of that particular line
            while(iss>>word)
            {
                cout<<word<<"\n";
                count++;
            }
        }
        cout<<count;
    readOnly.close(); //for closing the file
    }
}
