#include <iostream>
#include <locale>
#include <iomanip>
#include "PciDevicesProvider.h"

#pragma comment( lib, "setupapi.lib" )

using namespace std;

int main() {
	PciDevicesProvider provider("pci_db.txt");
	vector<Device> Devices = provider.GetDevices();

	for (Device device : Devices) {

		cout << setw(5) << left << device.vendorId
			 << setw(40) << left << device.vendorInfo
			 << setw(5) << left << device.deviceId
			 << setw(40) << left << device.deviceInfo << endl;
	}
	system("pause");
	return 0;
}