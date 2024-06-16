#include <iostream>
#include <fstream>
#include <list>
#include <ostream>
#include <string>
#include <vector>
// have to make myown tuple struct bc the std lib doesnt have the right 
// tuple types
struct Cupling{
    char characterD;
    int count;
};


int main(){

    const std::string filename = "test1.txt";
    // read in file contents
    std::fstream testfile(filename, std::fstream::in);
    if(!testfile.is_open()){
        std::cerr << "failed to open " + filename<<std::endl;
        return 1;
    }

    std::string line;
    std::string data;

    while(std::getline(testfile,line)){
        data.append(line);
    }
    testfile.close();

    // find the frequency of all the characters
    std::vector<Cupling> frequency;

    return 0;
}