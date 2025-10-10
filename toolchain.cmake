# 可传参：-DTOOLCHAIN_ROOT=/opt/gcc-13
if(NOT DEFINED TOOLCHAIN_ROOT)
    # 默认用系统 PATH 里的 gcc/g++
    find_program(GCC_EXEC gcc)
    find_program(GXX_EXEC g++)
else()
    set(GCC_EXEC ${TOOLCHAIN_ROOT}/bin/gcc)
    set(GXX_EXEC ${TOOLCHAIN_ROOT}/bin/g++)
endif()

set(CMAKE_C_COMPILER   ${GCC_EXEC} CACHE FILEPATH "C compiler")
set(CMAKE_CXX_COMPILER ${GXX_EXEC} CACHE FILEPATH "C++ compiler")
