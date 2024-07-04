#include <__config>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <memory>
#include <ostream>
#include <string>
#include <vector>
#include <algorithm>
// have to make myown tuple struct bc the std lib doesnt have the right 
// tuple types
struct Node{
    char letter;
    int count;
    float weight;
    Node* Zero = nullptr;
    Node* One = nullptr;
    bool Visited = false;
};

struct Tree{
    std::unique_ptr<Node> root;
};

void printVec(std::vector<Node> input){
    std::cout<<"Letter | Count | Weights"<<std::endl;
    for(auto & i : input){
        std::cout<<i.letter;
        std::cout<<"      : " + std::to_string(i.count)+ "    : "+std::to_string(i.weight)<<std::endl;
    }
}

void calcWeights(std::vector<Node>& input, int size){
    for(auto &i: input){
        i.weight = static_cast<float>(i.count)/size;
    }
}

void calcFrequency(std::string data, std::vector<Node>& frequency){
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
            Node t;
            t.letter = ch;
            t.count = 1;  // Initialize count to 1 for new characters
            frequency.push_back(t);
        }
    }
}


int main(int argc, char* argv[]){

    const std::string filename = std::string(argv[1]);
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
    std::vector<Node> frequency;
    calcFrequency(data, frequency);
    calcWeights(frequency, data.size());
    printVec(frequency);

    float total = 0.0;
    for(auto &i : frequency){
        total += i.weight;
    }
    std::cout<<"total: " + std::to_string(total) <<std::endl;

    // Build the Minimal Weight Binary Tree
    Tree ensemble;
    Node leaf;
    for(auto &i: data){
        for(auto &node: frequency){
            if(!ensemble.root){
                ensemble.root = std::unique_ptr<Node>();
                ensemble.root->letter = i;
                ensemble.root->count = node.count;
                ensemble.root->weight = node.weight;
            } else {
                // if the count is greater that the current root
                if(node.count > ensemble.root->count){
                    // std::unique_ptr<Node> temp = std::move(ensemble.root);
                    // ensemble.root = std::make_unique<Node>(node);
                    // ensemble.root->Zero = std::move(temp);
                    

                }
                // if the count is less than the current root
                if(node.count < ensemble.root->count){

                }
                // if the count is equal than the current root
                if(node.count == ensemble.root->count){

                }
            }
        }
    }

        

    // }

    return 0;
}