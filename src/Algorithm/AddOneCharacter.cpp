#include <Algorithm/AddOneCharacter.hpp>

#include <unordered_map>

#include <Common/CipherCommand.hpp>
#include <Common/Logger.hpp>

namespace src::algo
{
namespace
{

common::Logger logger("AddOneCharacter");

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
    std::unordered_map<char, char> result;
    for (unsigned ctr = 0; ctr < text.size() - 1; ctr++)
    {
        char currentChar = text[ctr];
        char nextChar = text[ctr+1];
        result[currentChar] = nextChar;
    }
    if (!text.empty())
    {
        char lastChar = text[text.size() - 1];
        char firstChar = text[0];
        result[lastChar] = firstChar;
    }
    return result;
}

std::unordered_map<char, char> mapEachCharToThePreviousOne(const std::string& text)
{
    std::unordered_map<char, char> result;
    for (unsigned ctr = 1; ctr < text.size(); ctr++)
    {
        char currentChar = text[ctr];
        char prevChar = text[ctr-1];
        result[currentChar] = prevChar;
    }
    if (!text.empty())
    {
        char firstChar = text[0];
        char lastChar = text[text.size() - 1];
        result[firstChar] = lastChar;
    }
    return result;
}

} // namespace

AddOneCharacter::AddOneCharacter()
{
}

std::string AddOneCharacter::process(
    const common::CipherCommand cipherCommand,
    const std::string& message,
    const std::string& cipherCode)
{
    switch (cipherCommand)
    {
        case common::CipherCommand::Encrypt : return encrypt(message, cipherCode);
        case common::CipherCommand::Decrypt : return decrypt(message, cipherCode);
    }

    logger.print("Error. Unrecognized CipherCommand. Message not processed.");
    return {};
}

std::string AddOneCharacter::encrypt(
    const std::string& message,
    const std::string& cipherCode)
{
    std::string cipherCodeTrimmed = removeRepeatingCharacters(cipherCode);
    std::unordered_map<char, char> cipherCodeNextChar = mapEachCharToTheNextOne(cipherCodeTrimmed);

    std::string encryptedMessage = message;
    for (unsigned ctr = 0; ctr < message.size(); ctr++)
    {
        char currentChar = message[ctr];
        char nextChar = cipherCodeNextChar.count(currentChar) > 0 ?
                            cipherCodeNextChar[currentChar] :
                            currentChar + 1;
        encryptedMessage[ctr] = nextChar;
    }

    logger.print("Message encryption done");
    return encryptedMessage;
}

std::string AddOneCharacter::decrypt(
    const std::string& message,
    const std::string& cipherCode)
{
    std::string cipherCodeTrimmed = removeRepeatingCharacters(cipherCode);
    std::unordered_map<char, char> cipherCodePrevChar = mapEachCharToThePreviousOne(cipherCodeTrimmed);

    std::string decryptedMessage = message;
    for (unsigned ctr = 0; ctr < message.size(); ctr++)
    {
        char currentChar = message[ctr];
        char prevChar = cipherCodePrevChar.count(currentChar) > 0 ?
                            cipherCodePrevChar[currentChar] :
                            currentChar - 1;
        decryptedMessage[ctr] = prevChar;
    }

    logger.print("Message decryption done");
    return decryptedMessage;
}

} // namespace src::algo
