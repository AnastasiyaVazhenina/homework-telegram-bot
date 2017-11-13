#include "api.hpp"
#include "keyboard.hpp"
#include "utils.hpp"

// ����, ��� ������������ ������ � ��������� � ������� �����������

using namespace std;
using namespace TgBot;
using namespace Utils;


// ������� ��� ������������ ������ � ���������
// ������� ���������� ������ ���, ����� �������� ���������, ������� ���������� �� /start
void onCommandStart(Bot& bot, Message::Ptr message)
{
    bot.getApi().sendMessage(message->chat->id, "Hi!");
}

// ������� ��� ������������ ������ � ���������
// ������� ���������� ������ ���, ����� �������� ���������, ������� ���������� �� /end
void onCommandEnd(Bot& bot, Message::Ptr message)
{
    bot.getApi().sendMessage(message->chat->id, "Bye!");
}

// ������������ �������
std::map<std::string, std::function<void(Bot&, Message::Ptr)>> getAllCommands()
{
    // ������ �������� ������������� �������
    // ��������� �������� �������-���������� ��������
    // ��������, ��� ��������� ������� /end ��������� ������� onCommandEnd
    std::map<std::string, std::function<void(Bot&, Message::Ptr)>> commands =
    {
        {"start", onCommandStart},
        {"end", onCommandEnd},
        {"keyboard", onCommandKeyboard}
    };

    return commands;
}



// �������, ������� ���������� ��� ����� ���������
void onAnyMessage(Bot& bot, Message::Ptr message)
{
    // ��������� �������� � �������
    printf("User wrote %s\n", message->text.c_str());

    // ���������� ���������, ������� ���������� � /start � /end
    if (StringTools::startsWith(message->text, "/start"))
    {
        return;
    }
    if (StringTools::startsWith(message->text, "/end"))
    {
        return;
    }

    // ���� � ������ ��������� ���� "������" ������������ �����������
    std::string hello = Utils::fromLocale("������");
    if (message->text.find(hello) != std::string::npos)
    {
        bot.getApi().sendMessage(message->chat->id, Utils::fromLocale("������, ") + message->from->firstName);
        return;
    }

    // ���������� ���������, ������� ��������
    bot.getApi().sendMessage(message->chat->id, message->from->username + ": " + message->text);
}

