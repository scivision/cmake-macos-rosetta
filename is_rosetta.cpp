#include <iostream>

#if __APPLE__
#include <sys/sysctl.h>

bool is_rosetta(){
   int ret = 0;
   size_t size = sizeof(ret);

   if (sysctlbyname("sysctl.proc_translated", &ret, &size, NULL, 0) < 0)
   {
      if (errno == ENOENT)
         return false;
      throw;
   }

   return (ret == 1);
}
#else
bool is_rosetta(){
   return false;
}
#endif

int main(int argc, char ** argv) {

  if (is_rosetta()) {
    std::cout << argv[0] << " is using Rosetta" << std::endl;
  }
  else {
    std::cout << argv[0] << " is not using Rosetta" << std::endl;
  }

  return EXIT_SUCCESS;
}
