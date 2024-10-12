#include <iostream>
#include <string>
#include <map>

class File{
  private :
    std::string _fileName;
    bool status; 
    std::string _content;
    
  public :
    File(const std::string& fileName, const std::string& content) : _fileName(fileName), _content(content){
      std::cout << "Creating file : " << _fileName << std::endl;     
    }
    
    std::string readFile(std::string) const{
      return _content;    
    }
    
    bool writeFile(std::string){
      return true;    
    }
    
    std::string getName() const{
      return _fileName;
    }
};

class Directory{
  private :
    std::string _dirName;
    std::map<std::string, File*> _files;
    
  public :
    Directory(std::string dirName) : _dirName(dirName){
      std::cout << "Creating directory : " << _dirName << std::endl;    
    }
    
    bool createFile(std::string fileName, std::string content){
      if(_files.find(fileName) != _files.end()){
        std::cout <<"file already exists\n";
        return false;
      }
      File *file = new File(fileName, content);
      _files[fileName] = file;
      return true;    
    }
    
    bool removeFile(std::string){
      return true;    
    }
    
    void listFiles() const{
        return;
    }
    
    File* getFile(const std::string& fileName){
        return nullptr;
    }
     
};

class FileSystem{
  private :
    std::map<std::string, Directory*> _dirs;
    std::string _fs_name;
    
  public :
    FileSystem(std::string fs_name) : _fs_name(fs_name){
      std::cout << "Creating filesystem : " << _fs_name << std::endl;    
    }
    
    bool createDirectory(std::string dirName){
      if(_dirs.find(dirName) == _dirs.end()){
        Directory *dir = new Directory(dirName);
        _dirs[dirName] = dir;
        return 1;
      } else{
          std::cout << "Dir exists\n";
          return 0;
      }
    }
    
    bool removeDirectory(std::string dirName){
        return true;
    };
    
    void listDirectories(){
        
    }
    
    Directory* getDirectory(const std::string& dirName){
        return nullptr;
    }
};

int main()
{
    std::cout<<"Hello World\n";
    
    FileSystem *fs = new FileSystem("fs");
    fs->createDirectory("dir1");
    
    Directory *dir2 = new Directory("dir2");
    fs->createDirectory("dir3");
    
    fs->removeDirectory("dir1");
    
    dir2->createFile("file1","hey");
    
    File *file2 = new File("file2","hi");
    dir2->createFile("file3","bye");
    file2->readFile("file2");
    file2->writeFile("file2");
    file2->readFile(file2->getName());
    
    dir2->removeFile("file2");
    
    return 0;
}
