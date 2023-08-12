cmake_minimum_required (VERSION 3.26)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project (bulk_thr VERSION ${PROJECT_VERSION})

set (CMAKE_CXX_STANDARD 20) 

set (BOOST_ROOT "C:/boost") # directory boost

add_executable(bulk_thr src/main.cpp
src/controlsData.cpp
src/models/dataTime.cpp
src/models/procesData.cpp
src/models/writeFile.cpp
src/models/outConsole.cpp
)

target_include_directories(bulk_thr
    PRIVATE
    includes/
)

find_package (Boost REQUIRED COMPONENTS program_options REQUIRED)
if (Boost_FOUND)
    include_directories (SYSTEM ${Boost_INCLUDE_DIR})    
    target_link_libraries (bulk_thr ${Boost_LIBRARIES}) 
endif ()

install(TARGETS bulk_thr RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()