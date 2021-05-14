#include "console_table.h"
#include <string>

// format of command is /show 3 - show 3 key; /play 3 - play 3 key
int console_table::make_command(std::string &command) {
  auto [com, key] = parse_command(command);
  auto it = m_table.find(key);
  if (com == "play") {
    it->value().play();
    return 0;
  }
  if (com == "show") {
    it->value().show();
    return 0;
  }
  if (com == "exit")
    return -1;
  if (com == "quick") {
    m_table.quick();
    return 0;
  }
  if (com == "insertion") {
    m_table.insertion();
    return 0;
  }
  if (com == "merge") {
    m_table.merge();
    return 0;
  } else
    return 1;
}

std::pair<std::string, int> console_table::parse_command(std::string &command) {
  command.erase(0, 1);
  auto command_pos = command.find(" ");
  auto com = command.substr(0, command_pos);
  std::string key;
  if (com == "quick")
    bool a = true;
  if (com == "exit" || com == "quick" || com == "insertion" || com == "merge")
    key = "0";
  else
    key = command.substr(command_pos + 1, command.length());
  return std::make_pair(com, std::stoi(key));
}

void console_table::push(const track &value) { m_table.push_back(value); }

void console_table::print() {
  for (auto it = m_table.begin(); it != m_table.end(); ++it) {
    std::cout << *it << std::endl;
  }
  std::cout << "\b";
}

void console_table::main_f() {
  m_table.load("files.txt");
  std::string command;
  while (true) {
    print();
    std::cout << ">> ";
    std::getline(std::cin, command);
    auto ec = make_command(command);
    if (ec == -1)
      break;
    system("cls");
  }
}
