// MacOS specific

#include <iostream>

#include <sys/sysctl.h>

bool is_rosetta(){
   int ret = 0;
   size_t size = sizeof(ret);

   if (sysctlbyname("sysctl.proc_translated", &ret, &size, NULL, 0) == -1)
   {
      if (errno == ENOENT)
         return false;
      throw;
   }

   return (ret == 1);
}

int main() {

  if (is_rosetta()) {
    std::cout << "Running via Rosetta" << std::endl;
  }
  else {
    std::cout << "Running without Rosetta" << std::endl;
  }

  return EXIT_SUCCESS;
}
