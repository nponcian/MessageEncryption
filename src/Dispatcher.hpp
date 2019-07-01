#ifndef SRC_DISPATCHER_HPP
#define SRC_DISPATCHER_HPP

#include <memory>

#include <boost/optional.hpp>

namespace src
{
namespace algo
{

enum class CipherCommand;

class IAlgorithm;

} // namespace algo

class Dispatcher
{
public:
    Dispatcher();

    void dispatch(
        const std::string& cipherCommand,
        const std::string& fileToCipher,
        const std::string& cipherCode,
        const std::string& algorithmId = "1");

private:
    boost::optional<algo::CipherCommand> getCipherCommand(const std::string& cipherCommand);

    std::unique_ptr<algo::IAlgorithm> createAlgorithm(const std::string& algorithmId);
};

} // namespace src

#endif // SRC_DISPATCHER_HPP
