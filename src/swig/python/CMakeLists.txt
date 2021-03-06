
add_subdirectory(modules)
add_subdirectory(scripts)

INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_PATH})

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/src/swig/)


SET(CMAKE_SWIG_OUTDIR ${CMAKE_CURRENT_BINARY_DIR})
SET(CMAKE_SWIG_FLAGS "")

SET_SOURCE_FILES_PROPERTIES(marsyas.i PROPERTIES CPLUSPLUS ON)
SET_SOURCE_FILES_PROPERTIES(marsyas.i PROPERTIES SWIG_FLAGS "-includeall")
SET_SOURCE_FILES_PROPERTIES(../realvec.i PROPERTIES CPLUSPLUS ON)
SWIG_ADD_MODULE(marsyas python marsyas.i ../realvec.i)

SWIG_LINK_LIBRARIES(marsyas marsyas ${OS_LIBS})

if(PYTHON_LIBRARIES)
  target_link_libraries(_marsyas optimized ${PYTHON_LIBRARIES})
endif()

if(PYTHON_LIBRARIES_DEBUG)
  target_link_libraries(_marsyas debug ${PYTHON_LIBRARIES_DEBUG})
endif()

install(TARGETS _marsyas LIBRARY DESTINATION ${PYTHON_MODULES_DIR})

install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/marsyas.py
  DESTINATION ${PYTHON_MODULES_DIR}
)
