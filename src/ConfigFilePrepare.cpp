//
// Created by cysiu on 22.09.2019.
//

#include "ConfigFilePrepare.h"

void ConfigFilePrepare::addConfigInputLine(string name, unsigned short type, string defaultVal, bool required){
    transform(name.begin(), name.end(),  name.begin(), [](unsigned char c){ return std::tolower(c); });
    temp.name = name;
    temp.type = type;
    temp.defaultVal = defaultVal;
    temp.required = required;
    inputLines.push_back(temp);
}

vector<ConfigFile::ConfigInputLine> ConfigFilePrepare::getConfigVector(){
    if(inputLines.size() > 0){
        return inputLines;
    }
    else{
        throw Exception("Nothing to return by getConfigVector");
    }
}