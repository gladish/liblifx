#include "gtest/gtest.h"
#include "lifx.h"

TEST(lifxBuffer, seekTestOk)
{
  lifxBuffer_t buff;
  EXPECT_EQ(0, lifxBuffer_Init(&buff, 64));
  EXPECT_EQ(0, lifxBuffer_Seek(&buff, 0, kLifxBufferWhenceSet));
  EXPECT_EQ(0, lifxBuffer_Seek(&buff, 63, kLifxBufferWhenceSet));
  EXPECT_EQ(0, lifxBuffer_Seek(&buff, 10, kLifxBufferWhenceSet));
  EXPECT_EQ(0, lifxBuffer_Seek(&buff, 53, kLifxBufferWhenceSet));
  lifxBuffer_Destroy(&buff);
}

TEST(lifxBuffer, seekTestFail)
{
  lifxBuffer_t buff;
  EXPECT_EQ(0, lifxBuffer_Init(&buff, 64));
  EXPECT_EQ(EINVAL, lifxBuffer_Seek(&buff, -1, kLifxBufferWhenceSet));
  EXPECT_EQ(EINVAL, lifxBuffer_Seek(&buff, 64, kLifxBufferWhenceSet));
  EXPECT_EQ(EINVAL, lifxBuffer_Seek(&buff, -64, kLifxBufferWhenceEnd));
  EXPECT_EQ(0, lifxBuffer_Seek(&buff, 30, kLifxBufferWhenceSet));
  EXPECT_EQ(EINVAL, lifxBuffer_Seek(&buff, -31, kLifxBufferWhenceCurrent));
  EXPECT_EQ(EINVAL, lifxBuffer_Seek(&buff, 35, kLifxBufferWhenceCurrent));
  lifxBuffer_Destroy(&buff);
}
