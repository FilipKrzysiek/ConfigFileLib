//
// Created by cysiu on 22.09.2019.
//

#ifndef LOGLIB_CONFIGFILEPREPARE_H
#define LOGLIB_CONFIGFILEPREPARE_H

#include "ConfigFile.h"
#include <string>
#include "../../../Exception/Exception.h"

using namespace std;


class ConfigFilePrepare {
public:
    /**
     * @brief Adding new line to definitions of config inputs
     * @param name name of config input (in line)
     * @param type type of variable
     * @param defaultVal default value of input
     * @param required is required to run program
     */
    void addConfigInputLine(string name, unsigned short type, string defaultVal, bool required);

    /**
     * @brief Getting vector of prepared config input lines. Pass this to ConfigFile constructor
     * @return vector of ConfigInputLines
     */
    vector<ConfigFile::ConfigInputLine> getConfigVector();
private:
    vector<ConfigFile::ConfigInputLine> inputLines;
    ConfigFile::ConfigInputLine temp;
};


#endif //LOGLIB_CONFIGFILEPREPARE_H
