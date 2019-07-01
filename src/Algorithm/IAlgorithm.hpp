#ifndef SRC_IALGORITHM_HPP
#define SRC_IALGORITHM_HPP

#include <string>

namespace src::algo
{

enum class CipherCommand
{
    Encrypt,
    Decrypt,
};

class IAlgorithm
{
public:
    virtual ~IAlgorithm(){}
    virtual void process(
        const CipherCommand cipherCommand,
        const std::string& fileToCipher,
        const std::string& cipherCode) = 0;
};

} // namespace src::algo

#endif // SRC_IALGORITHM_HPP
