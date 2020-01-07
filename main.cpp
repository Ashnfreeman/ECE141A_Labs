//
//  main.cpp
//  ECE141A_LabW1Code
//
//  Created by Ashley Freeman on 1/6/20.
//  Copyright © 2020 Ashley Freeman. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

/*
  This function counts source lines, and excludes comments!
  Return an integer that represents # of source lines read.
*/
size_t countLines(std::string &aFile) {
  size_t          theCount=0;
  char            theBuffer[250];
  std::ifstream   theInput(aFile.c_str());
  bool            inComment=false;

  while(!theInput.eof()) {
    theInput>>std::ws;
    theInput.getline(theBuffer,200);
    if(theBuffer[0]) {
      if(inComment) {
        if(strstr(theBuffer,"*/"))
          inComment=false;
      }
      else {
        if(strstr(theBuffer,"//")) {
          continue;
        }
        
        char* thePos=strstr(theBuffer,"/*");
        if(thePos && (thePos==theBuffer)) {
          inComment=!strstr(theBuffer,"*/");
        }
        else theCount++;
    }
  }
}
    return theCount;
}

    //Get a path to the main for this lab...This should be the ACTUAL path //on your computer to this main.cpp file!


std::string getPath() {
    return std::string("/Users/ashleyfreeman/Desktop/ECE 141A Lab Code/ECE141A_LabW1Code/ECE141A_LabW1Code/main.cpp");
}

int main() {
    std::string thePath(getPath());
    float  lineCount=countLines(thePath);
    std::cout << thePath << " lines: " <<  lineCount<<  "\n";
    return 0;
}

