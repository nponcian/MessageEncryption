#ifndef SRC_DISPATCHER_HPP
#define SRC_DISPATCHER_HPP

#include <memory>

namespace src
{
namespace algo
{

class IAlgorithm;

} // namespace algo

class Controller
{
public:
    Controller();

    void handle(
        const std::string& cipherCommandText,
        const std::string& fileToCipher,
        const std::string& keyCode,
        const std::string& algorithmId = "1");

private:
    std::unique_ptr<algo::IAlgorithm> createAlgorithm(const std::string& algorithmId);
};

} // namespace src

#endif // SRC_DISPATCHER_HPP
