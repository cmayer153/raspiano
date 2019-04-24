#include <cstdio>
#include <iostream>

#include "minimal_host.h"

using namespace Raspiano;

int main(int argc, char* argv[])
{
  std::cout << "Starting Host..." << std::endl;
  MinimalHost* myHost = new MinimalHost();
  return 0;
}
