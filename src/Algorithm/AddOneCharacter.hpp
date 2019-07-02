#ifndef SRC_ADDONECHARACTER_HPP
#define SRC_ADDONECHARACTER_HPP

#include <Algorithm/IAlgorithm.hpp>

namespace src::algo
{

class AddOneCharacter : public IAlgorithm
{
public:
    AddOneCharacter();

    virtual std::string process(
        const common::CipherCommand cipherCommand,
        const std::string& message,
        const std::string& cipherCode) override;

protected:
    virtual std::string encrypt(
        const std::string& message,
        const std::string& cipherCode) override;

    virtual std::string decrypt(
        const std::string& message,
        const std::string& cipherCode) override;
};

} // namespace src::algo

#endif // SRC_ADDONECHARACTER_HPP
