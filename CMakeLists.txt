cmake_minimum_required(VERSION 3.24)
project(DataStructExp)

set(CMAKE_CXX_STANDARD 98)


add_executable(DLinkedListTest 1_DLinkedList/DLinkedListTest.cpp 1_DLinkedList/DLinkedList.h)
add_executable(QueueTest 2_AQueue&LStack/QueueTest.cpp 2_AQueue&LStack/AQueue.h)
add_executable(StackTest_1 2_AQueue&LStack/StackTest_1.cpp 2_AQueue&LStack/LStack.h)
add_executable(StackTest_2 2_AQueue&LStack/StackTest_2.cpp 2_AQueue&LStack/LStack.h)
add_executable(HTree 3_HTree/HTree.cpp)
add_executable(AND 4_Test/AND.cpp 4_Test/DLinkedList.h)
add_executable(Reverse 4_Test/Reverse.cpp 4_Test/DLinkedList.h)
add_executable(isSearchTree 4_Test/isSearchTree.cpp)
add_executable(AQueueTest 4_Test/AQueueTest.cpp 4_Test/AQueue.h)