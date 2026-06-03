set(header_path "${${PROJECT_NAME}_SOURCE_DIR}/include")
set(header_circle ${header_path}/circle.h)
set(header_tasks ${header_path}/tasks.h)

set(src_files circle.cpp tasks.cpp)

add_library(${PROJECT_NAME} STATIC
    ${src_files}
)

target_include_directories(${PROJECT_NAME}
    PUBLIC 
        ${CMAKE_CURRENT_BINARY_DIR}
        ${${PROJECT_NAME}_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
    pthread
)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
    add_executable(${PROJECT_NAME}.info main.cpp)
    target_include_directories(${PROJECT_NAME}.info
        PUBLIC 
            ${CMAKE_CURRENT_BINARY_DIR}
            ${${PROJECT_NAME}_SOURCE_DIR}/include
    )
    target_link_libraries(${PROJECT_NAME}.info
        ${PROJECT_NAME}
    )
endif()
