#pragma once

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
#include <filesystem>

class DevicesDatabase {
	
public :
	std::vector<std::string> data;
	void Initialize(const std::filesystem::path& path);
};