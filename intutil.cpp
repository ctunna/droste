/*********************************************************************
NAME: CARSON TUNNA
EMAIL: ctunn136@mymru.ca
ASG#: 3
INSTRUCTOR: DR. NAMARATA KHEMKA
FILE NAME: intutil.cpp
DUE: WEDNESDAY MARCH 9TH, 2011 10:00 PM
*********************************************************************/

#include <iostream>
using namespace std;

void readInt(const char prompt[], int &x, int &y)

/**********************************************************************************

FUNCTIONS NAME: readInt

PURPOSE: The purpose of this function is to provide a reliable way to read an
         integer from the user.

INPUT PARAMETERS: const char prompt[] - This is an array of characters that prompts
                  the user for input.

OUTPUT PARAMETERS: None.

Returns: void.

Note: This is code is derived from a function written in a previous assignment.
**********************************************************************************/
    
{
    
    bool done;
    char junk;
    
    done = false;
    
    while( !done )    
    {
	cout << prompt << endl;
	cin >> x >> y;
	
	if ( cin.fail() )
	{
	    cin.ignore(1000);
	    cin.clear();
	}
	else
	{
	    cin.get(junk);
	    
	    if( junk == ' ' ||
		junk == '\n' )
		done = true;
	    else
	    {
		cin.ignore(1000);
		cin.clear();
	    }
	    
	} 
	
    }
    
    
    return;
    
}

