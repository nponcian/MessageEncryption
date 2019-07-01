#include <Algorithm/AddOneCharacter.hpp>

#include <Common/Logger.hpp>

namespace src::algo
{
namespace
{

common::Logger logger("AddOneCharacter");

} // namespace

AddOneCharacter::AddOneCharacter()
{
}

void AddOneCharacter::process(
    const CipherCommand,// cipherCommand,
    const std::string&,// fileToCipher,
    const std::string&)// cipherCode)
{
    logger.print("process called");
}

} // namespace src::algo
