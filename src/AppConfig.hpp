#ifndef AppConfig_hpp
#define AppConfig_hpp

#include <string>

class AppConfig
{
    public:
        AppConfig();
        void setFileName(std::string fileName);
        void setDeviceID(int deviceID);
        void setIsFile(int isFile);
        void setIsDevice(int inputIsDevice);
        int getDeviceID();
        int getIsFile();
        int getIsDevice();
        std::string getFileName();
    private:
        std::string fileName;
        int DeviceID;
        int isFile;
        int isDevice;
};

#endif /* AppConfig_hpp */
