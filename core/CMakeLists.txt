cmake_minimum_required (VERSION 2.6)

set(TEST_CORE_TARGET_NAME "test_core")

set(GENERATED_INCLUDE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/include")
set(GENERATED_VERSION_FILE "${GENERATED_INCLUDE_DIRECTORY}/version.h")

configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/version.h.in
	${GENERATED_VERSION_FILE}
)

set(LIB_SRC_FILES
	"${CMAKE_SOURCE_DIR}/external/cpp_sqlite/src/CppSQLite3.cpp"
	"${CMAKE_SOURCE_DIR}/external/cpp_sqlite/src/sqlite3.c"
	src/DatabaseStorage.cpp
	src/DefinitionKind.cpp
	src/EdgeKind.cpp
	src/ElementComponentKind.cpp
	src/LocationKind.cpp
	src/NameHierarchy.cpp
	src/NodeKind.cpp
	src/ReferenceKind.cpp
	src/SourcetrailDBWriter.cpp
	src/SymbolKind.cpp
	src/utility.cpp
)

set(LIB_HDR_FILES
	"${CMAKE_SOURCE_DIR}/external/json/include/json.hpp"
	"${CMAKE_SOURCE_DIR}/external/cpp_sqlite/include/CppSQLite3.h"
	"${CMAKE_SOURCE_DIR}/external/cpp_sqlite/include/sqlite3.h"
	include/DatabaseStorage.h
	include/DefinitionKind.h
	include/EdgeKind.h
	include/ElementComponentKind.h
	include/LocationKind.h
	include/NameHierarchy.h
	include/NodeKind.h
	include/ReferenceKind.h
	include/SourceRange.h
	include/SourcetrailDBWriter.h
	include/SourcetrailException.h
	include/StorageEdge.h
	include/StorageElementComponent.h
	include/StorageError.h
	include/StorageFile.h
	include/StorageLocalSymbol.h
	include/StorageNode.h
	include/StorageOccurrence.h
	include/StorageSourceLocation.h
	include/StorageSymbol.h
	include/SymbolKind.h
	include/utility.h
	${GENERATED_VERSION_FILE}
)

add_library(${LIB_CORE_TARGET_NAME} STATIC ${LIB_SRC_FILES} ${LIB_HDR_FILES})

set_target_properties(${LIB_CORE_TARGET_NAME} PROPERTIES OUTPUT_NAME "sourcetraildb")

target_include_directories(${LIB_CORE_TARGET_NAME} PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/include"
	"${CMAKE_SOURCE_DIR}/external/json/include"
	"${CMAKE_SOURCE_DIR}/external/cpp_sqlite/include"
	"${GENERATED_INCLUDE_DIRECTORY}"
)


set(TEST_SRC_FILES
	test/test.cpp
)

add_executable(${TEST_CORE_TARGET_NAME} ${TEST_SRC_FILES})

target_include_directories(${TEST_CORE_TARGET_NAME} PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/include"
	"${CMAKE_SOURCE_DIR}/external/catch/include"
	"${CMAKE_SOURCE_DIR}/external/json/include"
	"${CMAKE_SOURCE_DIR}/external/cpp_sqlite/include"
	"${GENERATED_INCLUDE_DIRECTORY}"
)

target_link_libraries(${TEST_CORE_TARGET_NAME} ${LIB_CORE_TARGET_NAME} ${CMAKE_DL_LIBS})
