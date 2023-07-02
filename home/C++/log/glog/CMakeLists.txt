cmake_minimum_required (VERSION 3.0)
project ("GLogTest")
set(ProjectName "GLogTest")
function(SUBDIRLIST filter curdir)
	IF(filter)
		FILE(GLOB SRC ${curdir}/*.h ${curdir}/*.cpp ${curdir}/*.qml ${curdir}/*.c)
		source_group(${filter} FILES ${SRC})
	ENDIF()
    FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
	FOREACH(child ${children})
	IF(IS_DIRECTORY ${curdir}/${child})
		FILE(GLOB SRC ${curdir}/${child}/*.h ${curdir}/${child}/*.cpp ${curdir}/${child}/*.c ${curdir}/${child}/*.qrc ${curdir}/${child}/*.ui ${curdir}/${child}/*.ts ${curdir}/*.qml)
		source_group(${filter}\\${child} FILES ${SRC})
		SUBDIRLIST(${filter}\\${child} ${curdir}/${child})
	ENDIF()
	ENDFOREACH()
endfunction()


set(LibOutPutDirectory "${CMAKE_CURRENT_SOURCE_DIR}/general/lib/" CACHE PATH "Directory where .exe and .lib files are dumped.")
set(DllOutPutDirectory "${CMAKE_CURRENT_SOURCE_DIR}/general/bin/" CACHE PATH "Directory where .exe and .dll files are dumped.")
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${LibOutPutDirectory}/debug)
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${LibOutPutDirectory}/release)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${DllOutPutDirectory}/debug)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${DllOutPutDirectory}/release)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

FILE(GLOB_RECURSE MAIN_SRC ./*.h ./*.cpp ./*.cc )

SUBDIRLIST("" ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

link_directories(${LibOutPutDirectory}/$<$<CONFIG:Debug>:debug>$<$<CONFIG:Release>:release>)

set(CMAKE_DEBUG_POSTFIX d)

add_executable(${ProjectName} ${MAIN_SRC})


target_link_libraries(${ProjectName} debug glogd optimized glog)