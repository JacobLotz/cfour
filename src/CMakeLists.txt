list(APPEND SOURCES
  grid.cpp
  complayer.cpp
  humplayer.cpp
)

list(APPEND HEADERS
  grid.hpp
  complayer.hpp
  humplayer.hpp
)

# Allegedly adding the headers is helpful for IDEs.
add_library(cfour ${SOURCES} ${HEADERS})
target_compile_definitions(cfour PUBLIC "${_cfour_compile_defs}")
target_compile_options(cfour PUBLIC "${_cfour_compile_opts}")
target_include_directories(cfour SYSTEM PUBLIC "${_cfour_include_dirs}")
target_link_libraries(cfour PUBLIC "${_cfour_libraries}")
