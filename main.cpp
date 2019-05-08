#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <fstream>
#include <mutex>
#include <unordered_map>

#include "myStringManipulation.h"

using namespace std;

vector<string> myFilenames;
unordered_map<string, int> myDictionary;
mutex mtx;

void readFile(string filename) {
    string line;
    fstream myFile (filename);
    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            for (const string& str : splitStringToArray(line)) {
                if (str == "") continue;
                string tempKey = filename + "___" + str;
                mtx.lock();
                if (!myDictionary.count(tempKey)) myDictionary[tempKey] = 1;
                else {
                    int temp = myDictionary[tempKey] + 1;
                    if (tempKey == "file1___fuck"){
                        cout << endl;
                    }
                    myDictionary[tempKey] = temp;
                }
                mtx.unlock();
            }
        }
    } else {
        cout << "No such file" << endl;
    }
}

int main(int argc, char** argv) {
    string filename;
    cout << "Please enter filename \nof the first file:" << endl;
    cin >> filename;
    myFilenames.push_back(filename);
    cout << "of the second file:" << endl;
    cin >> filename;
    myFilenames.push_back(filename);

 
    thread firstThread (readFile , myFilenames.at(myFilenames.size() - 1));
    myFilenames.pop_back();
    thread secondThread (readFile , myFilenames.at(myFilenames.size() - 1));
    myFilenames.pop_back();
    
    firstThread.join();
    secondThread.join();
    
    
    //thread finalThread ();
    for (auto const& x : myDictionary) {
        cout << x.first  // string (key)
                  << ':' 
                  << x.second // string's value 
                  << endl ;
    }
    cout << "i am here " << filename << endl;
    return 0;
}

