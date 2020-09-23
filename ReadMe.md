# Config file library

This is simple library to read configuration file. 

## Initialize

First we must create template with all used in config file variables. This template is used to check all needed vars is set and vars has correct types.

All prepare methods are in ConfigFilePrepare.h. There are methods:
 * `addConfigInputLine` - adding definitions of variables in config files
 * `getConfigVector` - get vector with all definitions
 
#### Creating variable templates

```c++
void addConfigInputLine(string name, unsigned short type, string defaultVal, bool required);
```

 * `name` - name of variable in config file
 * `type` - type from ConfigFile. Type list:
    * `CFILE_BOOL` - bool
    * `CFILE_SHORT` - short
    * `CFILE_U_SHORT` - unsigned short
    * `CFILE_INT` - int
    * `CFILE_U_INT` - unsigned int 
    * `CFILE_LONG` - long
    * `CFILE_U_LONG` - unsigned long
    * `CFILE_LONG_LONG` - long long
    * `CGILE_U_LONG_LONG` - unsigned long long
    * `CFILE_FLOAT` - float
    * `CFILE_DOUBLE` - double
    * `CFILE_LONG_DOUBLE` - long double
    * `CFILE_CHAR` - char
    * `CFILE_U_CHAR` - unsigned char
    * `CFILE_STRING` - string
 * `defaultVal` - default value, this is always string. Later it was changed. This can be empty string.
 * `required` - variable is required
 
#### Getting vector of all definitions 

```c++
vector<ConfigFile::ConfigInputLine> getConfigVector();
```

Returns vector of all definitions needed to read config file. 

##### Throws

```c++
Exception("Nothing to return by getConfigVector");
```

When list of definitions is empty.

#### Read config file

`ConfigFile.h`

Create ConfigFile object using constructor:

```c++
ConfigFile(string fileName, vector<ConfigFile::ConfigInputLine> cinput);
```

* `fileName` - config file name
* `cinput` - vector of variables definitions

##### Throws

```c++
Exception("Item with name" + name + "exist in definitions list!")
```

In definitions list are duplicated definitions name.

```c++
Exception("Can't open config file");
```

When can't open file.

```c++
Exception("Error in line " + lineNumber + " can't find delimiter\n" + line);
```

Error when parsing line in lineNumber. Not found `=` in line

```c++
Exception("Error in line " + lineNumber + " no assigned value\n" + line);
```

Not found value assigned to variable name.

```c++
Exception("Error in line " + lineNumber + " parameter no name\n" + line);
```

Not found variable name only found value.

```c++
Exception("Error in line " + lineNumber + " bad type\n" + line);
```

Value has bad type.

```c++
Exception("Error can't find required key: " + key);
```

Not found variable which is required.

## Initialize example

```c++
ConfigFilePrepare cfp;

cfp.addConfigInputLine("logFilePath", ConfigFile::CFILE_STRING, "./log.log", false);
cfp.addConfigInputLine("logFileSize", ConfigFile::CFILE_INT, "", true);
cfp.addConfigInputLine("logMaxKeepFiles", ConfigFile::CFILE_U_SHORT, "3", true);

ConfigFile *cfile;

try{
    cfile = new ConfigFile("config.conf", cfp.getConfigVector());
}
catch (Excption &e) {
    cout<<"Error on preparing config:" << e.what() << endl;
    exit(1);
}
```

## Add next definitions list

Adding next definitions list to created configFile object.
This is usable when you using dynamic link libraries and them needs different variables.

```c++
void loadMoreDefinitions(vector<ConfigFile::ConfigInputLine> definitionsList);
``` 

* `definitionsList` - vector of variables definitions

## Config variables access

```c++
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
```
