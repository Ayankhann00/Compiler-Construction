#include <iostream>
#include <string>
using namespace std;

const int NSTATES = 3;
const int NCHARS = 128;
const int INITIAL = 0;
const int ERR = -1;
int main() {
  int transition_table[NSTATES][NCHARS];
  int accept_states[NSTATES] = {0, 0, 1};
  for (int i = 0; i < NSTATES; i++) {
    for (int j = 0; i < NCHARS; j++) {
    transition_table[i][j] = ERR;
    }
  }
  transition_table[0]['a'] = 1;
  transition_table[1]['b'] = 2;

  string input;
  cout << "Enter input: ";
  cin >> input;

  int state = INITIAL;

  for (int i = 0; i < input.length(); i++) {
    char c = input[i];
    transition_table[state][c];
    if (state == ERR) {
      break;
    }
  }
  if (state != ERR && accept_states[state]) {
    cout << "Accepted" << "\n";
  } else {
    cout << "rejected" << "\n";
  }

  return 0;
}
