#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Indentation {
  int ind;

 public:
  Indentation(int ind) { this->ind = ind; }

  void readFile() {
    ifstream file("input.cpp");
    string line;

    while (getline(file, line)) {
      format(line);
    }

    file.close();
  }

  void format(string line) {
    string trimmedLine = line;
    size_t start = trimmedLine.find_first_not_of(" \t");
    if (start != string::npos) {
      trimmedLine = trimmedLine.substr(start);
    }

    if (trimmedLine.find('}') != string::npos) {
      ind--;
    }

    for (int i = 0; i < ind; i++) {
      cout << "    ";
    }

    cout << trimmedLine << endl;

    if (trimmedLine.find('{') != string::npos) {
      ind++;
    }
  }

  void output() {
    ifstream file("input.cpp");
    ofstream out("output.cpp");
    string line;
    int tempInd = 0;

    while (getline(file, line)) {
      string trimmedLine = line;
      size_t start = trimmedLine.find_first_not_of(" \t");
      if (start != string::npos) {
        trimmedLine = trimmedLine.substr(start);
      }

      if (trimmedLine.find('}') != string::npos) {
        tempInd--;
      }

      for (int i = 0; i < tempInd; i++) {
        out << "    ";
      }

      out << trimmedLine << endl;

      if (trimmedLine.find('{') != string::npos) {
        tempInd++;
      }
    }
    file.close();
    out.close();
  }
};

int main() {
  Indentation obj(0);
  cout << "Indented Code:" << endl;
  obj.readFile();
  obj.output();
  cout << "\nIndented code has been written to output.cpp" << endl;
  return 0;
}
