//------------------------------------------------------------------------------------------------
//
// #Name: CutFlowClass.cxx
// #Description: Source file for CutFlow class.
//
// #Creator: Joshua Loyal
// #Updated: 6/20/2011
//
//------------------------------------------------------------------------------------------------

#include "DukHep/include/CutFlow.h"

//------------------------------------------------------------------------------------------------
// 
// I am going to use the map::insert method in this code, so I am going to document its use.
// I am using this method because if one attempts to insert an element with a key that is already
// in the map, then map::insert does nothing. In addition the version of map::insert that takes
// a single key-value std::pair does return a value: an iterator that refers to the element in
// the map with the corresponding key, and a bool that indicates whether the element was inserted.
//
//-------------------------------------------------------------------------------------------------

void CutFlow::addCut(uint cutidx, std::string CutName) {
    
    // to understand this syntax see the paragraph above
    std::pair<std::map<uint, std::string>::iterator, bool> ret = 
            cutMap.insert(std::make_pair(cutidx, CutName));
    
    // check to see if the cut was inserted
    if(! ret.second) { 
        std::cout << "You have already inserted the following cut number: " << cutidx 
                  << "!" << "\nPlease fix your F@*n code..." << std::endl;
    } 
    
    // if the cut number is not already in cutMap, add an element to cutVec 
    // and increment the number of cuts.
    cutVec.push_back(0);
    ++nCuts;

    return;

}

void CutFlow::passCut() {
    cutVec.at(Counter)++; // increment the cut flow information
    Counter++;            // move the counter over to the next cut
}

void CutFlow::printCutFlow() {
    std::map<uint, std::string>::const_iterator
                            map_it = cutMap.begin();
 
    // I want a pretty banner surrounding the table... it dynamically grows
    // depending on the object name.
    std::string Banner("=====================");
    std::string BannerTitle = " " + Object + " Cut Flow Summary "; 
    std::string LowerBanner(2*Banner.size() + BannerTitle.size() , '=' );
    
    // top banner
    std::cout << Banner << BannerTitle << Banner << std::endl;
    
    // loop through the cutflow map and cutflow vector and display the information in a table
    while (map_it != cutMap.end()) {
        std::cout << "(C" << map_it->first << ") Number of " << Object <<"s passing " 
             << map_it->second << " cut: " << cutVec[map_it->first] 
                                           << std::endl;
        ++map_it;
    }
    
    // bottom banner
    std::cout << LowerBanner << std::endl;

}


