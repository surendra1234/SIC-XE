#ifndef OBJECTPROG_H_INCLUDED
#define OBJECTPROG_H_INCLUDED
#include <iostream>
#include <fstream>
#include <iomanip>

void write()
{

    int columns=0;
    string forwriting="",s,textrec_add=start_add;
    store_count=0;

    ofstream myfile;
    myfile.open("object.txt");

    myfile<<"H^";
    myfile<<SYMTAB[0].label;
    for(int yr=SYMTAB[0].label.length();yr<=6;yr++)
    myfile<<" ";
    myfile<<"^0"<<start_add<<"^0"<<length<<endl;

    FILE* fptr;
    fptr=fopen("output.txt","r");

    while (fgets(buffer,256,fptr) != NULL)
	{
	     s=buffer;
	     store_count++;
         s=s.substr(0,s.length()-1);
         if(s.length()==0)
                  continue;
         if(columns+s.length() > 60)
         {
              myfile<<"T^"<<textrec_add<<"^";
              myfile<<tohexstr(columns/2);
              myfile<<"^"<<forwriting<<endl;
              columns=0;
              forwriting=s+"^";
              columns=s.length();
              textrec_add=store[store_count];
         }
         else
         {
              forwriting+=s+"^";
              columns+=s.length();
         }
    }    
    myfile<<"T^"<<textrec_add<<"^";;
    myfile<<tohexstr(columns/2);
    myfile<<"^"<<forwriting<<endl;
    myfile.close();
    fclose(fptr);
}

#endif 
