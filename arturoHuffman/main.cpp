#include <cstring>
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>

// have to make myown tuple struct bc the std lib doesnt have the right 
// tuple types
struct Cupling{
    char letter;
    int count;
};

void printVec(std::vector<Cupling>& input){
    for(auto & i : input){
        std::cout<<i.letter;
        std::cout<<" : " + std::to_string(i.count)<<std::endl;
    }
}

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
    for (char ch : data) {
        bool found = false;
        for (auto &element : frequency) {
            if (element.letter == ch) {
                element.count += 1;
                found = true;
                break;
            }
        }
        if (!found) {
            Cupling t;
            t.letter = ch;
            t.count = 1;  // Initialize count to 1 for new characters
            frequency.push_back(t);
        }
    }

    printVec(frequency);

    return 0;
}