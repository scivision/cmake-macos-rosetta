// MacOS specific

#include <iostream>

#include <sys/sysctl.h>


bool has_avx2(){
   int ret = 0;
   size_t size = sizeof(ret);

   if (sysctlbyname("hw.optional.avx2_0", &ret, &size, NULL, 0) < 0)
   {
      switch (errno){
        case ENOENT:
        case ENOTSUP:
          return false;
        default:
          throw;
      }
   }

   return (ret == 1);
}


int main() {

  if (has_avx2()) {
    std::cout << " has AVX2" << std::endl;
  }
  else {
    std::cout << " does not have AVX2" << std::endl;
  }

  return EXIT_SUCCESS;
}
