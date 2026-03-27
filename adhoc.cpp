#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum TokenType { TID, TNUM, T_EOF, T_PLUS, T_ERR, T_STR };

struct Token {
  TokenType type;
  string value;
  Token(TokenType t, std::string v) : type(t), value(v) {}
};

class Lexer {
  istream& s;
  int next;

 public:
  Lexer(istream& _s) : s(_s) { advance(); }

  void advance() { next = s.get(); }

  Token nextToken() {
    while (isspace(next)) {
      advance();
    }

    if (next == EOF) return Token(T_EOF, "");

    if (idChar(next)) return readId();
    if (isdigit(next)) return readNumber();
    if (next == '"') return readString();

    if (next == '+') {
      advance();
      return Token(T_PLUS, "+");
    }

    string err(1, (char)next);
    advance();
    return Token(T_ERR, err);
  }

  Token readId() {
    string id = "";
    while (next != EOF && idChar(next)) {
      id += (char)next;
      advance();
    }
    return Token(TID, id);
  }

  Token readNumber() {
    string num = "";
    while (next != EOF && isdigit(next)) {
      num += (char)next;
      advance();
    }
    return Token(TNUM, num);
  }

  Token readString() {
    string str = "";
    advance();
    while (next != EOF && next != '"') {
      str += (char)next;
      advance();
    }
    advance();
    return Token(T_STR, str);
  }

  bool idChar(char c) { return isalnum(c) || c == '_'; }
};
int main() {
  Lexer lex(cin);
  Token t = lex.nextToken();

  while (t.type != T_EOF) {
    cout << t.value << endl;
    t = lex.nextToken();
  }
}