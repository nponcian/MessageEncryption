#ifndef SRC_IALGORITHM_HPP
#define SRC_IALGORITHM_HPP

#include <string>

namespace src
{
namespace common
{

enum class CipherCommand;

} // namespace common

namespace algo
{

class IAlgorithm
{
public:
    virtual ~IAlgorithm(){}
    virtual std::string process(
        const common::CipherCommand cipherCommand,
        const std::string& message,
        const std::string& keyCode) = 0;

protected:
    virtual std::string encrypt(
        const std::string& message,
        const std::string& keyCode) = 0;
    virtual std::string decrypt(
        const std::string& message,
        const std::string& keyCode) = 0;
};

} // namespace algo
} // namespace src

#endif // SRC_IALGORITHM_HPP
