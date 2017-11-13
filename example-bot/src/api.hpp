#pragma once

#include <functional>
#include <map>
#include <string>
#include <tgbot/tgbot.h>


std::string readToken(const std::string& filename);

void initBot(TgBot::Bot& bot);


// �����������, ��������� ����������� ��� �������.
std::map<std::string, std::function<void(TgBot::Bot&, TgBot::CallbackQuery::Ptr)>> getAllCallbacks();

// �����������, ��������� ����������� ��� �������.
std::map<std::string, std::function<void(TgBot::Bot&, TgBot::Message::Ptr)>> getAllCommands();

// �����������, ��������� ����������� ��� �������.
void onAnyMessage(TgBot::Bot& bot, TgBot::Message::Ptr message);
