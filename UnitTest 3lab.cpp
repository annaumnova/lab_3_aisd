#include "pch.h"
#include "CppUnitTest.h"
#include"../כנ 3 אטסה גאנ1/Binary_tree_search.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3lab
{
	TEST_CLASS(UnitTest3lab)
	{
	public:
		
		TEST_METHOD(Test_contains) 
		{
			BinaryTreeSearch tree;
			tree.insert(2);
			tree.insert(6);
			tree.insert(8);

			Assert::IsTrue(tree.contains(2)==1);
			Assert::IsTrue(tree.contains(6)==1);
			Assert::IsTrue(tree.contains(8)==1);
			Assert::IsTrue(tree.contains(1)==0);
		}
		TEST_METHOD(Test_remove)
		{
			BinaryTreeSearch tree;
			tree.insert(2);
			tree.insert(6);
			tree.insert(8);

			Assert::IsTrue(tree.contains(2) == 1);
			Assert::IsTrue(tree.contains(6) == 1);
			Assert::IsTrue(tree.contains(8) == 1);
			Assert::IsTrue(tree.contains(1) == 0);

			tree.remove(8);
			Assert::IsTrue(tree.contains(2) == 1);
			Assert::IsTrue(tree.contains(6) == 1);
			Assert::IsTrue(tree.contains(8) == 0);
			Assert::IsTrue(tree.contains(1) == 0);

			tree.remove(1);
			Assert::IsTrue(tree.contains(2) == 1);
			Assert::IsTrue(tree.contains(6) == 1);
			Assert::IsTrue(tree.contains(8) == 0);
			Assert::IsTrue(tree.contains(1) == 0);

			tree.remove(6);
			Assert::IsTrue(tree.contains(2) == 1);
			Assert::IsTrue(tree.contains(6) == 0);
			Assert::IsTrue(tree.contains(8) == 0);
			Assert::IsTrue(tree.contains(1) == 0);
			
			tree.remove(2);
			Assert::IsTrue(tree.contains(2) == 0);
			Assert::IsTrue(tree.contains(6) == 0);
			Assert::IsTrue(tree.contains(8) == 0);
			Assert::IsTrue(tree.contains(1) == 0);
		}
		TEST_METHOD(Test_insert)
		{
			BinaryTreeSearch tree;
			tree.insert(2);
			tree.insert(6);
			tree.insert(8);

		}
	};
}
