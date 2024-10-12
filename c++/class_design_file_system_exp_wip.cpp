#include <iostream>

class FileSystem{
  private :
    std::map<std::string, bool> dirs;
    
  public :
    createDirectory();
    removeDirectory();
};

class Directory{
  private :
    std::map<std::string, bool> files;
  public :
    createFile();
    removeFile();
     
};

class File{
  private :

  public :
    readFile();
    writeFile();  
};

int main()
{
    std::cout<<"Hello World\n";
    
    FileSystem *fs = new FileSystem();
    fs->createDirectory(new Directory dir1());
    
    Directory *dir2 = new Directory();
    fs->createDirectory(dir1);
    
    fs->removeDirectory(dir1);
    
    dir2->createFile(new File file1());
    
    File *file2 = new File();
    dir2->createFile(file2);
    file2->readFile();
    file2->writeFile();
    file2->readFile();
    
    dir2->removeFile(file2);
    
    return 0;
}
