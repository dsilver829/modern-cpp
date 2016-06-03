#include "gmock/gmock.h"
#include "Tweet.h"
#include <string>

using namespace ::testing;

TEST(ATweet, RequiresUserToStartWithAtSign) {
	std::string invalidUser("notStartingWith@");
	ASSERT_ANY_THROW(Tweet tweet("msg", invalidUser));
}
