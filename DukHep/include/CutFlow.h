//----------------------------------------------------------------------------------------------------
//
// #name: CutFlow.h
// #Description: This class is designed as an outline to a generic cutflow. 
//               It allows the user to declare a cut using the addCut(unsigned int, string &) method. 
//               This will create a map that that links the cut name with its position in the cut flow.
//               If one calls the passCut() method when a particle passes a cut, then you should be able
//               to retrieve the cut information with the printCutFlow() method.
//
// #Author: Joshua Loyal
// #Updated: 6/20/2011
//
//----------------------------------------------------------------------------------------------------

// STL include(s)
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <iostream>


#ifndef CUTFLOW_H
#define CUTFLOW_H

class CutFlow {

    public:
    typedef unsigned int uint;
    
    // constructor : allow the users to give the object a name
    CutFlow(const std::string &ObjectName = "object") : nCuts(0), Object(ObjectName), Counter(0) { }
    
    // destructor : default
    ~CutFlow() { }
    
    // call in order to add cut number(cutidx) to cutMap.
    void addCut(uint cutidx, std::string CutName);

    // call if an object passes a particular cut. 
    void passCut();
 
    // call to reset the cut counter
    void resetCutFlow() { Counter = 0; }

    // prints the cutflow information 
    void printCutFlow();
    
    // returns the number of objects which have passed cut cutidx
    uint passedCut(uint cutidx) { return cutVec.at(cutidx); }
    
    public:
    uint nCuts; // total number of cuts.

    private:
    std::string Object;                 // used the printed summary to identify the object.
    std::vector<uint> cutVec;           // the actually cut flow values are held in this vector
    std::map<uint, std::string> cutMap; // used to print the information.
    uint Counter;                       // counter to keep track of the current cut number.

};

#endif 

