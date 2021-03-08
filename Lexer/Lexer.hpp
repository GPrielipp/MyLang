#ifndef __LEXER__
#define __LEXER__

// includes
#include "../Tokens/Token.hpp"
#include "../Tokens/Tokens.hpp"
#include <string>
#include <vector>

#define DIGITS std::string("0123456789")
#define NOT_FOUND std::string::npos

struct Position
{
  int row = 0;
  int col = 0;
};

class Lexer
{
private:
  std::string m_stext;
  char current_char;
  Position pos;

public:
  //constructor
  Lexer(std::string text)
  {
    m_stext = text;
    current_char = NULL;
    pos = *(Position *)malloc(sizeof(Position));
    pos.col = -1;
    advance();
  }

  void advance()
  {
    pos.col++;
    if (pos.col < m_stext.length())
    {
      current_char = m_stext.at(pos.col);
    }
    else
    {
      current_char = NULL;
    }
  }

  std::vector<Token> make_tokens()
  {
    std::vector<Token> tokens = *new std::vector<Token>();

    while (current_char != NULL)
    {
      if (current_char == ' ' || current_char == '\t')
        continue;
      else if (DIGITS.find(current_char) != NOT_FOUND)
      {
        tokens.append(make_number());
      }
      else if (current_char == '+')
      {
        tokens.append(*new Token(TOKENS::PLUS));
        advance();
      }
      else if (current_char == '-')
      {
        tokens.append(*new Token(TOKENS::MINUS));
        advance();
      }
      else if (current_char == '*')
      {
        tokens.append(*new Token(TOKENS::MULTIPLY));
        advance();
      }
      else if (current_char == '/')
      {
        tokens.append(*new Token(TOKENS::DIVIDE));
        advance();
      }
      else if (current_char == '(')
      {
        tokens.append(*new Token(TOKENS::L_PAREN));
        advance();
      }
      else if (current_char == ')')
      {
        tokens.append(*new Token(TOKENS::R_PAREN));
        advance();
      }
    }

    return tokens;
  }

  // return Token("int") or Token("float")
  Token make_number()
  {
    int dot_count = 0;
    std::string number_str = "";

    while (current_char != NULL &&
           (DIGITS + '.').find(current_char) != NOT_FOUND)
    {
      if (current_char == '.')
      {
        if (dot_count == 1)
          break;
        dot_count++;
      }
      // always append the number and '.'
      number_str += current_char;
    }

    if (dot_count == 0)
    {
      return *new Token(TOKENS::INT, (void *)std::stoi(number_string))
    }
    else
    {
      return *new Token(TOKENS::FLOAT, (void *)std::stof(number_string));
    }
  }
};

#endif