#include "gmock/gmock.h"
#include "RetweetCollection.h"

using namespace testing;

class ARetweetCollection: public Test {
  public:
    RetweetCollection collection;
};

TEST_F(ARetweetCollection, IsEmptyWhenCreated) {
  ASSERT_TRUE(collection.isEmpty());
}
