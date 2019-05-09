#pragma once

#include <dlfcn.h>
#include <experimental/filesystem>

#include "vst_module.h"

namespace Raspiano
{
class MinimalHost
{
public:
  MinimalHost();

private:
  std::experimental::filesystem::path vstPath; 
  VSTModule* myModule;
};

}
