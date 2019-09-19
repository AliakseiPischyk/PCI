#include <windows.h>
#include <setupapi.h>
#include <devguid.h>
#include <regstr.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>

#include "Parser.h"
#include "Device.h"

#pragma comment( lib, "setupapi.lib" )

class PciDevicesProvider
{
private:
	SP_DEVINFO_DATA DevInfoData;
	HDEVINFO DevInfoSet;

	char pbuffer[512];

	Parser parser;

	bool Initialize();
public:
	PciDevicesProvider(const std::filesystem::path& database):parser(database) {this->Initialize();	}
						
	std::vector<Device> GetDevices();		
	~PciDevicesProvider() {
		SetupDiDestroyDeviceInfoList(DevInfoSet);
	}
};

