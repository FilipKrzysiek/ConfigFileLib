#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include <string>
#include <typeinfo>

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

    /**
     * @brief Constructor of config class
     * @param fileName name of config file
     * @param cinput ConfigVector (from ConfigPrepare)
     */
    ConfigFile(string fileName, vector<ConfigFile::ConfigInputLine> cinput);

    virtual ~ConfigFile();

    /**
     * @brief Get from readed config int value
     * @param key
     * @return value assigned to key
     */
    int getIntValue(string key);

    /**
     * @brief Get from readed config int value
     * @param key
     * @return value assigned to key
     */
    double getDoubleValue(string key);

    /**
     * @brief Get from readed config int value
     * @param key
     * @return value assigned to key
     */
    string getStringValue(string key);

    /**
     * @brief Get from readed config int value
     * @param key
     * @return value assigned to key
     */
    template<typename type>
    type getValue(string key);

    /**
     * @brief Get from readed config int value
     * @param key
     * @return value assigned to key
     */
    string getValue(string key);
};

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
