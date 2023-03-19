cmake_minimum_required(VERSION 3.2)
project(final-project)
add_subdirectory(googletest)

#set(CMAKE_BUILD_TYPE Debug)


include_directories(
  ./googletest/googletest/include/
  ./googletest/googlemock/include/
)

# add_executable(playerTests
#     ./Player-Class/Player.cpp
#     ./Player-Class/Melee.cpp
#     ./Player-Class/Range.cpp
#     ./Player-Class/Mage.cpp
#     ./tests/tests.cpp
# ) 

add_executable(runGame
    ./src/main.cpp
    ./Inventory-Class/Inventory.cpp
    ./Inventory-Class/InventoryActions.cpp
    ./Player-Class/Player.cpp
    ./Player-Class/Melee.cpp
    ./Player-Class/Range.cpp
    ./Player-Class/Mage.cpp
    ./Enemy-Class/Enemy.cpp
    ./Enemy-Class/regularEnemy.cpp
    ./Enemy-Class/bossEnemy.cpp
    ./World-Class/World.cpp
) 

add_executable(inventoryTests
    ./tests/inventoryTests.cpp
)

add_executable(worldTests
    ./World-Class/World.cpp
    ./tests/worldTests.cpp
) 

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Enemy-Class)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Player-Class)

target_link_libraries(inventoryTests gtest gtest_main)
target_link_libraries(worldTests gtest gtest_main)

# OLD CMAKELISTS
#===============================================
# add_executable(mainTests
#     ./src/main.cpp
#     ./tests/mainTests.cpp
# ) 

# add_executable(enemyTests
#     ./src/main.cpp
#     ./tests/mainTests.cpp
# ) 

#target_link_libraries(playerTests gtest gtest_main)

#find all source files

# # find all source files
# file(GLOB ENEMY_SOURCES 
#     "Enemy-Class/*.cpp"
# )

# file(GLOB PLAYER_SOURCES 
#     "Player-Class/*.cpp"
# )

# # find all header files
# file(GLOB ENEMY_HEADERS 
#     "Enemy-Class/*.h"
# )

# file(GLOB PLAYER_HEADERS 
#     "Player-Class/*.h"
# )

# add_executable(runGame 
#     ${ENEMY_SOURCES}
#     ${PLAYER_SOURCES} 
#     ${ENEMY_HEADERS} 
#     ${PLAYER_HEADERS}
#     src/main.cpp
#     ./src/Inventory.cpp
#     ./src/InventoryActions.cpp
# )

# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Enemy-Class)
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Player-Class)

# #target_link_libraries(playerTests gtest gtest_main)
