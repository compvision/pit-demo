#include <cstdlib>
#include <string>

#include "AppConfig.hpp"

AppConfig::AppConfig() :
DeviceID(0),
isFile(0),
isDevice(0)
{
}

// Getters
std::string AppConfig::getFileName()
{
    return fileName;
}

int AppConfig::getDeviceID()
{
    return DeviceID;
}

int AppConfig::getIsFile()
{
    return isFile;
}

int AppConfig::getIsDevice()
{
    return isDevice;
}

// Setters
void AppConfig::setFileName(std::string inputFileName)
{
    fileName = inputFileName;
}

void AppConfig::setDeviceID(int inputDeviceID)
{
    DeviceID = inputDeviceID;
}

void AppConfig::setIsFile(int inputIsFile)
{
    isFile = inputIsFile;
}

void AppConfig::setIsDevice(int inputIsDevice)
{
    isDevice = inputIsDevice;
}
