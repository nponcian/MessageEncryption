#include <Algorithm/AddOneCharacter.hpp>

#include <string>

#include <gtest/gtest.h>

#include <Common/CipherCommand.hpp>

using namespace src::algo;
using namespace src::common;

struct AddOneCharacterTest : public ::testing::Test
{
    AddOneCharacterTest(){}
    virtual ~AddOneCharacterTest(){}

    virtual void SetUp(){}
    virtual void TearDown(){}

    AddOneCharacter impl_;
};

TEST_F(AddOneCharacterTest, CheckKeycodeDelimiterAndNextCharFromKeycode)
{
    std::string keycode = "aeiou";

    std::string message = "aeo";

    // Delimiter for keycode characters is "1"
    // Next characters of "aeo" in keycode are "eiu"
    std::string encrypted = "1e1i1u";

    auto result = impl_.process(
                    CipherCommand::Encrypt,
                    message,
                    keycode);

    EXPECT_EQ(result, encrypted);
}

TEST_F(AddOneCharacterTest, CheckNonKeycodeDelimiterAndNextCharFromAscii)
{
    std::string keycode = "aeiou";

    std::string message = "bfj";

    // Delimiter for non-keycode characters is "I"
    // Next characters of "bfj" in ASCII are "cgk"
    std::string encrypted = "IcIgIk";

    auto result = impl_.process(
                    CipherCommand::Encrypt,
                    message,
                    keycode);

    EXPECT_EQ(result, encrypted);
}

TEST_F(AddOneCharacterTest, CheckKeycodeAndNonKeycodeCombinationDelimiterAndNextChar)
{
    std::string keycode = "aeiou";

    std::string message = "abefoj";
    std::string encrypted = "1eIc1iIg1uIk";

    auto result = impl_.process(
                    CipherCommand::Encrypt,
                    message,
                    keycode);

    EXPECT_EQ(result, encrypted);
}

TEST_F(AddOneCharacterTest, AddNextCharacterFromAsciiIfNotInKeycode)
{
    std::string message = "aA1bB2cC3";
    std::string encrypted = "IbIBI2IcICI3IdIDI4";
    std::string emptyCode = "";

    auto result = impl_.process(
                    CipherCommand::Encrypt,
                    message,
                    emptyCode);

    EXPECT_EQ(result, encrypted);
}
