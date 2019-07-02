#ifndef SRC_ADDONECHARACTER_HPP
#define SRC_ADDONECHARACTER_HPP

#include <Algorithm/IAlgorithm.hpp>

namespace src::algo
{

class AddOneCharacter : public IAlgorithm
{
public:
    AddOneCharacter();

    virtual void process(
        const common::CipherCommand cipherCommand,
        const std::string& fileToCipher,
        const std::string& cipherCode) override;
};

} // namespace src::algo

#endif // SRC_ADDONECHARACTER_HPP
