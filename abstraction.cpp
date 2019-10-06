#include "abstraction.h"
#include "porterStemm.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

//define functions

void file::readIn(file& docObj)//read in file 
{
	ifstream instream; //input
	ofstream outstream; //output

    	cout << "Enter name of file: ";
    	string fileName;
    	cin >> fileName;

    	int fileCheck = 0;
    	instream.open(fileName);

    	while(fileCheck != 0)
    	{
        	if(!instream.is_open())
        	{
        	    fileCheck = 1;
        	    cout << "could not open file." << endl;
        	    cout << "Enter name of file: ";
        	    cin >> fileName;
        	    //return fileCheck;
        	}
        	instream.open(fileName);
    	}

    string a; //check if ID, title, author, abstract
    vector<string> temp;
    instream >> a;

        while(!instream.eof())
        {
			instream >> a;
			docObj.IDs.push_back(a);
			instream.ignore();
			instream >> a;
              
			if(a == ".T")
            {
				getline(instream, a);
				docObj.titles.push_back(a);
				getline(instream, a);

				while(a != ".A")
				{
					docObj.titles[docObj.titles.size()-1].append(a);
					getline(instream, a);
				}
			}

			if(a == ".A")
			{
				getline(instream, a);
				docObj.authors.push_back(a);
				getline(instream, a);

				while(a != ".W")
				{
						docObj.authors[docObj.authors.size()-1].append(a);
						getline(instream, a);
				}
			}
			if(a == ".W")
			{
				instream >> a;
				temp.push_back(a);
				docObj.abstractList.push_back(temp);
	
				while(!instream.eof() && (a != ".I"))
				{
						if(a != "\n")
						{
								docObj.abstractList[docObj.abstractList.size()-1].push_back(a);
						}
						instream >> a;
				}
				docObj.abstractList.at(docObj.abstractList.size()-1).erase(docObj.abstractList.at((docObj.abstractList.size()-1)).begin());
			}
		}
}

void file::outputFile(file docObj, int docNum) 
{
	int idSize = docObj.IDs.size();
	int authorSize = docObj.authors.size();
	int titleSize = docObj.titles.size();
	int abstractSize = docObj.abstractList.size();

	if(idSize != 0 && authorSize != 0 && titleSize != 0 && abstractSize != 0)
	{
		cout << "~~~Document 1~~~" << endl;
		cout << "ID: " << docObj.IDs.at(docNum) << endl;
		cout << "Title: " << docObj.titles.at(docNum) << endl;
		cout << "Author: " << docObj.authors.at(docNum) << endl;

		for(int i = 0; i < docObj.abstractList.at(docNum).size(); i++)
		{
			cout << docObj.abstractList.at(docNum).at(i) << " ";
		}
		cout << endl;
	}
}


void file::readInStop(file& docObj)
{
	ifstream inStop;
	string stopFileName;
	string a;
	int count = 0;
	while(!inStop.is_open())
	{	
		cout << "Enter name of the file containing the stop words: ";
	    	cin >> stopFileName;
		inStop.open(stopFileName.c_str());
	}

	while(!inStop.eof())
	{
		getline(inStop, a);
		docObj.stopWordList.push_back(a);
		count ++;
	}
	cout << "Number of stop words in list: " << count << endl;

	inStop.close();
}

void file::findPunc(file& docObj)
{
	string findS = "'s";
	string questionMark = "?";
	string bang = "!";
	string period = ".";
	string comma = ",";
	string backSlash = "/";
	string colon = ":";
	string semiColon = ";";
	string percent = "%";
	string astriks = "*";
	string ambersand = " - ";
	string hash = "#";
	string parens = "(";
	string parens2 = ")"; 
	string equal = "=";
	string a;
	string b;
	string::size_type sz;


    	for(int i = 0; i < docObj.abstractList.size(); i++)
    	{
        	for(int j = 0; j < docObj.abstractList.at(i).size(); j++)
        	{
			for(int k = 0; k < 5; k++)
			{		
				if(atoi(docObj.abstractList.at(i).at(j).c_str()) != 0)
				{
					docObj.abstractList.at(i).erase(docObj.abstractList.at(i).begin()+j);
					j--;
                        	}
				if(docObj.abstractList.at(i).at(j).find("0") != string::npos)
				{
						docObj.abstractList.at(i).erase(docObj.abstractList.at(i).begin()+j);
						j--;
				}

				for(int m = 0; m < 10; m++)
				{
					b = to_string(m);
					if(docObj.abstractList.at(i).at(j).find(b) != string::npos)
					{
							docObj.abstractList.at(i).erase(docObj.abstractList.at(i).begin()+j);
							j--;
					}
				}
				if(docObj.abstractList.at(i).at(j).find(findS) != string::npos)  
				{
					docObj.abstractList.at(i).at(j).erase(docObj.abstractList.at(i).at(j).find(findS), 2);
				}
				if(docObj.abstractList.at(i).at(j).find(questionMark) != string::npos)
				{
					docObj.abstractList.at(i).erase(docObj.abstractList.at(i).begin()+j);
					j--;
				}
				if(docObj.abstractList.at(i).at(j).find(bang) != string::npos)
				{
					docObj.abstractList.at(i).erase(docObj.abstractList.at(i).begin()+j);
					j--;
				}
				if(docObj.abstractList.at(i).at(j).find(period) != string::npos)
				{
					docObj.abstractList.at(i).erase(docObj.abstractList.at(i).begin()+j);
					j--;
				}
				if(docObj.abstractList.at(i).at(j).find(comma) != string::npos)
				{
					docObj.abstractList.at(i).at(j).erase(docObj.abstractList.at(i).at(j).find(comma), 1);
				}
				if(docObj.abstractList.at(i).at(j).find(backSlash) != string::npos)
				{
					docObj.abstractList.at(i).at(j).erase(docObj.abstractList.at(i).at(j).find(backSlash), 1);
				}
				if(docObj.abstractList.at(i).at(j).find(colon) != string::npos)
				{
					docObj.abstractList.at(i).at(j).erase(docObj.abstractList.at(i).at(j).find(colon), 1);
				}
				if(docObj.abstractList.at(i).at(j).find(semiColon) != string::npos)
				{
					docObj.abstractList.at(i).at(j).erase(docObj.abstractList.at(i).at(j).find(semiColon), 1);
				}
				if(docObj.abstractList.at(i).at(j).find(percent) != string::npos)
				{
					docObj.abstractList.at(i).at(j).erase(docObj.abstractList.at(i).at(j).find(percent), 1);
				}
				if(docObj.abstractList.at(i).at(j).find(astriks) != string::npos)
				{
					docObj.abstractList.at(i).at(j).erase(docObj.abstractList.at(i).at(j).find(astriks), 1);
				}
				if(docObj.abstractList.at(i).at(j).find(ambersand) != string::npos)
				{
					docObj.abstractList.at(i).at(j).erase(docObj.abstractList.at(i).at(j).find(ambersand), 1);
				}
				if(docObj.abstractList.at(i).at(j).find(hash) != string::npos)
				{
					docObj.abstractList.at(i).at(j).erase(docObj.abstractList.at(i).at(j).find(hash, 1));
				}
				if(docObj.abstractList.at(i).at(j).find(parens) != string::npos)
				{
					docObj.abstractList.at(i).at(j).erase(docObj.abstractList.at(i).at(j).find(parens), 1);
				}
				if(docObj.abstractList.at(i).at(j).find(parens2) != string::npos)
				{
					docObj.abstractList.at(i).at(j).erase(docObj.abstractList.at(i).at(j).find(parens2), 1);
				}
				if(docObj.abstractList.at(i).at(j).find(equal) != string::npos)
                                {
                                	docObj.abstractList.at(i).erase(docObj.abstractList.at(i).begin()+j);
                                	j--;
                                }
			}
		}
	}
}

void file::delStop(file& docObj)
{
	for(int i = 0; i < docObj.abstractList.size(); i++)
	{
		for(int j = 0; j < docObj.abstractList.at(i).size(); j++)
		{
			for(int k = 0; k < docObj.stopWordList.size(); k++)
			{
				if(docObj.abstractList.at(i).at(j) == docObj.stopWordList.at(k))
				{
					docObj.abstractList.at(i).erase(docObj.abstractList.at(i).begin()+j);
					j--;
					break;
				}
			}
		}
	}
}


void file::setAbstractList(vector < vector<string> > stemmList)
{
	abstractList = stemmList;
}
