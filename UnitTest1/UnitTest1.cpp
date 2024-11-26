#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include <cmath>
#include "C:\Users\user\Desktop\test\MainF\MainF\MainF.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab3
{
    TEST_CLASS(UnitTestLab3)
    {
    public:

        TEST_METHOD(TestValidInputs)
        {
            Assert::AreEqual(139.0, calculateY(-2, 5), 1e-9);
            Assert::AreEqual(0.0, calculateY(5, 5), 1e-9);
        }

        TEST_METHOD(TestInvalidN)
        {

            try {
                calculateY(1, 4);
                Assert::Fail(L"Виняток не був згенерований для некоректного n");
            }
            catch (const std::invalid_argument& e) {
                Assert::AreEqual("Параметр n повинен бути більше 4.", std::string(e.what()).c_str());
            }
        }

        TEST_METHOD(TestExtremeXValues)
        {

            Assert::IsTrue(calculateY(100, 5) > 0);
            Assert::IsTrue(calculateY(-100, 5) > 0);
        }
    };
}