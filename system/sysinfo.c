#include <pwd.h>
#include <unistd.h>
#include <sys/user.h>
#include <sys/utsname.h>

unsigned int GetLogicalCpuNumber()
{
     return sysconf(_SC_NPROCESSORS_ONLN);
}
 
unsigned long long GetPhysicalMemorySize()
{
     return sysconf(_SC_PHYS_PAGES) * (unsigned long long) PAGE_SIZE;
 }
  
 static const struct utsname* GetUnameInfo()
 {
     static struct utsname uts;
     if (uname(&uts) == -1)
         return NULL;
 
     return &uts;
 }
 
 bool GetOsKernelInfo(std::string* kernerl_info)
 {
     const struct utsname* uts = GetUnameInfo();
     if (uts != NULL) {
         kernerl_info->assign(uts->release);
         return true;
     }
 
     return false;
 }
 
 bool GetMachineArchitecture(std::string* arch_info)
 {
     const struct utsname* uts = GetUnameInfo();
     if (uts != NULL) {
         arch_info->assign(uts->machine);
         return true;
     }
 
     return false;
 }
