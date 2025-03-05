set(TARGET_NAME atmega328p-HAL)

add_library(${TARGET_NAME})

target_sources(${TARGET_NAME} PUBLIC
    src/gpio.c
)

target_include_directories(${TARGET_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc
)

target_link_libraries(${TARGET_NAME} PUBLIC

)