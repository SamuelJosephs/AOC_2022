#include<vector>
#include<fstream>
#include<iostream>

std::vector<std::string> split(const std::string input, const char delim){
    std::vector<std::string> output(10);
    std::string acc;
    for (auto&& i: input){

        if (i == delim){
            output.push_back(acc);
            acc = std::string("");
            continue;
        }
        acc = acc.append(std::string(1,i));
    }
    output.push_back(acc);
    return output;


}

struct num_pair {
    int x,y;
    num_pair():x(0),y(0){};
    num_pair(int x, int y):x(x),y(y){};
};

std::vector<num_pair> get_input(const char* filename){
    std::ifstream file(filename);
    std::string acc;
    std::vector<num_pair> output;
    std::vector<std::string> num_strings;

    while (std::getline(file,acc)){
        std::vector<std::string> commas = split(acc,',');
        for (auto&& i: commas){
            std::vector<std::string> hyphens = split(i,'-');
            for (auto&& j: hyphens){
                
              
                num_strings.push_back(j);
            }

        }
    }

    // convert num_strings to numbers

    for (int i = 0; i < num_strings.size(); i+=2){
        if (!std::isdigit(num_strings[i][0])){
            continue;
        }
        int x = std::stoi(num_strings[i]);
        int y = std::stoi(num_strings[i+1]);
        num_pair temp(x,y);
        output.push_back(temp);
    }

    return output;
}

int main(){


    std::vector<num_pair> test = get_input("one_input.txt");

    for (int i = 0;i < test.size(); i++) {
        std::cout << test[i].x << " , " << test[i].y << "\n";
    }

    int counter_contains = 0;
    int counter_overlaps = 0;
    // Do the comparisons 
    for (int i = 0; i < test.size(); i+=2){
        num_pair elf1 = test[i];
        num_pair elf2 = test[i+1];

        bool one_contains_two = (elf1.x <= elf2.x) && (elf1.y >= elf2.y);
        bool two_contains_one = (elf2.x <= elf1.x) && (elf2.y >= elf1.y);

        if (one_contains_two || two_contains_one)
            counter_contains++;
        bool overlaps = ((elf1.y >= elf2.x) && (elf1.x <= elf2.y));
        if (overlaps)
            counter_overlaps++;

    }

    std::cout << "The answer to day 4 is:\n" << counter_contains << " contain each other and \n" << counter_overlaps << " overlap each other\n";



}