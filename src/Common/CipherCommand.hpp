#ifndef SRC_COMMON_CIPHERCOMMAND_HPP
#define SRC_COMMON_CIPHERCOMMAND_HPP

#include <string>

#include <boost/optional.hpp>

namespace src::common
{

enum class CipherCommand
{
    Encrypt,
    Decrypt,
};

boost::optional<CipherCommand> getCipherCommand(const std::string& cipherCommandText);

} // namespace src::common

#endif // SRC_COMMON_CIPHERCOMMAND_HPP
