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

int portStemm::getmValue(string test)
{
	int mVal = 0; //intialize mval
//	bool isVowel = true;
	string temp = test;

	for(int i = 0; i < temp.length() - 1; i++)
	{
		if(temp.at(i) == 'a' || temp.at(i) == 'e' || temp.at(i) == 'i' || temp.at(i) == 'o' || temp.at(i) == 'u' || temp.at(i) == 'y')
		{
			if(temp.at(i + 1) == 'a' || temp.at(i + 1) == 'e' || temp.at(i + 1) == 'i' || temp.at(i + 1) == 'o' || temp.at(i + 1) == 'u' || temp.at(i +1) == 'y')
			{
				//skip me
			}
			else
			{
				mVal ++;		
			}
		}
		else
		{
			//goes to next letter to find a VC pair
		}
		
	}
	return mVal;
}

bool portStemm::isVowel(char c)
{
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

void portStemm::algo1A(file& docObj, portStemm& absObj) 
{
	absObj.abstractList = docObj.getAbstractList();
    for(int i = 0; i < absObj.abstractList.size(); i++)
    {
        for(int j = 0; j < absObj.abstractList.at(i).size(); j++)
		{
			if(absObj.abstractList.at(i).at(j).find("sses") != string::npos) //test for sses
			{
				absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).find("sses") +2, 2);
			}	
			else if(absObj.abstractList.at(i).at(j).find("ies") != string::npos) //test for ies
			{
				absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).find("ies") + 1, 2);
			}
			else if(absObj.abstractList.at(i).at(j).find("ss") != string::npos) //test for ss
			{
				//defaults to else 	
			}
			else if(absObj.abstractList.at(i).at(j).find_last_of("s") == absObj.abstractList.at(i).at(j).length() - 1) //test for s
			{
				absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).find_last_of("s"), 1);
			}
			else //return 
			{
				
			}
			//return absObj.abstractList.at(i).at(j);
		}
	}
	docObj.setAbstractList(absObj.abstractList);
	//return "its alive!!";
}

void portStemm::algo1B(file& docObj, portStemm& absObj) //"and i oop" -summer h. 
{
	int mval = 0;
	bool rule = false; //used to check if second or third step is successful...initialized to false
	bool rule2 = false;
	string subTemp; //substring shit

 	for(int i = 0; i < absObj.abstractList.size(); i++)
    {
        for(int j = 0; j < absObj.abstractList.at(i).size(); j++)
		{
			rule = false;
			rule2 = false;

			if(absObj.abstractList.at(i).at(j).find("eed") != string::npos)
			{
				subTemp = absObj.abstractList.at(i).at(j).substr(0, absObj.abstractList.at(i).at(j).find("eed"));
				mval = absObj.getmValue(subTemp);
				if(mval > 0)
				{
					absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).find("eed") +2, 1);
					rule = true;
				}
			}
			else if(absObj.abstractList.at(i).at(j).find("ed") != string::npos)
			{
				subTemp = absObj.abstractList.at(i).at(j).substr(0, absObj.abstractList.at(i).at(j).find("ed"));
				mval = absObj.getmValue(subTemp);
				if(mval > 0)
				{
					absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).find("ed"), 2);
					rule = true;
				}
			}  

			else if (absObj.abstractList.at(i).at(j).find("ing") != string::npos)
			{
				subTemp = absObj.abstractList.at(i).at(j).substr(0, absObj.abstractList.at(i).at(j).find("ing"));
				mval = absObj.getmValue(subTemp);
				if(mval > 0)
				{
					absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).find("ing"), 3);
					rule = true;
				}
			}

			if(rule == true)
			{
				if(absObj.abstractList.at(i).at(j).find("at") == absObj.abstractList.at(i).at(j).length() - 2) 
				{
					absObj.abstractList.at(i).at(j).append("e");
					rule2 = true;
				}
				else if(absObj.abstractList.at(i).at(j).find("bl") == absObj.abstractList.at(i).at(j).length() - 2)
				{
					absObj.abstractList.at(i).at(j).append("e");
					rule2 = true;
				}
				else if(absObj.abstractList.at(i).at(j).find("iz") == absObj.abstractList.at(i).at(j).length() - 2)
				{
					absObj.abstractList.at(i).at(j).append("e");
					rule2 = true;
				}
			}
			if(rule2 == true || rule == true)
			{
				if(subTemp.at(subTemp.length() - 1) == subTemp.at(subTemp.length() - 2))
				{
					if((subTemp.at(subTemp.length()-1) != 'a' || subTemp.at(subTemp.length()-1) != 'e' || subTemp.at(subTemp.length()-1) != 'i' || subTemp.at(subTemp.length()-1) != 'o' || subTemp.at(subTemp.length()-1) != 'u' || subTemp.at(subTemp.length()-1) != 'y') && (subTemp.at(subTemp.length()-2) != 'a' || subTemp.at(subTemp.length()-2) != 'e' || subTemp.at(subTemp.length() - 2) != 'i' || subTemp.at(subTemp.length() -2) != 'o' || subTemp.at(subTemp.length() -2) != 'u' || subTemp.at(subTemp.length() - 2) != 'y'))
					{
						if(subTemp.at(subTemp.length() -1) != 'l' && subTemp.at(subTemp.length() -1) != 's' && subTemp.at(subTemp.length() -1) != 'z')
						{
							absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).length() - 1);
						}
					}
				}

				else if(mval == 1)
				{
					if(absObj.abstractList.at(i).at(j).at(absObj.abstractList.at(i).at(j).length()-3) != 'a' && absObj.abstractList.at(i).at(j).at(absObj.abstractList.at(i).at(j).length()-3) != 'e' && absObj.abstractList.at(i).at(j).at(absObj.abstractList.at(i).at(j).length()-3) != 'i' && absObj.abstractList.at(i).at(j).at(absObj.abstractList.at(i).at(j).length()-3) != 'o' && absObj.abstractList.at(i).at(j).at(absObj.abstractList.at(i).at(j).length()-3) != 'u' && absObj.abstractList.at(i).at(j).at(absObj.abstractList.at(i).at(j).length()-3) != 'y')
					{
						if(absObj.abstractList.at(i).at(j).at(absObj.abstractList.at(i).at(j).length()-2) == 'a' || absObj.abstractList.at(i).at(j).at(absObj.abstractList.at(i).at(j).length()-2) == 'e' || absObj.abstractList.at(i).at(j).at(absObj.abstractList.at(i).at(j).length()-3) != 'i' || absObj.abstractList.at(i).at(j).at(absObj.abstractList.at(i).at(j).length()-2) == 'o' || absObj.abstractList.at(i).at(j).at(absObj.abstractList.at(i).at(j).length()-2) == 'u' || absObj.abstractList.at(i).at(j).at(absObj.abstractList.at(i).at(j).length()-2) == 'y')
						{
							if(absObj.abstractList.at(i).at(j).at(absObj.abstractList.at(i).at(j).length()-1) != 'a' && absObj.abstractList.at(i).at(j).at(absObj.abstractList.at(i).at(j).length()-1) != 'e' && absObj.abstractList.at(i).at(j).at(absObj.abstractList.at(i).at(j).length()-1) != 'i' && absObj.abstractList.at(i).at(j).at(absObj.abstractList.at(i).at(j).length()-1) != 'o' && absObj.abstractList.at(i).at(j).at(absObj.abstractList.at(i).at(j).length()-1) != 'u' && absObj.abstractList.at(i).at(j).at(absObj.abstractList.at(i).at(j).length()-1) != 'y')
							{
								if(absObj.abstractList.at(i).at(j).at(absObj.abstractList.at(i).at(j).length()-1) != 'w' && absObj.abstractList.at(i).at(j).at(absObj.abstractList.at(i).at(j).length()-1) != 'x' && absObj.abstractList.at(i).at(j).at(absObj.abstractList.at(i).at(j).length()-1) != 'y')
								{
									absObj.abstractList.at(i).at(j).append("e");
								}
							}
						}
					}
				}
			}
		}
	}
	docObj.setAbstractList(absObj.abstractList);
}


void portStemm::algo1C(file& docObj, portStemm& absObj)
{
	int mval;
	string sub;

	for(int i = 0; i < absObj.abstractList.size(); i++)
	{
		for(int j = 0; j < absObj.abstractList.at(i).size(); j++)
		{
			if(absObj.abstractList.at(i).at(j).find('y') ==  absObj.abstractList.at(i).at(j).length() - 1)
			{
				sub = absObj.abstractList.at(i).at(j).substr(0, absObj.abstractList.at(i).at(j).length() - 2);	
				mval = absObj.getmValue(sub);
				if(mval > 0)
				{
					absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).length() - 1);
					absObj.abstractList.at(i).at(j).append("i");
				}
			}
		}
	}
	docObj.setAbstractList(absObj.abstractList); //send it! \m/
}

void portStemm::algo2(file& docObj, portStemm& absObj)
{
	int mval;
	string sub;

	for(int i = 0; i < absObj.abstractList.size(); i++)
	{
		for(int j = 0; j < absObj.abstractList.at(i).size(); j++)
		{
			if(absObj.abstractList.at(i).at(j).length() > 7)
			{
				if(absObj.abstractList.at(i).at(j).find("ational") != string::npos)
				{
					sub = absObj.abstractList.at(i).at(j).substr(0, absObj.abstractList.at(i).at(j).length() - 7);	
					mval = absObj.getmValue(sub);

					cout << sub << " " << mval << endl;
					if(mval > 0)
					{
						absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).length() - 7);
						absObj.abstractList.at(i).at(j).append("ate");
					}
				}
			}
			if(absObj.abstractList.at(i).at(j).length() > 6)
			{
				if(absObj.abstractList.at(i).at(j).find("tional") != string::npos)//absObj.abstractList.at(i).at(j).length() - 7)
				{
					if(absObj.abstractList.at(i).at(j).find("tional") == absObj.abstractList.at(i).at(j).length() - 6)
					{
						sub = absObj.abstractList.at(i).at(j).substr(0, absObj.abstractList.at(i).at(j).length() - 6);	
						mval = absObj.getmValue(sub);
						if(mval > 0)
						{
							absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).length() - 6);
							absObj.abstractList.at(i).at(j).append("tion");
						}
					}
				}
			}
			if(absObj.abstractList.at(i).at(j).length() > 4)
			{
				if(absObj.abstractList.at(i).at(j).find("enci") !=  string::npos)//absObj.abstractList.at(i).at(j).length() - 4)
				{
					sub = absObj.abstractList.at(i).at(j).substr(0, absObj.abstractList.at(i).at(j).length() - 4);	
					mval = absObj.getmValue(sub);
					if(mval > 0)
					{
						absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).length() - 4);
						absObj.abstractList.at(i).at(j).append("ence");
					}
				}
			}
			if(absObj.abstractList.at(i).at(j).length() > 4)
			{
				if(absObj.abstractList.at(i).at(j).find("anci") != string::npos)//absObj.abstractList.at(i).at(j).length() - 4)
				{
					sub = absObj.abstractList.at(i).at(j).substr(0, absObj.abstractList.at(i).at(j).length() - 4);	
					mval = absObj.getmValue(sub);
					if(mval > 0)
					{
						absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).length() - 4);
						absObj.abstractList.at(i).at(j).append("ance");
					}
				}
			}
			if(absObj.abstractList.at(i).at(j).length() > 4)
			{
				if(absObj.abstractList.at(i).at(j).find("izer") != string::npos)//absObj.abstractList.at(i).at(j).length() - 5)
				{
					sub = absObj.abstractList.at(i).at(j).substr(0, absObj.abstractList.at(i).at(j).length() - 4);	
					mval = absObj.getmValue(sub);
					if(mval > 0)
					{
						absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).length() - 4);
						absObj.abstractList.at(i).at(j).append("ize");
					}
				}
			}
			if(absObj.abstractList.at(i).at(j).length() > 4)
			{
				if(absObj.abstractList.at(i).at(j).find("abli") != string::npos)
				{
					sub = absObj.abstractList.at(i).at(j).substr(0, absObj.abstractList.at(i).at(j).length() - 4);	
					mval = absObj.getmValue(sub);
					if(mval > 0)
					{
						absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).length() - 4);
						absObj.abstractList.at(i).at(j).append("able");
					}
				}
			}
			if(absObj.abstractList.at(i).at(j).length() > 4)
			{
				if(absObj.abstractList.at(i).at(j).find("alli") != string::npos)
				{
					sub = absObj.abstractList.at(i).at(j).substr(0, absObj.abstractList.at(i).at(j).length() - 4);	
					mval = absObj.getmValue(sub);
					if(mval > 0)
					{
						absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).length() - 4);
						absObj.abstractList.at(i).at(j).append("al");
					}
				}
			}
			if(absObj.abstractList.at(i).at(j).length() > 5)
			{
				if(absObj.abstractList.at(i).at(j).find("entli") != string::npos)
				{
					sub = absObj.abstractList.at(i).at(j).substr(0, absObj.abstractList.at(i).at(j).length() - 5);	
					mval = absObj.getmValue(sub);
					if(mval > 0)
					{
						absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).length() - 5);
						absObj.abstractList.at(i).at(j).append("ent");
					}
				}
			}
			if(absObj.abstractList.at(i).at(j).length() > 3)
			{
				if(absObj.abstractList.at(i).at(j).find("eli") != string::npos)
				{
					sub = absObj.abstractList.at(i).at(j).substr(0, absObj.abstractList.at(i).at(j).length() - 3);	
					mval = absObj.getmValue(sub);
					if(mval > 0)
					{
						absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).length() - 3);
						absObj.abstractList.at(i).at(j).append("e");
					}
				}
			}
			if(absObj.abstractList.at(i).at(j).length() > 5)
			{
				if(absObj.abstractList.at(i).at(j).find("ousli") != string::npos)
				{
					sub = absObj.abstractList.at(i).at(j).substr(0, absObj.abstractList.at(i).at(j).length() - 5);	
					mval = absObj.getmValue(sub);
					if(mval > 0)
					{
						absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).length() - 5);
						absObj.abstractList.at(i).at(j).append("ous");
					}
				}
			}
			if(absObj.abstractList.at(i).at(j).length() > 7)
			{
				if(absObj.abstractList.at(i).at(j).find("ization") != string::npos)
				{
					sub = absObj.abstractList.at(i).at(j).substr(0, absObj.abstractList.at(i).at(j).length() - 7);	
					mval = absObj.getmValue(sub);
					if(mval > 0)
					{
						absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).length() - 7);
						absObj.abstractList.at(i).at(j).append("ize");
					}
				}
			}
			if(absObj.abstractList.at(i).at(j).length() > 5)
			{
				if(absObj.abstractList.at(i).at(j).find("ation") != string::npos)
				{
					sub = absObj.abstractList.at(i).at(j).substr(0, absObj.abstractList.at(i).at(j).length() - 5);	
					mval = absObj.getmValue(sub);
					if(mval > 0)
					{
						absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).length() - 5);
						absObj.abstractList.at(i).at(j).append("ate");
					}
				}
			}
			if(absObj.abstractList.at(i).at(j).length() > 4)
			{
				if(absObj.abstractList.at(i).at(j).find("ator") != string::npos)
				{
					sub = absObj.abstractList.at(i).at(j).substr(0, absObj.abstractList.at(i).at(j).length() - 4);	
					mval = absObj.getmValue(sub);
					if(mval > 0)
					{
						absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).length() - 4);
						absObj.abstractList.at(i).at(j).append("ate");
					}
				}
			}
			if(absObj.abstractList.at(i).at(j).length() > 5)
			{
				if(absObj.abstractList.at(i).at(j).find("alism") != string::npos)
				{
					sub = absObj.abstractList.at(i).at(j).substr(0, absObj.abstractList.at(i).at(j).length() - 5);	
					mval = absObj.getmValue(sub);
					if(mval > 0)
					{
						absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).length() - 5);
						absObj.abstractList.at(i).at(j).append("al");
					}
				}
			}
			if(absObj.abstractList.at(i).at(j).length() > 7)
			{
				if(absObj.abstractList.at(i).at(j).find("iveness") != string::npos)
				{
					sub = absObj.abstractList.at(i).at(j).substr(0, absObj.abstractList.at(i).at(j).length() - 7);	
					mval = absObj.getmValue(sub);
					if(mval > 0)
					{
						absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).length() - 7);
						absObj.abstractList.at(i).at(j).append("ive");
					}
				}
			}
			if(absObj.abstractList.at(i).at(j).length() > 7)
			{
				if(absObj.abstractList.at(i).at(j).find("fulness") != string::npos)
				{
					sub = absObj.abstractList.at(i).at(j).substr(0, absObj.abstractList.at(i).at(j).length() - 7);	
					mval = absObj.getmValue(sub);
					if(mval > 0)
					{
						absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).length() - 7);
						absObj.abstractList.at(i).at(j).append("ful");
					}
				}
			}
			if(absObj.abstractList.at(i).at(j).length() > 7)
			{
				if(absObj.abstractList.at(i).at(j).find("ousness") != string::npos)
				{
					sub = absObj.abstractList.at(i).at(j).substr(0, absObj.abstractList.at(i).at(j).length() - 7);	
					mval = absObj.getmValue(sub);
					if(mval > 0)
					{
						absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).length() - 7);
						absObj.abstractList.at(i).at(j).append("ous");
					}
				}
			}
			if(absObj.abstractList.at(i).at(j).length() > 5)
			{
				if(absObj.abstractList.at(i).at(j).find("aliti") != string::npos)
				{
					sub = absObj.abstractList.at(i).at(j).substr(0, absObj.abstractList.at(i).at(j).length() - 5);	
					mval = absObj.getmValue(sub);
					if(mval > 0)
					{
						absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).length() - 5);
						absObj.abstractList.at(i).at(j).append("al");
					}
				}
			}
			if(absObj.abstractList.at(i).at(j).length() > 5)
			{
				if(absObj.abstractList.at(i).at(j).find("iviti") != string::npos)
				{
					sub = absObj.abstractList.at(i).at(j).substr(0, absObj.abstractList.at(i).at(j).length() - 5);	
					mval = absObj.getmValue(sub);
					if(mval > 0)
					{
						absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).length() - 5);
						absObj.abstractList.at(i).at(j).append("ive");
					}
				}
			}
			if(absObj.abstractList.at(i).at(j).length() > 6)
			{
				if(absObj.abstractList.at(i).at(j).find("biliti") != string::npos)
				{
					sub = absObj.abstractList.at(i).at(j).substr(0, absObj.abstractList.at(i).at(j).length() - 6);	
					mval = absObj.getmValue(sub);
					if(mval > 0)
					{
						absObj.abstractList.at(i).at(j).erase(absObj.abstractList.at(i).at(j).length() - 6);
						absObj.abstractList.at(i).at(j).append("ble");
					}
				}
			}
		}
	}
	docObj.setAbstractList(absObj.abstractList); //send it! \m/
}

/*

string step3(string abstracList)
{
	int l = abstracList.length();
        if (l>=7 && getmValue(abstracList.substr(0,l-5))>0 && abstracList.substr(l-5,5)== "icate")
	{
		abstracList.erase(l-3,3);
		l-=3;
	}

        else if (l>=7 && getmValue(abstracList.substr(0,l-5))>0 && abstracList.substr(l-5,5)== "ative")
        {
		abstracList.erase(l-5,5);
		l-=5;
	}

	else if (l>=7 && getmValue(abstracList.substr(0,l-5))>0 && abstracList.substr(l-5,5)== "alize")
        {
                abstracList.erase(l-3,3);
		l-=3;
        }

	else if (l>=7 && getmValue(abstracList.substr(0,l-5))>0 && abstracList.substr(l-5,5)== "iciti")
        {
                abstracList.erase(l-3,3);
		l-=3;
        }

	else if (l>=6 && getmValue(abstracList.substr(0,l-4))>0 && abstracList.substr(l-4,4)== "ical")
        {
                abstracList.erase(l-2,2);
		l-=2;
        }

	else if (l>=5 && getmValue(abstracList.substr(0,l-3))>0 && abstracList.substr(l-3,3)=="ful")
        {
                abstracList.erase(l-3,3);
		l-=3;
        }

	else if (l>=6 && getmValue(abstracList.substr(0,l-4))>0 && abstracList.substr(l-4,4)== "ness")
        {
                abstracList.erase(l-4,4);
		l-=4;
        }
	return abstracList; 
}

string step4(string abstracList)
{
	int l = abstracList.length();
	if (l>=4 && getmValue(abstracList.substr(0,l-2))> 1 && abstracList.substr(l-2,2)=="al")
	{
                abstracList.erase(l-2,2);
		l-=2;
	}

	else if(l>=6 && getmValue(abstracList.substr(0,l-4))> 1 && abstracList.substr(l-4,4)=="ance")
	{
                abstracList.erase(l-4,4);
		l-=4;
	}

	else if(l>=6 && getmValue(abstracList.substr(0,l-4))> 1 && abstracList.substr(l-4,4)=="ence")
        {
                abstracList.erase(l-4,4);
		l-=4;
        }

	else if(l>=4 && getmValue(abstracList.substr(0,l-2))> 1 && abstracList.substr(l-2,2)=="er")
        {
                abstracList.erase(l-2,2);
		l-=2;
        }

	else if(l>=4 && getmValue(abstracList.substr(0,l-2))> 1 && abstracList.substr(l-2,2)=="ic")
        {
                abstracList.erase(l-2,2);
		l-=2;
        }

	else if(l>=6 && getmValue(abstracList.substr(0,l-4))> 1 && abstracList.substr(l-4,4)=="able")
        {
                abstracList.erase(l-4,4);
		l-=4;
        }

	else if(l>=6 && getmValue(abstracList.substr(0,l-4))> 1 && abstracList.substr(l-4,4)=="ible")
        {
                abstracList.erase(l-4,4);
		l-=4;
        }

	else if(l>=5 && getmValue(abstracList.substr(0,l-3))> 1 && abstracList.substr(l-3,3)=="ant")
        {
                abstracList.erase(l-3,3);
		l-=3;
        }
	
	else if(l>=7 && getmValue(abstracList.substr(0,l-5))> 1 && abstracList.substr(l-5,5)=="ement")
        {
                abstracList.erase(l-5,5);
		l-=5;
        }

	else if(l>=6 && getmValue(abstracList.substr(0,l-4))> 1 && abstracList.substr(l-4,4)=="ment")
        {
                abstracList.erase(l-4,4);
		l-=4;
        }

	else if(l>=5 && getmValue(abstracList.substr(0,l-3))> 1 && abstracList.substr(l-3,3)=="ent")
        {
                abstracList.erase(l-3,3);
		l-=3;
        }

	else if(l>=6 && getmValue(abstracList.substr(0,l-3))> 1 &&(abstracList[l-4]=='s'||abstracList[l-4]=='t')&& abstracList.substr(l-3,3)=="ion")
        {
                abstracList.erase(l-3,3);
		l-=3;
        }

	else if(l>=4 && getmValue(abstracList.substr(0,l-2))>1 && abstracList.substr(l-2,2)=="ou")
        {
                abstracList.erase(l-2,2);
		l-=2;
        }
	
	else if(l>=5 && getmValue(abstracList.substr(0,l-3))>1 && abstracList.substr(l-3,3)=="ism")
        {
                abstracList.erase(l-3,3);
		l-=3;
        }

	else if(l>=5 && getmValue(abstracList.substr(0,l-3))>1 && abstracList.substr(l-3,3)=="ate")
        {
                abstracList.erase(l-3,3);
		l-=3;
        }

	else if(l>=5 && getmValue(abstracList.substr(0,l-3))>1 && abstracList.substr(l-3,3)=="iti")
        {
                abstracList.erase(l-3,3);
		l-=3;
        }

	else if(l>=5 && getmValue(abstracList.substr(0,l-3))>1 && abstracList.substr(l-3,3)=="ous")
        {
                abstracList.erase(l-3,3);
		l-=3;
        }

	else if(l>=5 && getmValue(abstracList.substr(0,l-3))>1 && abstracList.substr(l-3,3)=="ive")
        {
                abstracList.erase(l-3,3);
		l-=3;
        }

	else if(l>=5 && getmValue(abstracList.substr(0,l-3))>1 && abstracList.substr(l-3,3)=="ize")
        {
                abstracList.erase(l-3,3);
		l-=3;
        }
        return abstracList;
}

string step5A(string abstracList)
{
	int l = abstracList.length();
        if (abstracList[l-1]=='e' && getmValue(abstracList.substr(0,l-1))>1 )
	{
                abstracList.pop_back();
		l--;
 	}

        else if (l>=3 && abstracList[l-1]=='e' && getmValue(abstracList.substr(0,l-1))==1 )
        {
                if (isvowel(abstracList[0]) || !(!isvowel(abstracList[l-2]) && isvowel(abstracList[l-3]) && !isvowel(abstracList[l-4])))
		{
			abstracList.pop_back();
			l--;
		}
        }
        return abstracList;
}

string step5B(string abstracList)
{
	int l = abstracList.length();
	if (getmValue(abstracList.substr(0,l-1))>1 && abstracList[l-1]=='l' && abstracList[l-2]=='l')
	{
		abstracList.pop_back();
	}		
        return abstracList;
}

string poters(string abstracList)
{
        abstracList = step1A(abstracList);
        abstracList = step1B(abstracList);
        abstracList = step1C(abstracList);
        abstracList = step2(abstracList);
        abstracList = step3(abstracList);
        abstracList = step4(abstracList);
        abstracList = step5A(abstracList);
        abstracList = step5B(abstracList);

        return abstracList;
}

*/



