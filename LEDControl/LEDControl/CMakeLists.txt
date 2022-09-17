add_executable(ServoControl
        main.c
)

target_link_libraries(ServoControl pico_stdlib freertos hardware_gpio hardware_adc hardware_pwm)
pico_add_extra_outputs(ServoControl)
