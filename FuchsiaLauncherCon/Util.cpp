#include "Util.h"

int GetFileSize(std::string path) {
	return std::filesystem::file_size(path);
}