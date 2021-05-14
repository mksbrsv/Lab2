#ifndef CONSOLE_TABLE_H
#define CONSOLE_TABLE_H
#include "sort_table.h"
#include "track.h"
class console_table {
public:
  console_table() = default;
  int make_command(std::string &command);
  std::pair<std::string, int> parse_command(std::string &command);
  void push(const track &value);
  void print();
  void main_f();

private:
  sort_table<int, track> m_table;
};
#endif
