#ifndef __TOKEN__
#define __TOKEN__

// includes
#include "Tokens.hpp"
#include <format> // requires c++20
#include <iostream>
#include <string>

class Token
{
private:
  // internal variables
  int m_ntype;
  void *m_value;

public:
  // Initializer
  Token(int type, void *value = NULL)
  {
    m_ntype = type;
    m_value = malloc(sizeof(value));
    *m_value = value;
  }

  // Display the Token
  std::string to_string()
  {
    std::string output;
    if (*m_value != NULL)
    {
      output = std::format("{}:{}", m_ntype, *m_value);
    }
    else
    {
      output = std::format("{}", m_ntype);
    }
    return output;
  }
};

#endif