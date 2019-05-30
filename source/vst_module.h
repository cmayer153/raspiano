#include "public.sdk/source/vst/hosting/module.h"
#include "pluginterfaces/base/ipluginbase.h"
//#include "steinberg_plugin_factory.h"

/*
namespace Steinberg
{
  class IPluginFactory;
}
*/

namespace Raspiano
{

class VSTModule
{
  //typedef void* (*get_plugin_factory)();
  using GetFactoryProc = Steinberg::IPluginFactory*(*)();
//  using VST3::Hosting::PluginFactory::PluginFactoryPtr = 
//    Steinberg::IPtr<Steinberg::IPluginFactory>;


public:
  VSTModule();
/*
//move to cpp file when you need this method
  template <typename T>
  T getFunctionPointer(const char* name)
  {
    return reinterpret_cast<T>(dlsym(pluginPtr, name));
  }
*/

  void initialize();

  void setObjectHandle(void* objPtrIn)
  {
    pluginPtr = objPtrIn;
  }

private:
  void* pluginPtr;
  GetFactoryProc myGetFactoryProc;
  VST3::Hosting::PluginFactory* myPluginFactory;
  VST3::Hosting::ClassInfo myCI;
  //add ptr to plugin object?
  

};
}
