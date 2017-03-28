#include <gtest/gtest.h>
#include "game.h"

class GoBangTest : public ::testing::Test
{
public:
    virtual void SetUp() {}
    virtual void TearDown() {}

private:

};

TEST_F(GoBangTest, testcase1)
{
    //Game game;
    //game.Run();
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
