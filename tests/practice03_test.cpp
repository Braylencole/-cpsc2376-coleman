#include "pch.h" 
#include "CppUnitTest.h"
#include "../../practice/practice03/main.cpp"  

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Practice03Test
{
    TEST_CLASS(MathUtilsTests)
    {
    public:
        // Test sumRange
        TEST_METHOD(SumRange_Standard)
        {
            Assert::AreEqual(15, MathUtils::sumRange(1, 5)); 
        }

        TEST_METHOD(SumRange_SingleValue)
        {
            Assert::AreEqual(3, MathUtils::sumRange(3, 3)); 
        }

        TEST_METHOD(SumRange_NegativeValues)
        {
            Assert::AreEqual(3, MathUtils::sumRange(-2, 3)); 
        }

        // Test containsNegative
        TEST_METHOD(ContainsNegative_HasNegative)
        {
            std::vector<int> values = { 3, -1, 5, 7 };
            Assert::IsTrue(MathUtils::containsNegative(values));
        }

        TEST_METHOD(ContainsNegative_NoNegative)
        {
            std::vector<int> values = { 3, 1, 5, 7 };
            Assert::IsFalse(MathUtils::containsNegative(values));
        }

        TEST_METHOD(ContainsNegative_EmptyList)
        {
            std::vector<int> values = {};
            Assert::IsFalse(MathUtils::containsNegative(values));
        }

        // Test findMax
        TEST_METHOD(FindMax_Standard)
        {
            std::vector<int> values = { 3, -1, 5, 7 };
            Assert::AreEqual(7, MathUtils::findMax(values));
        }

        TEST_METHOD(FindMax_AllEqual)
        {
            std::vector<int> values = { 2, 2, 2, 2 };
            Assert::AreEqual(2, MathUtils::findMax(values));
        }

        TEST_METHOD(FindMax_EmptyList)
        {
            std::vector<int> values = {};
            try {
                MathUtils::findMax(values); 
                Assert::Fail(L"Expected an exception, but none was thrown.");
            }
            catch (const std::runtime_error& e) {
                Assert::AreEqual("Vector is empty", e.what()); 
            }
        }

        TEST_METHOD(FindMax_SingleElement)
        {
            std::vector<int> values = { 42 };
            Assert::AreEqual(42, MathUtils::findMax(values));
        }
    };
}
