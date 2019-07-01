#include <Dispatcher.hpp>

#include <string>

#include <Algorithm/AddOneCharacter.hpp>
#include <Algorithm/IAlgorithm.hpp>
#include <Common/Logger.hpp>

namespace src
{
namespace
{

common::Logger logger("Dispatcher");

} // namespace

Dispatcher::Dispatcher()
{
}

void Dispatcher::dispatch(
    const std::string& cipherCommand,
    const std::string& fileToCipher,
    const std::string& cipherCode,
    const std::string& algorithmId)
{
    // ./cipher --encrypt ./fileWithMessage.txt code algorithmID
    auto command = getCipherCommand(cipherCommand);
    auto algorithm = createAlgorithm(algorithmId);

    if (command && algorithm)
    {
        algorithm->process(command.get(), fileToCipher, cipherCode);
    }
    else
    {
        logger.print("Unsupported input");
        logger.print("Try with --help to display usage, sample command: ./cipher_src --help");
    }
}

boost::optional<algo::CipherCommand> Dispatcher::getCipherCommand(const std::string& cipherCommand)
{
    if (cipherCommand == "--encrypt")      return algo::CipherCommand::Encrypt;
    else if (cipherCommand == "--decrypt") return algo::CipherCommand::Decrypt;

    return boost::none;

}

std::unique_ptr<algo::IAlgorithm> Dispatcher::createAlgorithm(const std::string& algorithmId)
{
    if (algorithmId == "1") return std::make_unique<algo::AddOneCharacter>();

    return nullptr;
}

} // namespace src
