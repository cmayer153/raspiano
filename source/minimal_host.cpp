#include "minimal_host.h"
#include <iostream>
#include <dlfcn.h>

namespace Raspiano
{
MinimalHost::MinimalHost()
  //vstPath("/home/chris/Downloads/VST_SDK/hw_build/VST3/Debug/hostchecker.vst3/Contents/x86_64-linux/hostchecker.so")
{
  std::cout << "Building MinimalHost..." << std::endl;

  std::string pathName = "/home/chris/Downloads/VST_SDK/hw_build/VST3/Debug/hostchecker.vst3/Contents/x86_64-linux/hostchecker.so";

  vstPath = std::experimental::filesystem::path (pathName);

  void* vstObjectHandle = dlopen(vstPath.generic_string().data(), RTLD_LAZY);

  if (!vstObjectHandle)
  {
    std::cout << "dlopen failed" << std::endl;
  }
  else
  {
    myModule = new VSTModule();
    myModule->setObjectHandle(vstObjectHandle);
    myModule->initialize();
  }
}

}
