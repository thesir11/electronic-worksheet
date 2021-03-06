/* 
 * File:   Persistence.h
 * Author: marlon
 *
 * Created on March 7, 2014, 5:26 PM
 */

#ifndef PERSISTENCE_H
#define	PERSISTENCE_H

#define NOT_FOUND string::npos

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class Persistence {
public:
    Persistence(int numLin=10, int numCol=10);
    Persistence(const Persistence& orig);
    virtual ~Persistence();
    
    //Returns number of non-empty lines on the Matrix
    int getNumLine();
    //Returns number of non-empty columns at specified lines
    int getNumCol(int numLin=0);
    //Returns number of allocated lines
    int getMaxNumLine();
    //Returns number of allocated columns
    int getMaxNumCol();
    
    //Writes the matrix to the file named fileName, using the CSV convention
    void writeFile(string fileName, bool header=false);
    
    //Reads the matrix from the fileName to the values vector, using the CSV convention
    void readFile(string fileName, bool header=false);
    
    //Increases the number of lines by d_i and the number of columns by d_j
    void growMatrix(int d_i, int d_j);
     
    //Decreases the number of lines by d_i and the number of columns by d_j
    void shrinkMatrix(int d_i, int d_j);
    
    //Add value to the end of the matrix 
    //(basically does a push_back and automatically changes the line)
    void addValue(string value);
    
    //Access a value on the matrix
    string& operator()(int line, int column);
    
    //returns a matrix that begins at cell (i_0, j_0) and ends at cell (i,j)
    Persistence getSubMatrix(int i_0, int j_0, int i, int j);
    
protected:
    
    //The only reason I'm introducing this value is because there's a strange bug
    //with the vector's .size() method and this is the only workaround I've been
    //able to find. Currently, the lack of this variable doesn't break the application
    //but it may be necessary in the future
    int numLines;
    
    //The reason for this variable is the same as above. It indicates the number of
    //elements in a given line
    vector <int> numCols;

    
    //here is the matrix that will hold the values of the spreadsheet
    vector <vector<string> > values; 
    
    //Returns a string properly processed and ready to be put into the file
    string processStringForWrite(string line);
    
    //RProcess a line and adds each element of the line to the vector
    void processStringForRead(string line);
    
    //Given a certain line, returns a boolean indicating wether the line is filled
    //or not
    bool isLineFull(int linNum);
    
    
    
    

};

#endif	/* PERSISTENCE_H */

