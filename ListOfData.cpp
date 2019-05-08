#include <iostream>
#include <string>
#include "ListOfData.h"

using namespace std;

class ListData{
private:
    int data;
    string word;
    int occFile1;
    int occFile2;
public:
    
    ListData(int data, string word, int occFile1, int occFile2){
        addNode(data, word, occFile1, occFile2);
    }
    
    void addNode(int data, string word, int occFile1, int occFile2){
        this->data = data;
        this->word = word;
        this->occFile1 = occFile1;
        this->occFile2 = occFile2;
    }
    
    
};
