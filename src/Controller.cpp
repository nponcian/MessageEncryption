#include <Controller.hpp>

#include <string>

#include <Algorithm/AddOneCharacter.hpp>
#include <Algorithm/IAlgorithm.hpp>
#include <Common/CipherCommand.hpp>
#include <Common/Logger.hpp>

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
    auto algorithm = createAlgorithm(algorithmId);

    if (cipherCommand && algorithm)
    {
        algorithm->process(cipherCommand.get(), fileToCipher, cipherCode);
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
