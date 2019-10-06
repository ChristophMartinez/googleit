#ifndef ABSTRACTION_H
#define ABSTRACTION_H
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

class file
{
    private:
        vector <vector <string> > abstractList;
        //vector <pair <string, int>> abstractList2;

        //vector <string> absObj; //vec of abstact objects 

        vector <string> stopWordList; //vec to store stopWords file 

	    vector <string> IDs; //vec for IDs
	    vector <string> authors; //vec for authors
	    vector <string> titles; //vec for titles 
	
    public:
 //       file(); //default contructor because...

        vector < vector<string> > getAbstractList() {return abstractList;}
        void setAbstractList(vector < vector<string> > stemmList);

//        void storeFile(file& docObj); //store all elements of file
        void readIn(file& docObj); //read in file

        void outputFile(file docObj, int docNum);//output first document information

	    void readInStop(file& docObj); //read in stop word file

        void findPunc(file& docObj); //searches for punc fool 

        void delStop(file& docObj); //removes punctuation and whitespace
};
#endif 