#include "gtest/gtest.h"
#include "lifx.h"

TEST(lifxDevieIdTest, stringify)
{
  char buff1[64];
  char buff2[64];
  lifxDeviceId_t id1;
  lifxDeviceId_t id2;

  strcpy(buff1, "lifx_id://mac/01:02:03:04:05:06");
  EXPECT_EQ(0, lifxDeviceId_FromString(&id1, buff1));
  EXPECT_EQ(0, lifxDeviceId_ToString(&id1, buff2, sizeof(buff2)));
  EXPECT_STREQ(buff1, buff2);
  EXPECT_EQ(0, lifxDeviceId_FromString(&id2, buff2));
  EXPECT_EQ(0, lifxDeviceId_Compare(&id1, &id2));
}
