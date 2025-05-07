#ifndef LOAD_DATA_H
#define LOAD_DATA_H

#include "FXOption.h"
#include <string>
#include <vector>

std::vector<FXOption> loadFXOptions(const std::string& filename);

#endif
