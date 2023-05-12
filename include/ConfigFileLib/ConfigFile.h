#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <typeinfo>
#include "Exception.h"

using namespace std;

class ConfigFile {
public:
    static const unsigned short CFILE_BOOL = 0,
            CFILE_SHORT = 1,
            CFILE_U_SHORT = 2,
            CFILE_INT = 3,
            CFILE_U_INT = 4,
            CFILE_LONG = 5,
            CFILE_U_LONG = 6,
            CFILE_LONG_LONG = 7,
            CGILE_U_LONG_LONG = 8,
            CFILE_FLOAT = 9,
            CFILE_DOUBLE = 10,
            CFILE_LONG_DOUBLE = 11,
            CFILE_CHAR = 12,
            CFILE_U_CHAR = 13,
            CFILE_STRING = 14;

    struct ConfigInputLine {
        string name;
        unsigned short type;
        string defaultVal;
        bool required;
    };
    //----------------------

    /**
     * @brief Constructor of config class
     * @param fileName name of config file
     * @param cinput ConfigVector (from ConfigPrepare)
     */
    ConfigFile(string fileName, vector<ConfigFile::ConfigInputLine> cinput);

    virtual ~ConfigFile();

    /**
     * @brief Load next/extra definitions list. The new list shouldnt not contain definitions that are passed in other lists or constructor.
     * @param definitionsList list with variable definitions
     * @throws Exception
     * @throw Duplicated definitions name
     * @throw Can't find required key
     */
    void loadMoreDefinitions(vector<ConfigFile::ConfigInputLine> definitionsList);

    /**
     * @brief Get from reader config bool value
     * @param key
     * @return value assigned to key
     */
    bool getBoolValue(string key);

    /**
     * @brief Get from reader config int value
     * @param key
     * @return value assigned to key
     */
    int getIntValue(string key);

    /**
     * @brief Get from reader config int value
     * @param key
     * @return value assigned to key
     */
    double getDoubleValue(string key);

    /**
     * @brief Get from reader config int value
     * @param key
     * @return value assigned to key
     */
    string getStringValue(string key);

    /**
     * @brief Get from reader config int value
     * @param key
     * @return value assigned to key
     */
    template<typename type>
    type getValue(string key);

    /**
     * @brief Get from reader config int value
     * @param key
     * @return value assigned to key
     */
    string getValue(string key);



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
        bool defined = false;
    };
    map<string, backboneItem> backbone;
    ifstream cfile;

    bool checkType(string val, unsigned short type);

    template<typename type>
    bool isNumber(string txt);

    bool isString(string txt);

    string whiteCharsEraser(string txt);

    void fileProcessing();
};

#endif // CONFIGFILE_H
