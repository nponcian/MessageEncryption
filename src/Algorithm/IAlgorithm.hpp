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
    virtual void process(
        const common::CipherCommand cipherCommand,
        const std::string& fileToCipher,
        const std::string& cipherCode) = 0;
};

} // namespace algo
} // namespace src

#endif // SRC_IALGORITHM_HPP
