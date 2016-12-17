#include <unity.h>
#include <Welford.h>

#ifdef UNIT_TEST
void test_uniform_distribution(void) {
  Welford<float> accum = Welford<float>{};
  double truevar = 0;
  for(int i = 0; i <= 100; i++) {
    accum.add_value(float(i));
    truevar += (i - 50.0) * (i - 50.0);
  }
  TEST_ASSERT_FLOAT_WITHIN(1e-3, accum.mean(), 50.0); // = 50
  TEST_ASSERT_FLOAT_WITHIN(1e-3, accum.var(), truevar / (100.0)); // = 50
}

int main(int argc, char** argv) {
//int main() {
  //a = 1;
  UNITY_BEGIN();
  RUN_TEST(test_uniform_distribution);
  UNITY_END();
  return 0;
}
#endif
