#include "Field.h"
#include <gtest/gtest.h>
#include <string>

using namespace std;

TEST(Field, ShouldReturnColumn) {
    Field field = Field(2, 3);
    EXPECT_EQ(3, field.getCol());
}
