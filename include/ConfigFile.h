#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <typeinfo>
#include "../../Exception/Exception.h"

using namespace std;

class ConfigFile {
public:
    static const unsigned short CFILE_BOOL = 0,
            CFILE_INT = 1,
            CFILE_DOUBLE = 2,
            CFILE_STRING = 3;

    struct ConfigInputLine {
        string name;
        unsigned short type;
        string defaultVal;
        bool required;
    };
    //----------------------

    ConfigFile(string fileName, vector<ConfigFile::ConfigInputLine> cinput);

    virtual ~ConfigFile();

    int getIntValue(string key);

    double getDoubleValue(string key);

    string getStringValue(string key);

    template<typename type = string>
    type getValue(string key);



    //string getValue(string key);

protected:

private:
    //Name, value
    //This keep all config values
    map<string, string> cdata;
    //Name, type, default value, is required
    struct backboneItem {
        unsigned short type;
        string defaultVal;
        bool required;
        bool exist = false;
    };
    map<string, backboneItem> backbone;
    ifstream cfile;

    bool checkType(string val, unsigned short type);

    template<typename type>
    bool isNumber(string txt);

    bool isString(string txt);

    string whiteCharsEraser(string txt);
};

#endif // CONFIGFILE_H
