#include "DevicesDatabase.h"

void DevicesDatabase::Initialize(const std::filesystem::path& path) {
	this->data.reserve(31000);
	std::ifstream devInfoFile(path);
	if (!devInfoFile.is_open()) {
		std::cerr << GetLastError();
	}

	std::string buffer;
	while (std::getline(devInfoFile, buffer)) {
		data.push_back(buffer);
	}
	devInfoFile.close();
}