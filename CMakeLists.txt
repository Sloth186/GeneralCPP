cmake_minimum_required(VERSION 3.30)
project(General)

set(CMAKE_CXX_STANDARD 20)

add_executable(BlackjackVsComp
        Blackjack/StandardDeck.cpp
        Blackjack/StandardDeck.h
        Blackjack/Card.cpp
        Blackjack/Card.h)

add_executable(BlackjackPvP
        Blackjack/StandardDeck.cpp
        Blackjack/StandardDeck.h
        Blackjack/Card.cpp
        Blackjack/Card.h)

add_executable(PigGamePart1VsComp
        PigGamePart1/Die.cpp
        PigGamePart1/Die.h
        PigGamePart1/playervscomputer.cpp
)

add_executable(PigGamePart1VsPlayer
        PigGamePart1/Die.cpp
        PigGamePart1/Die.h
        PigGamePart1/pvp.cpp)
add_executable(StackBaseConversion StackBaseConversion/Stack.cpp)
add_executable(QueueTask QueueTask/queueTask.cpp)
add_executable(PalindromesCheck PalindromesCheck/palindromesCheck.cpp)
add_executable(Lab7UnorderedSet Lab7UnorderedSet/Lab7.cpp)
