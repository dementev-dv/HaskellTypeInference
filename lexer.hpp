#ifndef LEXER_HPP_
#define LEXER_HPP_

#include <string>
#include <iostream>

enum Tag {
  START,
  ID,
  NUM,
  EQ,
  LPAR,
  RPAR,
  COLON,
  LBRAC,
  RBRAC,
  PLUS,
  MINUS,
  MUL,
  DIV,        // can also be lamda?
  WILD,
  END,
  ERROR
};

class Token {
 public:
  Token(Tag t, std::string v)
    : tag_(t), val_(v) {
    // std::cout << val_ << std::endl;
  }

  Tag tag() { return tag_; }
  std::string str() { return val_; }

 private:
  Tag tag_;
  std::string val_;
};

class Lexer {
 public:
  Lexer(std::string in) : in_(in) {
    // std::cout << in_ << std::endl;
  }

  Token Next() {
    while(pos_ < in_.size() && isspace(in_[pos_])) {
      pos_++;
    }

    if (pos_ >= in_.size())
      return Token(END, "");

    char curr = in_[pos_];

    if (isdigit(curr)) {
      std::string num;
      while (pos_ < in_.size() && isdigit(in_[pos_])) {
        num += in_[pos_];
        pos_++;
      }
      return Token(NUM, num);
    }

    if (isalpha(curr)) {
      std::string id;
      while (pos_ < in_.size() && isalpha(in_[pos_])) {
        id += in_[pos_];
        pos_++;
      }
      return Token(ID, id);
    }

    pos_++;
    switch (curr) {
      case ':': return Token(COLON, ":");
      case '=': return Token(EQ, "=");
      case '[': return Token(LBRAC, "[");
      case ']': return Token(RBRAC, "]");
      case '+': return Token(PLUS, "+");
      case '-': return Token(MINUS, "-");
      case '*': return Token(MUL, "*");
      case '/': return Token(DIV, "/");
      case '(': return Token(RPAR, "(");
      case ')': return Token(LPAR, ")");
      case '_': return Token(WILD, "_");
      default: return Token(ERROR, std::string(1, curr));
    }

    return Token(ERROR, std::string(1, curr));
  }

 private:
  std::string in_;
  unsigned pos_;
};

#endif // LEXER_HPP_
