add_executable_stm32f4(fastusbasp isp.h main.cpp)

target_include_directories(fastusbasp PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/../lib/)
target_link_libraries(fastusbasp -L${CMAKE_CURRENT_SOURCE_DIR}/../lib/ stm32f4cpp)
