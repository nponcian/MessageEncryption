#include <Controller.hpp>
#include <Common/Logger.hpp>

namespace
{

src::common::Logger logger("main");

} // namespace

int main(int argc, char** argv)
{
    logger.print("Start of execution\n");

    if (argc == 4)      src::Controller().handle(argv[1], argv[2], argv[3]);
    else if (argc == 5) src::Controller().handle(argv[1], argv[2], argv[3], argv[4]);
    else                src::Controller().handle("", "", "", "");

    logger.print("End of execution\n");
    return 0;
}
