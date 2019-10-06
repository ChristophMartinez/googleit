#include "abstraction.h"
#include "porterStemm.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>


using namespace std;


int main()
{
    file docObj;
    portStemm absObj;
    int docNum = 0;


    docObj.readIn(docObj); //read in raw doc
    docObj.outputFile(docObj, docNum); //output raw doc
    docObj.readInStop(docObj); //read in stopwords doc
    docObj.findPunc(docObj); //search for puncs
    docObj.delStop(docObj); //deletes stop words
//    absObj.storemVal(docObj, absObj);
//    absObj.getmValue(docObj, absObj);
    absObj.algo1A(docObj, absObj);
    absObj.algo1B(docObj, absObj);
    absObj.algo1C(docObj, absObj);
    absObj.algo2(docObj, absObj);

    docObj.outputFile(docObj, docNum);

/*
//masons shit below 

    docObj.readIn(docObj);
    docObj.outputFile(docObj, 0);
	docObj.readInStop(docObj);
	docObj.findPunc(docObj);
	docObj.delStop(docObj);
	docObj.outputFile(docObj, 0);
	calcObj.TfIdf(calcObj, docObj, 0);
*/

	return 0;
}

