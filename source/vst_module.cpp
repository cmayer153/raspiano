#include "vst_module.h"
#include <dlfcn.h>
#include <iostream>

#include "pluginterfaces/base/funknown.h"
#include "pluginterfaces/base/ipluginbase.h"

using namespace VST3;
using namespace Hosting;

namespace Raspiano
{
VSTModule::VSTModule() :
  myPluginFactory(nullptr)
{

}

void VSTModule::initialize()
{
  // I should understand this better...
  *(void**)(&myGetFactoryProc) = dlsym(pluginPtr, "GetPluginFactory");
  if (! myGetFactoryProc)
  {
    std::cout << "Cannot find the 'GetPluginFactory' function" << std::endl;
  }
  else
  {
//    Steinberg::FUnknownPtr<Steinberg::IPluginFactory> tmpFuncPtr = 
    auto tmpFuncPtr = 
      Steinberg::FUnknownPtr<Steinberg::IPluginFactory>(myGetFactoryProc());

    if (! tmpFuncPtr)
    {
      std::cout << "GetPluginFactory call didn't work..." << std::endl;
    }
    else
    {
      myPluginFactory = new PluginFactory(tmpFuncPtr);
    }
  }
  
}

}
