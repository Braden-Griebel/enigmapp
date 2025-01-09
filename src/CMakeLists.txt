

add_subdirectory(enigma)
add_executable(enigmapp enigmapp.cpp)

target_link_libraries(enigmapp CLI11::CLI11)
