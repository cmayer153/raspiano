#include "public.sdk/source/vst/hosting/module.h"


namespace Raspiano
{
class VSTModule
{
  typedef void* (*get_plugin_factory)();


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
  get_plugin_factory myGetFactory;
  

};
}
