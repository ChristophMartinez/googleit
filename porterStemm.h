#ifndef PORTERSTEMM_H
#define PORTERSTEMM_H
#include "abstraction.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

class portStemm
{
    private:
        int mVals;
        vector < vector<string> > abstractList;
        vector < vector<int> > mvals;
 //     bool vowelinstem(string c);

    public:

//      vector <file> abstractList(vector < vector<string> > &abstractList); //here goes nothing
//        void storemVal(file& docObj, portStemm& absObj);
        int getmValue(string test); //getting that mval yo 
        bool isVowel(char c);
//algos from the paper that Helsing gave us
        void algo1A(file& docObj, portStemm& absObj);
        void algo1B(file& docObj, portStemm& absObj);
        void algo1C(file& docObj, portStemm& absObj);    
        void algo2(file& docObj, portStemm& absObj);
        

/*
        string algo3(vector < vector<string> > &abstractList);
        string algo4(vector < vector<string> > &abstractList);
        string algo5A(vector < vector<string> > &abstractList);
        string algo5B(vector < vector<string> > &abstractList);

        string poters(string initial);
*/
};

#endif
