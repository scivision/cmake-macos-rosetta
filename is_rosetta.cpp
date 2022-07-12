#include <iostream>

#ifdef __APPLE__
#include <sys/sysctl.h>
#endif

bool is_rosetta(){

#ifdef __APPLE__
   int ret = 0;
   size_t size = sizeof(ret);

   if (sysctlbyname("sysctl.proc_translated", &ret, &size, nullptr, 0) < 0)
   {
      if (errno == ENOENT)
         return false;
      throw;
   }

   return (ret == 1);
#else
   return false;
#endif
}

int main(int argc, char ** argv) {

  if (is_rosetta()) {
    std::cout << argv[0] << " is using Rosetta" << std::endl;
  }
  else {
    std::cout << argv[0] << " is not using Rosetta" << std::endl;
  }

  return EXIT_SUCCESS;
}
