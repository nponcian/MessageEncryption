#include <Common/CipherCommand.hpp>

namespace src::common
{

boost::optional<CipherCommand> getCipherCommand(const std::string& cipherCommandText)
{
    if (cipherCommandText == "--encrypt")      return CipherCommand::Encrypt;
    else if (cipherCommandText == "--decrypt") return CipherCommand::Decrypt;

    return boost::none;

}

} // namespace src::common
