#include <iostream>
#include <fstream>
#include <vector>
#include <string>
/*
modifications
-add continuous asking
-

*/

//globals
std::vector<std::string> classes;
std::vector<std::string> prereqs;
int count;
std::string chosen_class;

//fcns
void findPrereq(void);

int main(int argc, char *argv[]) {

  //std::string chosen_class;

  std::cout << "Welcome to the Prereq checker!" << std::endl;
  
  std::ifstream input_file;
  std::string each_class;
  std::string each_line;
  std::vector<std::string> read_file;

  std::string file_name = "prereq_list.txt";
  input_file.open(file_name);
  while (getline(input_file, each_line)) {
    read_file.push_back(each_line);
  }
  input_file.close();
  //not reading the file right
  for (auto l : read_file) {
    classes.push_back(l.substr(0, l.find('|')));
    prereqs.push_back(l.substr(l.find('|') + 1));
    count++;
  }
  
  /*for (int y = 0; y < count; y++) {
    std::cout << prereqs[y] << std::endl;
  }*/
  
  findPrereq();

  return 0;

} //end main


void findPrereq(void) {
  
  std::string answer;
  std::cout << "What class would you like to include the prerequsite for?" <<  std::endl;
  std::cin >> chosen_class;
  std::cout << chosen_class << std::endl;
  for (int a = 0; a < count; a++) {
      if (classes[a] == chosen_class) {
      	  answer = prereqs[a];
          std::cout << prereqs[a] << std::endl;
      }
  } 
}

