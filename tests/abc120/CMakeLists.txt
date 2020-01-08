add_executable(TestDecayedBridges test_decayed_bridges.cc)
target_link_libraries(TestDecayedBridges DecayedBridges gtest_main)

include_directories(${PROJECT_SOURCE_DIR}/src)
include(GoogleTest)

gtest_discover_tests(TestDecayedBridges)
