// basic file operations
#include <iostream>
#include <fstream>
#include "optab.h"
#include "search_op.h"
#include "hexfunc.h"
#include "subtract_hex.h"
#include "add_hex.h"
#include "Pass2.h"
#include "Pass1.h"
#include "objectprog.h"
#include "listing.h"
using namespace std;

int main ()
{
    ofstream myfile;
    myfile.open("intermediate.txt");
    myfile.close();
    myfile.open("output.txt");
    myfile.close();
    start=false;
    base="";
    string line;
    locctr=0;
    symtab_ctr=0;
    addr="0";
    int lcount=0;//counts the no. of lines
    FILE* fptr;
    fptr=fopen("input.txt","r");

    while (fgets(buffer,256,fptr) != NULL)
	{
         lcount++;
         processline(buffer);
    }
    fclose(fptr);
    length=subtract_hex(addr,start_add);
    start=false;

    fptr=fopen("intermediate.txt","r");
    while (fgets(buffer,256,fptr) != NULL)
	{
        lcount++;
        processline_2(buffer);
    }
    fclose(fptr);
    write();
    listingf();
    system("Pause");
    return 0;
}



