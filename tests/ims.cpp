#include <iostream> 
#include <sys/types.h>
#include <sys/stat.h>

struct stat info;

int dir_exists(const char* path) {
if( stat( path, &info ) != 0 )
   return -1 ;
else if( info.st_mode & S_IFDIR )  // S_ISDIR() doesn't exist on my windows 
  return 0;
else
   return 1;
}

int main( ) 
{
    const char* path = "C:\\p\\";
     printf("%d\n", dir_exists(path));
    return -1;
}