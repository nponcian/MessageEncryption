#include <Controller.hpp>

#include <string>

#include <Algorithm/AddOneCharacter.hpp>
#include <Algorithm/IAlgorithm.hpp>
#include <Common/CipherCommand.hpp>
#include <Common/Logger.hpp>
#include <File/FileHandler.hpp>

namespace src
{
namespace
{

common::Logger logger("Controller");

} // namespace

Controller::Controller()
{
}

void Controller::handle(
    const std::string& cipherCommandText,
    const std::string& fileToCipher,
    const std::string& cipherCode,
    const std::string& algorithmId)
{
    // ./cipher --encrypt ./fileWithMessage.txt code algorithmID
    auto cipherCommand = common::getCipherCommand(cipherCommandText);
    auto message = file::readContentsOfFile(fileToCipher);
    auto algorithm = createAlgorithm(algorithmId);

    if (cipherCommand && algorithm)
    {
        auto processedMessage = algorithm->process(cipherCommand.get(), message, cipherCode);
        file::writeContentsToFile(fileToCipher + ".output", processedMessage);
    }
    else
    {
        logger.print("Unsupported input");
        logger.print("Try with --help to display usage, sample command: ./cipher_src --help");
    }
}

std::unique_ptr<algo::IAlgorithm> Controller::createAlgorithm(const std::string& algorithmId)
{
    if (algorithmId == "1") return std::make_unique<algo::AddOneCharacter>();

    return nullptr;
}

} // namespace src
