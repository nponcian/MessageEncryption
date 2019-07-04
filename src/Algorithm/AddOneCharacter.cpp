#include <Algorithm/AddOneCharacter.hpp>

#include <unordered_map>

#include <Common/CipherCommand.hpp>
#include <Common/Logger.hpp>

namespace src::algo
{
namespace
{

common::Logger logger("AddOneCharacter");

const char KEYCODE_ID = '1';
const char NON_KEYCODE_ID = 'I';

std::string removeRepeatingCharacters(const std::string& text)
{
    std::string result;
    for (const auto& ch : text)
    {
        if (result.find(ch) == std::string::npos)
        {
            result = result + ch;
        }
    }
    return result;
}

std::unordered_map<char, char> mapEachCharToTheNextOne(const std::string& text)
{
    if (text.empty()) return {};

    std::unordered_map<char, char> result;
    for (unsigned ctr = 0; ctr < text.size() - 1; ctr++)
    {
        char currentChar = text[ctr];
        char nextChar = text[ctr+1];
        result[currentChar] = nextChar;
    }

    char lastChar = text[text.size() - 1];
    char firstChar = text[0];
    result[lastChar] = firstChar;

    return result;
}

std::unordered_map<char, char> mapEachCharToThePreviousOne(const std::string& text)
{
    if (text.empty()) return {};

    std::unordered_map<char, char> result;
    for (unsigned ctr = 1; ctr < text.size(); ctr++)
    {
        char currentChar = text[ctr];
        char prevChar = text[ctr-1];
        result[currentChar] = prevChar;
    }

    char firstChar = text[0];
    char lastChar = text[text.size() - 1];
    result[firstChar] = lastChar;

    return result;
}

} // namespace

AddOneCharacter::AddOneCharacter()
{
}

std::string AddOneCharacter::process(
    const common::CipherCommand cipherCommand,
    const std::string& message,
    const std::string& keyCode)
{
    switch (cipherCommand)
    {
        case common::CipherCommand::Encrypt : return encrypt(message, keyCode);
        case common::CipherCommand::Decrypt : return decrypt(message, keyCode);
    }

    logger.print("Error. Unrecognized CipherCommand. Message not processed.");
    return {};
}

std::string AddOneCharacter::encrypt(
    const std::string& message,
    const std::string& keyCode)
{
    std::string keyCodeTrimmed = removeRepeatingCharacters(keyCode);
    std::unordered_map<char, char> keyCodeNextChar = mapEachCharToTheNextOne(keyCodeTrimmed);

    std::string encryptedMessage = "";
    for (unsigned ctr = 0; ctr < message.size(); ctr++)
    {
        char currentChar = message[ctr];
        char id;
        char nextChar;
        if (keyCodeNextChar.count(currentChar) > 0)
        {
            id = KEYCODE_ID;
            nextChar = keyCodeNextChar[currentChar];
        }
        else
        {
            id = NON_KEYCODE_ID;
            nextChar = currentChar + 1;
        }
        encryptedMessage = encryptedMessage + id + nextChar;
    }

    logger.print("Message encryption done");
    return encryptedMessage;
}

std::string AddOneCharacter::decrypt(
    const std::string& message,
    const std::string& keyCode)
{
    std::string keyCodeTrimmed = removeRepeatingCharacters(keyCode);
    std::unordered_map<char, char> keyCodePrevChar = mapEachCharToThePreviousOne(keyCodeTrimmed);

    std::string decryptedMessage = "";
    for (unsigned ctr = 1; ctr < message.size(); ctr=ctr+2)
    {
        char currentChar = message[ctr];
        char prevChar;
        if (keyCodePrevChar.count(currentChar) > 0 &&
            message[ctr-1] == KEYCODE_ID)
        {
            prevChar = keyCodePrevChar[currentChar];
        }
        else
        {
            prevChar = currentChar - 1;
        }
        decryptedMessage = decryptedMessage + prevChar;
    }

    logger.print("Message decryption done");
    return decryptedMessage;
}

} // namespace src::algo
