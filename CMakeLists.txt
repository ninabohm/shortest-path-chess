cmake_minimum_required(VERSION 3.14)
project(main)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        Main
        main.cpp
        Color.h

        Node.cpp
        Edge.cpp
        Graph.cpp
        InputHelper.cpp
        Field.cpp
        Pawn.cpp
        Chessboard.cpp
        Piece.cpp
        King.cpp
        Knight.cpp

        PawnTest.cpp
        KnightTest.cpp
        ChessboardTest.cpp
        FieldTest.cpp
        GraphTest.cpp
        NodeTest.cpp
        EdgeTest.cpp
        InputHelperTest.cpp
)
target_link_libraries(
        Main
        GTest::gtest_main
)

include(GoogleTest)
#gtest_discover_tests(Main)