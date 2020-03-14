include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

#add_subdirectory(include)
add_subdirectory(extension)
if (REGRESS_CHECKS)
  add_subdirectory(test)
endif (REGRESS_CHECKS)
