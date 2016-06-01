#include "gmock/gmock.h"
#include "RetweetCollection.h"

#include <memory>

using namespace testing;

class ARetweetCollection: public Test {
  public:
    RetweetCollection collection;
};

class ARetweetCollectionWithOneTweet: public Test {
  public:
    RetweetCollection collection;
		std::shared_ptr<Tweet> tweet;
		void SetUp() override {
			tweet = std::shared_ptr<Tweet>(new Tweet("msg", "@user"));
			collection.add(*tweet);
		}
};

MATCHER_P(HasSize, expected, "") {
	return arg.size() == expected && arg.isEmpty() == (0 == expected);
}

TEST_F(ARetweetCollection, IsEmptyWhenCreated) {
  ASSERT_TRUE(collection.isEmpty());
}

TEST_F(ARetweetCollection, HasSizeZeroWhenCreated) {
  ASSERT_THAT(collection.size(), Eq(0));
}

TEST_F(ARetweetCollectionWithOneTweet, IsNoLongerEmptyAfterTweetAdded) {
  ASSERT_FALSE(collection.isEmpty());
}

TEST_F(ARetweetCollectionWithOneTweet, HasSizeOfOneAfterTweetAdded) {
  ASSERT_THAT(collection.size(), Eq(1u));
}

TEST_F(ARetweetCollectionWithOneTweet, DecreasesSizeAfterRemovingTweet) {
	collection.remove(Tweet("msg", "@user"));
	ASSERT_THAT(collection, HasSize(0u));
}

TEST_F(ARetweetCollectionWithOneTweet, IgnoresDuplicateTweetsAdded) {
	Tweet duplicate(*tweet);
	collection.add(duplicate);

	ASSERT_THAT(collection.size(), Eq(1u));
}
