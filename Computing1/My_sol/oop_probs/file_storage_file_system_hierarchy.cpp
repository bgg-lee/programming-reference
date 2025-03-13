/*
You are simulating a File System that has Files and Directories. Both are “nodes” in a tree-like structure. A File has a size, while a Directory can contain multiple child nodes (which can be files or directories). We want to store them in a container, and do operations like computing total size, listing content, etc.
Key OOP:
    FileSystemNode (abstract) – has a name, a virtual destructor, a pure virtual size() method.
    File (derived) – has a size_t fileSize. size() returns that.
    Directory (derived) – has a std::vector<std::unique_ptr<FileSystemNode>> children;. size() returns the sum of the children’s sizes. Also has methods addNode(...).
    Possibly virtual void printInfo(int indentLevel) const; to show a tree structure.
*/
/*********************************************************
 * FileSystem.cpp
 * Demonstrates a simple file system hierarchy:
 * FileSystemNode (abstract), File, Directory
 *********************************************************/

 #include <iostream>
 #include <string>
 #include <vector>
 #include <memory>
 
 //------------------------------------------------
 // 1) Abstract Base: FileSystemNode
 //------------------------------------------------
 class FileSystemNode {
 protected:
     std::string name;
 
 public:
     FileSystemNode(const std::string& n) : name(n) {}
     virtual ~FileSystemNode() {}
 
     virtual size_t size() const = 0;
     virtual void printInfo(int indent=0) const = 0;
 };
 
 //------------------------------------------------
 // 2) Derived: File
 //------------------------------------------------
 class File : public FileSystemNode {
 private:
     size_t fileSize;
 
 public:
     File(const std::string& n, size_t sz)
         : FileSystemNode(n), fileSize(sz) {}
 
     size_t size() const override {
         return fileSize;
     }
 
     void printInfo(int indent=0) const override {
         std::string spacing(indent, ' ');
         std::cout << spacing << "File: " << name
                   << " (" << fileSize << " bytes)\n";
     }
 };
 
 //------------------------------------------------
 // 3) Derived: Directory
 //------------------------------------------------
 class Directory : public FileSystemNode {
 private:
     std::vector<std::unique_ptr<FileSystemNode>> children;
 
 public:
     Directory(const std::string& n) : FileSystemNode(n) {}
 
     size_t size() const override {
         size_t total = 0;
         for(const auto &child : children) {
             total += child->size();
         }
         return total;
     }
 
     void addNode(std::unique_ptr<FileSystemNode> node) {
         children.push_back(std::move(node));
     }
 
     void printInfo(int indent=0) const override {
         std::string spacing(indent, ' ');
         std::cout << spacing << "Directory: " << name
                   << " (total size=" << size() << ")\n";
         for(const auto &child : children) {
             child->printInfo(indent + 2);
         }
     }
 };
 
 //------------------------------------------------
 // main() - Test
 //------------------------------------------------
 int main() {
     // Create a root directory
     auto root = std::make_unique<Directory>("root");
 
     // Add some files
     root->addNode(std::make_unique<File>("readme.txt", 100));
     root->addNode(std::make_unique<File>("notes.doc", 5000));
 
     // Add a subdirectory "src"
     auto srcDir = std::make_unique<Directory>("src");
     srcDir->addNode(std::make_unique<File>("main.cpp", 2000));
     srcDir->addNode(std::make_unique<File>("utils.cpp", 1500));
 
     // Insert the subdirectory into root
     root->addNode(std::move(srcDir));
 
     // Print
     root->printInfo();
 
     std::cout << "Total size of root = " << root->size() << " bytes\n";
 
     return 0;
 }
 