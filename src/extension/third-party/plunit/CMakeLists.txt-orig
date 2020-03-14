set(SOURCES
  plunit.c
)

# Add test source code in Debug builds
if (CMAKE_BUILD_TYPE MATCHES Debug)
  set(TS_DEBUG 1)
  set(DEBUG 1)
endif (CMAKE_BUILD_TYPE MATCHES Debug)

set(PLUNIT_LIBRARY_NAME ${PROJECT_NAME}-plunit)

include(build-defs.cmake)

if (CMAKE_BUILD_TYPE MATCHES Debug)
add_library(${PLUNIT_LIBRARY_NAME} STATIC ${SOURCES} $<TARGET_OBJECTS:${PLUNIT_TESTS_LIB_NAME}>)
else ()
add_library(${PLUNIT_LIBRARY_NAME} STATIC ${SOURCES})
endif ()

set_target_properties(${PLUNIT_LIBRARY_NAME} PROPERTIES
  OUTPUT_NAME ${PLUNIT_LIBRARY_NAME}-${PROJECT_VERSION_MOD}
  PREFIX "")

target_compile_definitions(${PLUNIT_LIBRARY_NAME} PUBLIC TS_PLUNIT)
target_compile_definitions(${PLUNIT_LIBRARY_NAME} PUBLIC TS_SUBMODULE)

#install(
#  TARGETS ${PLUNIT_LIBRARY_NAME}
#  DESTINATION ${PG_PKGLIBDIR})

# if (WIN32)
#   target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-${PROJECT_VERSION_MOD}.lib)
# endif(WIN32)

