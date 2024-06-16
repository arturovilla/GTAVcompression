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
    float weight;
};

void calcWeights(std::vector<Cupling>& input, int size){
    for(auto &i: input){
        i.weight = static_cast<float>(i.count)/size;
    }
}

void calcFrequency(std::string data, std::vector<Cupling>& frequency){
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
}

void printVec(std::vector<Cupling> input){
    std::cout<<"Letter | Count | Weights"<<std::endl;
    for(auto & i : input){
        std::cout<<i.letter;
        std::cout<<"      : " + std::to_string(i.count)+ "    : "+std::to_string(i.weight)<<std::endl;
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


    // find the frequency and weights of all the characters
    std::vector<Cupling> frequency;
    calcFrequency(data, frequency);
    calcWeights(frequency, data.size());
    printVec(frequency);

    float total = 0.0;
    for(auto &i : frequency){
        total += i.weight;
    }
    std::cout<<"total: " + std::to_string(total) <<std::endl;

    return 0;
}