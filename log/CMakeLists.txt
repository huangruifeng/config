include_directories(${PROJECT_SOURCE_DIR}/threadPool)
message(${PROJECT_SOURCE_DIR}/threadPool)
list(APPEND logsrc
     ${LOG_SOURCE_DIRECTORY}/log.h
     ${LOG_SOURCE_DIRECTORY}/log.cpp
    )

add_library(Log ${logsrc})
target_link_libraries(Log threadpool)