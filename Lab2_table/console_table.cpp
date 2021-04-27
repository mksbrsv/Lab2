#include "console_table.h"


//format of command is /show 3 - show 3 key; /play 3 - play 3 key
int console_table::make_command(std::string& command) {
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
	else
		return 1;
}

std::pair<std::string, int> console_table::parse_command(std::string& command) {
	command.erase(0, 1);
	auto command_pos = command.find(" ");
	auto com = command.substr(0, command_pos);
	std::string key = command.substr(command_pos + 1, command.length());
	return std::make_pair(com, std::stoi(key));
}
