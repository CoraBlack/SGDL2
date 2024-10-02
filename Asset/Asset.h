#ifndef ASSET_H
#define ASSET_H

#include <string>

class Asset {
public:
	Asset(std::string &filePath);
protected:
	std::string path = "";
};

#endif