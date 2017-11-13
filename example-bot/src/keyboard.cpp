#include "api.hpp"
#include "utils.hpp"

// ����, ��� ������������ ������ � �����������

using namespace std;
using namespace TgBot;
using namespace Utils;


// ������� ��� ������������ ������ � Inline Keyboard 
// https://core.telegram.org/bots/2-0-intro
// ��� ������ ���������� �������� ��������� /keyboard
void onCommandKeyboard(Bot& bot, Message::Ptr message)
{
    // ������� ������ ����������
    InlineKeyboardMarkup::Ptr keyboard(new InlineKeyboardMarkup);

    // ������� ����� ������ � ����������
    // ������� ������
    vector<InlineKeyboardButton::Ptr> row0;

    // ������� ������
    InlineKeyboardButton::Ptr buttonOne(new InlineKeyboardButton);
    // ���� ������
    buttonOne->text = "text button one";
    // ��������� ������������� ������
    // ��� ������� �� ������ ����� ��������� ������ ���� �����
    // ������ ������� getAllCallbacks
    buttonOne->callbackData = "id_button_one";

    InlineKeyboardButton::Ptr buttonTwo(new InlineKeyboardButton);
    // ����� ������� ������� �����, ���� ������������ ������� fromLocale
    buttonTwo->text = fromLocale("������ 2");
    buttonTwo->callbackData = "id_button_two";

    // ��������� ������ �� ������
    row0.push_back(buttonOne);
    row0.push_back(buttonTwo);

    // ��������� ������ ������ � ����������
    keyboard->inlineKeyboard.push_back(row0);


    // ������� ��� ������ � ����������
    vector<InlineKeyboardButton::Ptr> row1;

    InlineKeyboardButton::Ptr buttonThree(new InlineKeyboardButton);
    buttonThree->text = fromLocale("������ 3 �� ������ ������");
    buttonThree->callbackData = "id_button_three";

    row1.push_back(buttonThree);
    keyboard->inlineKeyboard.push_back(row1);

    // �������� ��������� ������ � �����������
    bot.getApi().sendMessage(message->chat->id, "Keyboard is showed!", false, 0, keyboard, "Markdown");
}

// ������� ���������� ������ ���, ����� �������� �� ������ 1
// (� ������ � callbackData == id_button_one)
void onClickButtonOne(Bot& bot, CallbackQuery::Ptr query)
{
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("�� ������ �� ������ 1 � ���������������: ") + query->data);
}

// ������� ���������� ������ ���, ����� �������� �� ������ 2 � 3
void onClickButton2or3(Bot& bot, CallbackQuery::Ptr query)
{
    bot.getApi().sendMessage(query->message->chat->id, fromLocale("�� ������ �� ������ 2 ��� 3"));
}

// ������������ ���� ������
std::map<std::string, std::function<void(Bot&, CallbackQuery::Ptr)>> getAllCallbacks()
{
    // ������ �������� ������������� ������
    // ��������� �������� �������-���������� ������
    // �.�. ��� ������� �� ������ � ���������������, ���������� ����� ��������������� �������
    // ��������, ��� ������� �� ������ � ��������������� id_button_one ��������� ������� onClickButtonOne
    std::map<std::string, std::function<void(Bot&, CallbackQuery::Ptr)>> callbacks =
    {
        {"id_button_one", onClickButtonOne},
        {"id_button_two", onClickButton2or3},
        {"id_button_three", onClickButton2or3}
    };

    return callbacks;
}

