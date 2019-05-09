#include "vst_module.h"
#include <dlfcn.h>
#include <iostream>

namespace Raspiano
{
VSTModule::VSTModule()
{

}

void VSTModule::initialize()
{
  *(void**)(&myGetFactory) = dlsym(pluginPtr, "GetPluginFactory");
  if (! myGetFactory)
  {
    std::cout << "Cannot find the 'GetPluginFactory' function" << std::endl;
  }
}

}
