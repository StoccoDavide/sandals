set(OPTIMIST_REQUIRED_VERSION 0.0.0)
cmake_policy(SET CMP0135 NEW)

list(APPEND CMAKE_PATH_PREFIX "${SANDALS_THIRD_PARTY_DIR}")
find_package(
  Optimist
  ${OPTIMIST_REQUIRED_VERSION}
  NO_MODULE
  QUIET
)

if(NOT TARGET Optimist::Optimist)
  message(STATUS "Sandals: Did not find Optimist ${OPTIMIST_REQUIRED_VERSION} installed, downloading to "
    "${SANDALS_THIRD_PARTY_DIR}")
  include(FetchContent)

  set(FETCHCONTENT_BASE_DIR "${SANDALS_THIRD_PARTY_DIR}")
  fetchcontent_declare(
    Optimist
    # URL "https://github.com/StoccoDavide/Optimist/archive/refs/tags/${OPTIMIST_REQUIRED_VERSION}.tar.gz"
    GIT_REPOSITORY "https://github.com/StoccoDavide/Optimist"
    GIT_TAG        main
  )

  fetchcontent_makeavailable(Optimist)
else()
  get_target_property(OPTIMIST_INCLUDE_DIRS
    Optimist::Optimist
    INTERFACE_INCLUDE_DIRECTORIES
  )
  message(STATUS "Sandals: Found Optimist installed in ${OPTIMIST_INCLUDE_DIRS}")
endif()
