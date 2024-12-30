if(CMAKE_VERSION VERSION_GREATER 3.9)
    option(LW_USE_LTO "Use linked time optimization if available in release builds" ON)

    if(LW_USE_LTO)
        include(CheckIPOSupported)
        check_ipo_supported(RESULT supported OUTPUT error)

        if(supported)
            message(STATUS "IPO / LTO enabled")
            set(LTO_ON TRUE)
        else()
            message(WARNING "IPO / LTO not available")
        endif()
    endif()
endif()

function(add_lto TARGET)
    if(LTO_ON)
       #set_property(TARGET ${TARGET} PROPERTY INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)
    endif()
endfunction()