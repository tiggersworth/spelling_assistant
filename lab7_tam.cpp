/***
*  File: a7.cpp
*  Author: Tammy Chang 
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

struct pair {
  std::string name;
  int freq;
};

bool compare(const pair& lhs, const pair& rhs){
  if(lhs.freq == rhs.freq){ 
    //if equal compare by ascii value
    return lhs.name < rhs.name;
  }

  //sort by frequency
  return lhs.freq > rhs.freq;
}

void sortdict(std::vector<pair>& vec){ 
  // sort by freq then sort by value
  std::sort(vec.begin(), vec.end(), compare);
}

bool deletey(std::string namefreq,  std::string duh, int duhduh ){
    std::string temp = namefreq;
    for(int i =0; i < namefreq.size(); ++i){
      if(temp[i] != duh[i]){
      temp.erase(i, 1);
      if(temp.compare(duh) == 0){
          //std::cout << duh << " " << duhduh << std::endl;
        return true;
      }
      else{
        return false;
      }
    }
    }
    //std::cout << duh << " " << duhduh << std::endl;
    return true;
}

bool insert(std::string namefreq, std::string duh, int duhduh){
    std::string temp = namefreq;
    for(int y = 0; y < temp.size(); ++y){ 
        // through vector word
        if(temp[y] != duh[y]){
          temp.insert(y, 1, duh[y] );
          if(temp.compare(duh) == 0){
            //std::cout << duh << " " << duhduh << std::endl;
            return true;
          }
          else{
            return false;
          }
        }
    }
  //std::cout << duh << " " << duhduh << std::endl;
  return true;
}


bool sub(std::string namefreq, std::string duh , int duhduh){
    std::string temp = namefreq;
    for(int y = 0 ; y < temp.size() ; ++y){ 
        //through vector word
        if(temp[y] != duh[y]){
          temp[y] = duh[y]; // substitute
          if(temp.compare(duh) == 0){
            //std::cout << duh << " " << duhduh << std::endl;
            return true;
          }
          else{
            return false;
          }
        }
  }
  //std::cout << duh << " " << duhduh << std::endl;
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<pair> vec;

std::ifstream f(argv[1]);
pair thing;
std::string str1;
int name1;

while(f >>str1 >> name1){ //populate vector
//  pair thing;
//  f >> thing.name >> thing.freq ;
  thing.name = str1;
  thing.freq = name1;
//  std::cout << thing.name << thing.freq << std::endl;
  vec.push_back(thing);
}
f.close();
sortdict(vec); //sort the dict


  std::string namefreq; //making sure my compiling works
 while(std::cin >> namefreq){
//std::cout<< namefreq << std::endl;
bool match = false;
for(int i = 0; i < vec.size(); ++i){
  pair thing;
  if(vec[i].name.compare(namefreq) == 0){ // it exists no modification needed
    std::cout << vec[i].name << " " << vec[i].freq <<std::endl;
    vec[i].freq += 1;
    sortdict(vec);
    match = true;
    break;
  }
}

bool flag = false;

if(match == false){
for(int i = 0; i < vec.size() && !flag; ++i){
    if ((vec[i].name.size() - namefreq.size()) == 1){ //size less than by 1
      //  std::cout << "insert " << namefreq;
        //TAMMY if(insert(namefreq, vec)) { flag = true; } //insert
        if(insert(namefreq, vec[i].name, vec[i].freq)) { flag = true;}
    }
  //if(vec[i].name.size() != namefreq.size())//greater or lesser
    else if((namefreq.size() - vec[i].name.size()) == 1){ //size greater than by 1
      //  std::cout << "delete " << namefreq ;
        if( deletey(namefreq, vec[i].name, vec[i].freq)) {flag = true; } //delete
    }
    else if(namefreq.size() == vec[i].name.size()){ //size is equal
      if (sub(namefreq, vec[i].name, vec[i].freq)) { flag = true; } //substitute
        

    }
}
  //or it still doesnt exist and its greater or lesser by more than 1
  if (!flag){
    thing.name = namefreq;
    thing.freq = 1;
    vec.push_back(thing);
    //std::cout << "-" << std::endl;
  }
}
}
    return 0;
}
