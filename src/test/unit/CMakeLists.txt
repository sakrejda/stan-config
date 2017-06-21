enable_testing()

# Finding stuff...
file(GLOB TESTS_CPP *test.cpp)

# Includes
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_BINARY_DIR}/src)
include_directories(${GTEST_INCLUDE_DIR})

# Build:

foreach(TEST_CPP IN ITEMS ${TESTS_CPP})
  get_filename_component(TEST_NAME ${TEST_CPP} NAME_WE)
  add_executable(${TEST_NAME} ${TEST_CPP} )
  set_target_properties(${TEST_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/test/unit)
  #  add_dependencies(${TEST_NAME} target-names-here-if-needed)
  target_link_libraries(${TEST_NAME} ${GTEST_LIBRARY} )
  add_test(${TEST_NAME} ${PROJECT_BINARY_DIR}/test/unit/${TEST_NAME})
endforeach(TEST_CPP)




